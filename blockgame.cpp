#include <iostream>
#include <string>
#include <vector>

using namespace std;

int row;
int col;
int cand[5][3][2] = {
    {{1,0}, {1,1}, {1,2}},      // 1    가로ㄴ
    {{1,0}, {1,-1}, {1,-2}},    // 2    역가로ㄴ
    {{1,0}, {2,0}, {2,1}},      // 3    세로ㄴ
    {{1,0}, {2,0}, {2,-1}},     // 4    역세로ㄴ
    {{1,0}, {1,1}, {1,-1}}      // 5    빠큐
};                              // 0    못지우는 모양

int BlockNum(vector<vector<int>>& board, int x, int y) {
    int n = 0;
    for(int i=0; i<5; i++) {
        int cnt = 0;
        for(int j=0; j<3; j++) {
            int a = x + cand[i][j][0];
            int b = y + cand[i][j][1];
            if(0 <= a && a < board.size() && 0 <= b && b < board.size()) {
                if(board[x][y]!=board[a][b])
                    break;
                else
                    cnt++;
            }
        }
        if(cnt==3) {
            n = i+1;
        }
    }
    return n;     // 0 반환 시 지울 수 없는 모양이다.
}

bool CanRemove(vector<vector<int>>& board, int n, int x, int y) {
    switch(n)
    {
    case 1:
        for(int i=0; i<x+1; i++) {
            if(board[i][y+1]!=0 || board[i][y+2]!=0) {
                return false;
            }
        }            
        return true;
            
    case 2:
        for(int i=0; i<x+1; i++) {
            if(board[i][y-1]!=0 || board[i][y-2]!=0) {
                return false;
            }
        }
        return true;
            
    case 3:
        for(int i=0; i<x+2; i++) {
            if(board[i][y+1]!=0) {
                return false;
            }
        }
        return true;
            
    case 4:
        for(int i=0; i<x+2; i++) {
            if(board[i][y-1]!=0) {
                return false;
            }
        }
        return true;
            
    case 5:
        for(int i=0; i<x+1; i++) {
            if(board[i][y+1]!=0 || board[i][y-1]!=0) {
                return false;
            }
        }
        return true;
    }
}

void Remove(vector<vector<int>>& board, int n, int x, int y) {
    switch(n) 
    {
    case 1:
        board[x][y] = 0;
        for(int j=0; j<3; j++) {
            int a = x + cand[0][j][0];
            int b = y + cand[0][j][1];
            board[a][b] = 0;
        }
        return;
            
    case 2:
        board[x][y] = 0;
        for(int j=0; j<3; j++) {
            int a = x + cand[1][j][0];
            int b = y + cand[1][j][1];
            board[a][b] = 0;
        }
        return;
            
    case 3:
        board[x][y] = 0;
        for(int j=0; j<3; j++) {
            int a = x + cand[2][j][0];
            int b = y + cand[2][j][1];
            board[a][b] = 0;
        }
        return;
            
    case 4:
        board[x][y] = 0;
        for(int j=0; j<3; j++) {
            int a = x + cand[3][j][0];
            int b = y + cand[3][j][1];
            board[a][b] = 0;
        }
        return;
            
    case 5:
        board[x][y] = 0;
        for(int j=0; j<3; j++) {
            int a = x + cand[4][j][0];
            int b = y + cand[4][j][1];
            board[a][b] = 0;
        }
        return;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    for(row = 0; row < n; row++) {
        for(col = 0; col < n; col++) {
            if(board[row][col] > 0) {
                int what = BlockNum(board, row, col);
                if(!what) continue;
                if(CanRemove(board, what, row, col)) {
                    answer++;
                    Remove(board, what, row, col);
                    row = 0; // 시발 이걸 생각 못했네...
                }
            }
        }
    }
    return answer;
}