#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int reach = w*2 + 1;
    int start = 0;
    int end;
    int dis;
    
    for(int i = 0; i < stations.size(); i++) {
        end = stations[i]-w;
        if(end > start) {
            dis = end-start-1;
            answer += dis / reach;
            if(dis%reach != 0)
                answer += 1;
        }
        start = stations[i]+w;
    }
    
    if(start < n) {
        dis = n-start;
        answer += dis / reach;
        if(dis%reach != 0)
            answer += 1;
    }
    
    return answer;
}