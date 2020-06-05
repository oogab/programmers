#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len = skill.size();
    int tree_len = skill_trees.size();
    bool skill_check[len];
    bool right[tree_len];
    memset(right, true, sizeof(right));
    
    for(int i=0; i<tree_len; i++) {
        memset(skill_check, false, sizeof(skill_check));
        string tmp = skill_trees[i];
        for(int j=0; j<tmp.size() && right[i]; j++) {
            for(int k=0; k<len; k++) {
                if(tmp[j]==skill[k]) {
                    if(k==0)
                        skill_check[k] = true;
                    else {
                        if(skill_check[k-1]) {
                            skill_check[k] = true;
                        }
                        else {
                            right[i] = false;
                            break;
                        }
                    }
                }
                else
                    continue;
            }
        }
    }
    for(int j=0; j<tree_len; j++) {
        if(right[j])
            answer++;
    }
    return answer;
}