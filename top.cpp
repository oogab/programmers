#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int len = heights.size();
    answer.resize(len);
    for(int i=len-1; i>=0; i--) {
        int num = heights[i];
        for(int j=i; j>=0; j--) {
            if(num < heights[j]) {
                answer[i] = j+1;
                break;
            } 
        }
    }

    return answer;
}