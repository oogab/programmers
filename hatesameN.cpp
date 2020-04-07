#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int len = arr.size();
    for(int i=1; i<len; i++) {
        if(arr[i]!=arr[i-1])
            answer.push_back(arr[i-1]);
    }
    answer.push_back(arr.back());

    return answer;
}