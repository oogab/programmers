#include <string>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    string op;  int num;
    
    for(int i=0; i<operations.size(); i++) {
        stringstream oper;
        oper.str(operations[i]);
        
        oper >> op;
        oper >> num;
        
        if(op=="I") {
            dq.push_front(num);
            int tmp;
            for(int i=0; i<dq.size()-1; i++) {
                if(dq[i] > dq[i+1]) {
                    tmp = dq[i];
                    dq[i] = dq[i+1];
                    dq[i+1] = tmp;
                }
            }
        }
        
        else if(op=="D") {
            if(dq.empty()) continue;
            if(num==1)
                dq.pop_back();
            else if(num==-1)
                dq.pop_front();
        }
    }
    
    if(dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}