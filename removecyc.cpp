#include <string>
#include <vector>

using namespace std;

vector<int> nedge[5001];
int discv_num[5001];    // 정점 i가 DFS 탐색에서 발견된 순서
int compnt[5001];       // 정점 i를 제거했을 경우 생기는 component의 수

int order;
// now의 자식 노드가 now를 거치지 않고 도달할 수 있는 정점 중 가장 먼저 dfs함수가 방문한 정점을 반환한다.
int dfs(int now, bool isRoot) { // DFS 탐색을 하면서 'Articulation Point' 탐색. 개념 정리 필요.
    discv_num[now] = ++order;
    int tmp, ret = discv_num[now];
    
    int child = 0;  // now가 루트 노드일 경우를 대비하여 자식 노드의 수를 count.
    
    for(int i=0; i<nedge[now].size(); i++) {
        int next = nedge[now][i];

        /* 
         만약 이미 DFS에서 탐색된 정점이라면 
         현재 정점의 방문순서와 탐색된 정점의 방문 순서중 min값을 찾는다.
         이 방법을 이용해야 
         " now 정점에서 자식 노드들이 정점 now를 거치지 않고 
         정점 now보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점이다. "
         를 찾을 수 있다.
        */

        if(discv_num[next]) {                   // 여기 이 부분에 대한 이해가 좀 부족하다.
            ret = min(ret, discv_num[next]);    
            continue;
        }

        child++;
        int prev = dfs(next, false);

        // 정점 now가 루트노드가 아니고 now 정점에서 now를 지나지 않고 now 이전의 방문번호를 가진 노드로 갈 수 없다면, 단절점이다.
        if (!isRoot && prev >= discv_num[now])
            compnt[now]++;

        ret = min(ret, prev);
    }
    // now가 루트노드이면 자식노드가 2개 이상일 경우 반드시 단절점이다.
    if (isRoot)
        compnt[now] = (child >= 2);
 
    return ret;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    
    for(int i=0; i<edges.size(); i++) {     // 기존의 edges 벡터를 nedge 벡터 인접리스트 형태로 변형한다.
        nedge[edges[i][0]].push_back(edges[i][1]);
        nedge[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=1; i<=edges.size(); i++) {    // 정점 1부터 마지막 정점까지 순차적으로 dfs 탐색을 수행한다.
        if(!discv_num[i])
            dfs(i, true);
    }
    
    for(int i=1; i<=n; i++) {   // 전체 간선의 수 - 해당 정점과 연결된 간선의 수 + 해당 정점을 제거했을 때 생기는 component의 수 = 전체 정점의 수 - 1
        if(edges.size()-nedge[i].size()+compnt[i] < n-1) answer += i;   // 위의 식이 성립할 경우 DFS tree의 필요충분조건이다.
    }
    
    return answer;
}

// https://bowbowbow.tistory.com/3
// https://www.crocus.co.kr/1164
// https://ideone.com/bhTfJu