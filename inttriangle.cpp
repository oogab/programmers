#include <string>
#include <vector>

using namespace std;

int D[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    D[0][0] = triangle[0][0];
    for(int i=1; i<height; i++) {
        for(int j=0; j<i+1; j++) {
            if(j==0)
                D[i][j] = D[i-1][j] + triangle[i][j];
            else if (j==i)
                D[i][j] = D[i-1][j-1] + triangle[i][j];
            else {
                D[i][j] = max(D[i-1][j] + triangle[i][j],
                              D[i-1][j-1] + triangle[i][j]);
            }
        }
    }

    for(int i=0; i<height; i++) {
        if(answer < D[height-1][i])
            answer = D[height-1][i];
    }
    return answer;
}