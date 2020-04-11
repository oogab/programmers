#include <string>
#include <vector>

using namespace std;

bool check_col(vector<vector<bool>> &col, vector<vector<bool>> &row, int x, int y) {
    if(y==1)                // 바닥에 기둥을 설치할 경우
        return true;
    else if(col[x][y-1])    // 아래에 기둥이 설치되어 있을 경우
        return true;
    else if(row[x-1][y])    // 왼쪽 아래에 보가 설치되어 있을 경우
        return true;
    else if(row[x][y])      // 아래에 보가 설치되어 있을 경우
        return true;
    else                 // 그 외 설치 불가
        return false;
}

bool check_row(vector<vector<bool>> &col, vector<vector<bool>> &row, int x, int y) {
    if(col[x][y-1])                         // 아래에 기둥이 설치되어 있을 경우
        return true;
    else if(col[x+1][y-1])                  // 오른쪽 아래에 기둥이 설치되어 있을 경우
        return true;
    else if(row[x-1][y] && row[x+1][y])     // 양쪽에 보가 설치되어 있을 경우
        return true;
    else                                    // 그 외 설치 불가
        return false;
}

bool canRemove(vector<vector<bool>> &col, vector<vector<bool>> &row, int n, int x, int y, int type) {
    bool result = true;

    if (type == 0) col[x][y] = false; // 임시로 삭제
    else row[x][y] = false;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            if (col[i][j] && !check_col(col, row, i, j)) {
                result = false;
                break;
            }
            if (row[i][j] && !check_row(col, row, i, j)) {
                result = false;
                break;
            }
        }
    }

    if (type == 0) col[x][y] = true; // 삭제했던 구조물 원상복구
    else row[x][y] = true;

    return result;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    int loop = build_frame.size();
    vector<vector<bool>> col(n+3, vector<bool>(n+3));
    vector<vector<bool>> row(n+3, vector<bool>(n+3));

    // 초기화 해줄 필요 없지만 하니 실행 속도가 더 빨랐다.
    for(int i=0; i<n+3; i++) {
        for(int j=0; j<n+3; j++) {
            col[i][j] = false;
            row[i][j] = false;
        }
    }
    
    for(int i=0; i<loop; i++) {
        int x = build_frame[i][0]+1;
        int y = build_frame[i][1]+1;
        int type = build_frame[i][2];
        int conORdel = build_frame[i][3];
        
        if(type==0) { // 기둥 설치 혹은 삭제
            if(conORdel==1 && check_col(col, row, x, y)) {
                col[x][y] = true;
            }
            else if(conORdel==0 && canRemove(col, row, n, x, y, 0)) {
                col[x][y] = false;
            }
        }
        else { // 보 설치 혹은 삭제
            if(conORdel==1 && check_row(col, row, x, y)) {
                row[x][y] = true;
            }
            else if(conORdel==0 && canRemove(col, row, n, x, y, 1)) {
                row[x][y] = false;
            }
        }
    }

    vector<vector<int>> answer;

    for(int i=1; i<=n+1; i++) {
        for(int j=1; j<=n+1; j++) {
            if(col[i][j]) {
                vector<int> tmp;
                tmp.push_back(i-1);
                tmp.push_back(j-1);
                tmp.push_back(0);
                answer.push_back(tmp);
            }
            if(row[i][j]) {
                vector<int> tmp;
                tmp.push_back(i-1);
                tmp.push_back(j-1);
                tmp.push_back(1);
                answer.push_back(tmp);
            }
        }
    }
    
    return answer;
}