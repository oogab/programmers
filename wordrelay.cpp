#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> used;
    string prev = words[0];   string next;
    int nth_person = 0;     int nth_time = 0;
    bool check = false;
    used.push_back(words[0]);
    
    for(int i=1; i<words.size(); i++) {
        next = words[i];
        if(prev.back() != next.front()) {
            nth_person = (i % n) + 1;
            nth_time = (i / n) + 1;
            break;
        }
        
        for(int j=0; j<used.size(); j++) {
            if(used[j]==next) {
                check = true;
                nth_person = (i % n) + 1;
                nth_time = (i / n) + 1;
                break;
            }
        }
        
        if(check)
            break;
        
        used.push_back(next);
        prev = next;
    }
    
    answer.push_back(nth_person);
    answer.push_back(nth_time);

    return answer;
}