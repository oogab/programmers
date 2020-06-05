#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size()/2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int kinds = nums.size();
    
    if(kinds > size)
        answer = size;
    else
        answer = kinds;
    
    return answer;
}