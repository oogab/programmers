#include <string>
using namespace std;

typedef struct _udrl {
    int u=0;
    int d=0;
    int r=0;
    int l=0;
} UDRL;

bool check(int a, int b) {
    if(a<0 || 10<a || b<0 || 10<b)
        return false;
    else
        return true;
}

// U, D, R, L 순서
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
UDRL map[11][11];

int solution(string dirs) {
	int answer = 0;
    int move = dirs.size();
    
    int x = 5;
    int y = 5;
    
    for(int i=0; i<move; i++) {
        int a, b;
        switch(dirs[i]) {
            case 'U':
                a = x + dx[0];
                b = y + dy[0];
                if(check(a,b)) {
                    if(map[a][b].u==0)
                        answer++;
                    map[x][y].d += 1;
                    x = a;
                    y = b;
                    map[a][b].u += 1;
                }
                break;
            case 'D':
                a = x + dx[1];
                b = y + dy[1];
                if(check(a,b)) {
                    if(map[a][b].d==0)
                        answer++;
                    map[x][y].u += 1;
                    x = a;
                    y = b;
                    map[a][b].d += 1;
                }
                break;
            case 'R':
                a = x + dx[2];
                b = y + dy[2];
                if(check(a,b)) {
                    if(map[a][b].r==0)
                        answer++;
                    map[x][y].l += 1;
                    x = a;
                    y = b;
                    map[a][b].r += 1;
                }
                break;
            case 'L':
                a = x + dx[3];
                b = y + dy[3];
                if(check(a,b)) {
                    if(map[a][b].l==0)
                        answer++;
                    map[x][y].r += 1;
                    x = a;
                    y = b;
                    map[a][b].l += 1;
                }
                break;
        }
    }
	return answer;
}