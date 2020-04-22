#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    sort(dist.begin(), dist.end(), [](int a, int b) { return a > b; }); // 이렇게 사용할 수 있는거 신기하다.
    int fr_num; // friend_number 선별할 친구의 숫자.

    // 시작점을 바꿔가면서 외벽 점검.
    for(int i=0; i<n; i++) {
        vector<int> selected;
        fr_num = 1;
        int dsize = dist.size();
        bool cover = false;
        // 취약점을 모두 점검하지 못했고 더이상 친구를 투입할 수 없을 때까지
        while(fr_num <= dsize && !cover) {
            cover = true;
		    selected.clear();
            // 가장 긴 거리를 점검할 수 있는 친구를 선발 가능한 인원만큼 선발
            for (int j = 0; j < fr_num; j++)
			    selected.push_back(dist[j]);
        
            do {
                cover = true;
                int wi = 0;
                int si = 0;
                
                int start = weak[wi];
                int end = start + selected[si];
                
                while(1) {
                    // 선발한 친구들로 모든 취약점이 점검이 가능할 경우.
                    if (start <= weak[wi] && weak[wi] <= end) {
                        wi++;
                        // 마지막 취약 지점이라면
                        if (weak.size() <= wi) {
                            cover = true;
                            break;
                        }
                    }
                    // 선발한 친구들로 취약점을 모두 점검할 수 없을 경우.
                    else {
                        si++;
                        // 선발한 친구중 더이상 투입할 사람들이 남아있지 않을 경우.
                        if (fr_num <= si) {
                            cover = false;
                            break;
                        }
                        
                        start = weak[wi];
                        end = start + selected[si];
                    }
                }
            
                if(cover) // 모든 취약점을 커버했을 경우.
                    answer = answer < fr_num ? answer : fr_num;
            // 선발한 친구의 출발 순서를 변경하면서 외벽 점검.
            } while(prev_permutation(selected.begin(), selected.end()));
        
            fr_num++;   // 선발할 친구의 숫자를 늘림.
        }
    
        weak[0] += n;   // 시작점을 다음칸으로 옮김.
        sort(weak.begin(), weak.end());
    }
    
    if(answer == 10) // 정답이 안바뀌었으면 -1 전달.
        answer = -1;
    
    return answer;
}

// https://lameld.github.io/kakao/2020_circular/
// 생각한 방법은 같으나... 구현이 잘 안되어서 보고 거의 외우다시피 공부했습니다.