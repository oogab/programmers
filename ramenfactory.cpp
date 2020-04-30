#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    int len = dates.size();
    int idx = 0;
    while(stock<k) {
        while(idx<len && dates[idx]<=stock) {
            pq.push(supplies[idx]);
            idx++;
        }
        stock += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}