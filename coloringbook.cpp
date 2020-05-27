#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    bool check[m][n];
    memset(check, false, sizeof(check));
    int tmp = 0;
    
    for(int x=0; x<m; x++) {
        for(int y=0; y<n; y++) {
            if(tmp >= max_size_of_one_area)
                max_size_of_one_area = tmp;
            
            if(picture[x][y]>0 && check[x][y]==false) {
                queue<pair<int, int>> q;
                number_of_area += 1;
                q.push(make_pair(x,y));
                check[x][y] = true;
                tmp = 1;
                while(!q.empty()) {
                    int ax = q.front().first;
                    int ay = q.front().second;
                    q.pop();
                    for(int i=0; i<4; i++) {
                        int nx = ax + dx[i];
                        int ny = ay + dy[i];
                        if(0<= nx && nx < m && 0<= ny && ny < n) {
                            if(check[nx][ny])
                                continue;
                            else {
                                if(picture[nx][ny] == picture[ax][ay]) {
                                    q.push(make_pair(nx, ny));
                                    check[nx][ny] = true;
                                    tmp += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}