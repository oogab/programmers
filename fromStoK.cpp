#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[100001];

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    for(int i=0; i<travel.size(); i++) {
        for(int j=K; j>=0; j--) {
            d[j] = -100000;
            if(j >= travel[i][2])
                d[j] = max(d[j], d[j-travel[i][2]]+travel[i][3]);
            if(j >= travel[i][0])
                d[j] = max(d[j], d[j-travel[i][0]]+travel[i][1]);
        }
    }
    
    answer = d[K];
    return answer;
}