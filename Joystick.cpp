#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
int numOfWord = 0;

int findnext(int idx, string &str) {
    int right_cnt = 0;
    int left_cnt = 0;
    int ridx;   int lidx;
    
    for(int i=idx; numOfWord>0; i++) {
        if(str[i] == 'A')
            right_cnt++;
        else {
            ridx = i;
            break;
        }
        
        if(i==str.size()-1)
            i = -1;
    }
    
    for(int i=idx; numOfWord>0; i--) {
        if(str[i] == 'A')
            left_cnt++;
        else {
            lidx = i;
            break;
        }
        
        if(i==0)
            i = str.size();
    }
    
    if(right_cnt <= left_cnt) {
        answer += right_cnt;
        return ridx;
    }
    
    else {
        answer += left_cnt;
        return lidx;
    }
    
    return -1;
}

void get(int idx, string &str) {
    if(str[idx] <= 'N')
        answer += str[idx] - 'A';
    else
        answer += -(str[idx]-'Z')+1;
    
    str[idx] = 'A';
    numOfWord--;
    return;
}

int solution(string name) {
    int len = name.size();
    int idx = 0;
    
    for(int i=0; i<len; i++) {
        if(name[i]!='A')
            numOfWord++;
    }
    
    while(numOfWord!=0) {
        if(name[idx]!='A') {
            get(idx, name);
        }
        
        idx = findnext(idx, name);
    }
    
    return answer;
}