using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long a = 1;
    long long b = 1;
    long long targetN;
    
    if (N==1)
    {
        answer = 4;
        return answer;
    }
    
    for(int i=2; i<N; i++) {
        targetN = a+b;
        a = b;
        b = targetN;    
    }
    
    answer = targetN*4 + a*2;
    return answer;
}