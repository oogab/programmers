#include <cstring>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    bool check[prices.size()];
    memset(check, false, sizeof(check));
    
    for(int idx=1; idx<prices.size(); idx++) {
        if(prices[idx] < prices[idx-1]) {
            int back = 0;
            while(prices[idx] < prices[idx-back-1]) {
                back++;
                if(check[idx-back]) continue;
                answer[idx-back] = back;
                check[idx-back] = true;
            }
        }
    }
    
    for(int i=0; i<prices.size(); i++) {
        if(check[i]==false) {
            check[i] = true;
            answer[i] = prices.size()-i-1;
        }
    }
    
    return answer;
}