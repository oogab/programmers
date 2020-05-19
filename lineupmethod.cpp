#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num(n,0);
    long long fact[n];
    fact[0] = 1;
    
    for(int i=0; i<n; i++) {
        num[i] = i+1;
    }
    
    for(int i=0; i<n-1; i++) {
        fact[i+1] = fact[i]*(i+1);
    }

    while(n!=0) {
        long long a = (k-1) / fact[n-1];
        long long b = (k-1) % fact[n-1];
        
        answer.push_back(num[a]);
        num.erase(num.begin()+a);
        
        k = b+1;
        n = n-1;
    }

    return answer;
}