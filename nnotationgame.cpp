#include <string>
#include <vector>

using namespace std;

char iToA(int num) {
    switch(num) {
        case 0:
            return '0';
            break;
        case 1:
            return '1';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;
        case 10:
            return 'A';
            break;
        case 11:
            return 'B';
            break;
        case 12:
            return 'C';
            break;
        case 13:
            return 'D';
            break;
        case 14:
            return 'E';
            break;
        case 15:
            return 'F';
            break;
        default:
            return 0;
    }
}

string decToN(int num, int n) {
    string conv = "";
    while((num/n)!=0) {
        conv = iToA(num%n) + conv;
        num = num/n;
    }
    conv = iToA(num) + conv;
    return conv;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string cand = "";
    for(int realNum = 0; realNum < t*m; realNum++) {
        cand = cand + decToN(realNum, n);
    }
    for(int i=p-1; answer.size()<t; i += m) {
        answer = answer + cand[i];
    }
    return answer;
}