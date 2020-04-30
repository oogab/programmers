#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int len = commands.size();
    for(int i=0; i<len; i++) {
        vector<int> narr;
        int start = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        for(int k=start; k<=end; k++) {
            narr.push_back(array[k-1]);
        }
        sort(narr.begin(), narr.end());
        answer.push_back(narr[target-1]);
    }
    
    return answer;
}