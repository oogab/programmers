#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    sort(jobs.begin(), jobs.end()); // 작업들이 요청되는 시점을 기준으로 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> job_list;
    
    int start;
    int end;
    int sum = 0;
    int i = 0;
    bool run = false;
    
    while(i <= size) {
        if(!run) {  // 디스크가 작동하지 않고 있을 경우
            if(i==size) // 모든 작업들을 처리했을 경우
                break;  // 끝
            else {      // 아직 작업이 남아있을 경우
                start = jobs[i][0];
                end = start + jobs[i][1];
                sum += end - start;
                run = true;
                i++;
            }           // 남은 작업 중 요청시간이 가장 짧은 작업 처리 후 디스크 작동 상태 변경
        }
        else {       // 디스크가 작동하고 있는 경우
            while (jobs[i][0] <= end && i < size) { // 이전 작업의 완료 시간안에 요청이 들어온 작업들을 작업 대기 큐에 넣는다.
                job_list.push(make_pair(jobs[i][1], jobs[i][0]));
                i++;
            }
            if(job_list.empty())    // 작업 대기 큐가 비었을 경우 디스크 작동 상태 변경
                run = false;
            else {                  // 작업 대기 큐에 작업이 남을 경우 작업 처리
                start = end;
                end = start + job_list.top().first;
                sum += end - job_list.top().second;
                job_list.pop();
            }
        }
    }
    
    answer = sum / size;
    return answer;
}