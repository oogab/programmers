#include <cstring>
#include <vector>

using namespace std;

bool putKey(vector<vector<int>>& key, vector<vector<int>> nlock, int x, int y, int n, int m) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            nlock[i+x][j+y] += key[i][j];
        }
    }
    for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (nlock[i+m-1][j+m-1] == 1) continue;
			return false;
		}
	}
    return true;
}

void turnKey(vector<vector<int>>& key) {
    vector<vector<int>> ckey = key;
    for(int i=0; i<key.size(); i++) {
        for(int j=0; j<key.size(); j++) {
            ckey[j][key.size()-i-1] = key[i][j];
        }
    }
    key = ckey;
    return;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int n = lock.size();
    int m = key.size();
    
    vector<vector<int>> nlock(n+2*m-2, vector<int>(n+2*m-2));
    
    for(int i=m-1; i<m-1+n; i++) {
        for(int j=m-1; j<m-1+n; j++) {
            nlock[i][j] = lock[i-m+1][j-m+1];
        }
    }
    
    for(int turn=0; turn<4; turn++) {
        for(int i=0; i<m-1+n; i++) {
            for(int j=0; j<m-1+n; j++) {
                answer = putKey(key, nlock, i, j, n, m);
                if(answer) return answer;
            }
        }
        turnKey(key);
    }
    
    return answer;
}