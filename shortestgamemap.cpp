#include<vector>
#include<queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> check(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = true;
    dis[0][0] = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if(0 <= a && a < n && 0 <= b && b < m) {
                if(check[a][b]) continue;
                if(!maps[a][b]) continue;
                q.push(make_pair(a, b));
                check[a][b] = true;
                dis[a][b] = dis[x][y] + 1;
            }
        }
    }
    
    if(dis[n-1][m-1])
        answer = dis[n-1][m-1];
    else
        answer = -1;
    
    return answer;
}