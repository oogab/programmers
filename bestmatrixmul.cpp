#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int size = matrix_sizes.size();
    int d[size+1][size+1];
    
    vector<int> p(size+1);
    p[0] = matrix_sizes[0][0];
    
    for(int i=0; i<size; i++) {
        p[i+1] = matrix_sizes[i][1];
    }
    
    for(int dig=0; dig<size; dig++) {
        for(int i=1; i<=size-dig; i++) {
            int j=i+dig;
            if(i==j) {
                d[i][j] = 0;
                continue;
            }
            d[i][j] = 1000000000;
            for(int k=i; k<=j-1; k++) {
                int tmp = d[i][k] + d[k+1][j] + p[i-1]*p[k]*p[j];
                if(tmp < d[i][j]) {
                    d[i][j] = tmp;
                }
            }
        }
    }
    
    answer = d[1][size];
    return answer;
}