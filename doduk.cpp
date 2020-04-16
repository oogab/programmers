#include <string>
#include <vector>
#include <cstring>

using namespace std;

int d[1000000];

int solution(vector<int> money) {
    int answer = 0;
    int len = money.size();
    
    if(len==1)
        return money[0];
    else if(len==2)
        return max(money[0], money[1]);
    
    // 첫 번째 집을 털었을 경우
    d[0] = money[0];
    d[1] = money[0];
   
    for(int i=2; i<len; i++) {
        d[i] = max(d[i-2]+money[i], d[i-1]);
    }
    
    answer = d[len-2];
    
    memset(d, 0, sizeof(d));
    
    // 두 번째 집을 털었을 경우 
    d[0] = 0;
    d[1] = money[1];
    
    for(int i=2; i<len; i++) {
        d[i] = max(d[i-2]+money[i], d[i-1]);
    }
    
    // 둘 중 더 큰 쪽을 정답으로 선택
    answer = max(answer, d[len-1]);
    
    return answer;
}