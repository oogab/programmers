#include <string>
#include <vector>

using namespace std;

long long d[5001];

int solution(int n) {
    int answer = 0;
    int p = 0;
    d[0] = 1;
    for(int i=2; i<=n; i+=2) {
        d[i] = d[i-2]*3 + 2*p;
        p += d[i-2];
        d[i] %= 1000000007;
    }
    answer = d[n];
    return answer;
}