#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idxa = A.size()-1;
    int idxb = B.size()-1;
    while(idxa>=0) {
        if(A[idxa]>=B[idxb]) {
            idxa--;
            continue;
        }
        if(A[idxa]<B[idxb]) {
            idxa--;
            idxb--;
            answer++;
        }
    }
    return answer;
}