using namespace std;

long long gcd(long long a, long long b) {
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

long long solution(int w,int h) {
    long long answer = 1;
    long long x = (long long)w;
    long long y = (long long)h;
    long long whole = x*y;
    long long crushed = x+y-gcd(x,y);
    answer = whole-crushed;
    return answer;
}