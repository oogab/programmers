#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int cnt = 0;
    int size = land.size();
    int map[300][300];
    queue<pair<int, int>> q;
    memset(map, -1, sizeof(map));
    
    for(int x=0; x<size; x++) {
        for(int y=0; y<size; y++) {
            if (map[x][y] >= 0)
                continue;
            q.push(make_pair(x, y));
            map[x][y] = cnt;
            while(!q.empty()) {
                int ax = q.front().first;
                int ay = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int nx = ax + dx[i];
                    int ny = ay + dy[i];
                    if(0<=nx && nx<size && 0<=ny && ny<size) {
                        if(map[nx][ny] >= 0) continue;
                        if(abs(land[ax][ay]-land[nx][ny]) > height) continue;
                        q.push(make_pair(nx, ny));
                        map[nx][ny] = map[ax][ay];
                    }
                }
            }
            cnt++;
        }
    }
    
    int p[cnt][cnt];
    bool map_check[size][size];
    
    for(int i=0; i<cnt; i++) {
        for(int j=0; j<cnt; j++) {
            p[i][j] = 100000;
        }
    }
    
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            map_check[i][j] = false;
        }
    }
    
    q.push(make_pair(0, 0));
    map_check[0][0] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<size && 0<=ny && ny<size) {
                if(map_check[nx][ny]) continue;
                if(map[x][y] != map[nx][ny]) {
                    if(abs(land[x][y]-land[nx][ny]) < p[map[x][y]][map[nx][ny]]) {
                        p[map[x][y]][map[nx][ny]] = abs(land[x][y]-land[nx][ny]);
                        p[map[nx][ny]][map[x][y]] = p[map[x][y]][map[nx][ny]];
                    }
                }
                else
                    p[map[x][y]][map[x][y]] = 0;
                map_check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }  
    
    for(int i=0; i<cnt; i++) {
        for(int j=0; j<cnt; j++) {
            if(p[i][j]==100000)
                p[i][j] = 0;
        }
    }
    
    vector<int> last[cnt];
    for(int i=0; i<cnt; i++) {
        for(int j=0; j<cnt; j++) {
            if(i==j) continue;
            if(p[i][j] > 0) {
                last[i].push_back(j);
                last[j].push_back(i);
            }
        }
    }
    
    bool check[cnt];
    int real = 100000;
    for(int i=0; i<cnt; i++) {
        stack<int> s;
        memset(check, false, sizeof(check));
        int tmp = 0;
        s.push(i);
        check[i] = true;
        while(!s.empty()) {
            int now = s.top();
            s.pop();
            for(int j=0; j<last[now].size(); j++) {
                int next = last[now][j];
                if(now == next) continue;
                if(check[next]) continue;
                tmp += p[now][next];
                s.push(next);
                check[next] = true;
            }
        }
        if(tmp < real)
            real = tmp;
    }
    
    answer = real;
    return answer;
}