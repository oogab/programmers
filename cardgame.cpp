#include <string>
#include <vector>

using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    
    vector<vector<int>> dp(left.size()+1, vector<int>(right.size()+1));
    
    for (int i = left.size() - 1; i >= 0; i--) 
    {
        for (int j = right.size() - 1; j >= 0; j--) 
        {
            if (left[i] > right[j]) 
                dp[i][j] = dp[i][j + 1] + right[j];
            else 
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]); 
        }
    }
    answer = dp[0][0];
    return answer;
}