#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string str1, string str2) {
    return str1+str2 > str2+str1;
}

string solution(vector<int> numbers) {
    string answer = "";
    int len = numbers.size();
    vector<string> a;
    for(int i=0; i<len; i++) {
        string s = to_string(numbers[i]);
        a.push_back(s);
    }
    sort(a.begin(), a.end(), cmp);
    
    for(int i=0; i<len; i++) {
        answer += a[i];
    }
    
    for(int i=0; i<len; i++) {
        if(a[i]!="0")
            break;
        answer = "0";
    }
    
    return answer;
}