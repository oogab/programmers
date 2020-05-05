#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    int len = 1;
    for(int i=1; i<n; i++) {
        vector<int> half;
        answer.push_back(0);
        for(int j=len-1; j>=0; j--) {
            half.push_back(1-answer[j]);
        }
        len = len*2+1;
        answer.insert(answer.end(), half.begin(), half.end());
    }
    return answer;
}