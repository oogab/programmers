#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int num = citations.size();
    sort(citations.begin(), citations.end());
    for(int h=0; h<=citations.back(); h++) {
        int cnt = 0;
        for(int i=0; i<num; i++) {
            if(h<=citations[i]) {
                cnt++;
            }
        }
        if(h<=cnt) {
            if(answer<h)
                answer = h;
        }
    }
    return answer;
}