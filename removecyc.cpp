#include <string>
#include <vector>

using namespace std;

vector<int> nedge[5001];
int discv_num[5001];
int compnt[5001];

int order;

int dfs(int now, bool isRoot) {
    discv_num[now] = ++order;
    int tmp, ret = discv_num[now];
    
    int child = 0;
    
    for(int i=0; i<nedge[now].size(); i++) {
        int next = nedge[now][i];
        if(discv_num[next]) {
            ret = min(ret, discv_num[next]);
            continue;
        }
        child++;
        int prev = dfs(next, false);
        if (!isRoot && prev >= discv_num[now])
            compnt[now]++;
        ret = min(ret, prev);
    }
    if (isRoot)
        compnt[now] = (child >= 2);
 
    return ret;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    
    for(int i=0; i<edges.size(); i++) {
        nedge[edges[i][0]].push_back(edges[i][1]);
        nedge[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=1; i<=edges.size(); i++) {
        if(!discv_num[i])
            dfs(i, true);
    }
    
    for(int i=1; i<=n; i++) {
        if(edges.size()-nedge[i].size()+compnt[i] < n-1) answer += i;
    }
    
    return answer;
}