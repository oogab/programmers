#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(), budgets.end());
    int prov = budgets.size();
    
    for(int i=0; i<prov; i++) {
        int avg = M/(prov-i);
        if(budgets[i] <= avg) {
            M -= budgets[i];
        }
        else {
            answer = avg;
            return answer;
        }
    }
    
    answer = budgets.back();
    return answer;
}