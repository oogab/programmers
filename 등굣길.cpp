#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[101][101] = {0,};
    int path[101][101];
    
    for(int i=0; i<puddles.size(); i++)
        map[puddles[i][0]][puddles[i][1]] = -1;

    path[1][0] = 1;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)         
        {
            if (map[i][j] == -1)
                path[i][j] = 0;
            else
                path[i][j] = (path[i-1][j] + path[i][j-1]) % 1000000007;
        }
    }
    
    return path[m][n];
}
