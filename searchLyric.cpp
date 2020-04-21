#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#define ALPHA   26

using namespace std;

struct trie {
    trie *next[26];
    bool finish;    // 단어의 마지막임을 표시, 이 문제에서는 딱히 필요없다.
    int total;      // 해당 노드를 몇 번의 지나쳤는지 카운트 = 자식의 개수
    
    trie() : finish(false), total(0) {
        memset(next, NULL, sizeof(next));
    }
    
    ~trie() {
        for(int i=0; i<ALPHA; i++) {
            if(next[i] != NULL) {
                delete next[i];
            }
        }
    }
    
    void insert(const char *str) {
        if(*str == '\0') {      // 더이상 입력 받을 단어가 없으면 단어의 끝임을 저장하고 return한다.
            finish = true;
            return;
        }
        int cur = *str - 'a';   // 알파벳 순서를 숫자로 변형하여 저장한다.
        if(next[cur] == 0) {
            next[cur] = new trie();
        }
        
        next[cur]->total++;
        next[cur]->insert(str+1);
    }
    
    int find(const char* str) {
        if(*str == '?') {       // solution 구조상 aaa?? 이런 형태의 입력만 존재하지만,
            int sum = 0;        // 모든 키워드가 ?로 이루어질 경우를 처리하기 위해 확인해준다.
            for(int i=0; i<ALPHA; i++) {
                if(next[i] == NULL) continue;
                sum += next[i]->total;
            }
            return sum;
        }
        else {                          // 단어의 알파벳이 입력되었을 경우.
            int cur = *str - 'a';       
            if(next[cur] == NULL) {     // 해당 단어가 존재하지 않으면 단어와 키워드가 일치하지 않는다.
                return 0;               // 종료.
            }
            if(*(str+1) == '?') {           // 다음 단어가 '?'일 경우 끝까지 '?'로 이루어져 있으므로,
                return next[cur]->total;    // 다음 노드의 total값 반환한다.
            }
            return next[cur]->find(str+1);  // 다음 단어가 알파벳일 경우 find 함수 재귀 호출.
        }
    }
};

trie* root[10001];      // 단어 길이별로 정방향으로 저장 
trie* revers[10001];    // 단어 길이별로 역방향으로 저장 

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    memset(root, NULL, sizeof(root));
    memset(revers, NULL, sizeof(revers));
    
    for(int i=0; i<words.size(); i++) {
        int wordsize = words[i].size(); // 단어를 길이별로 저장한다.
        if(root[wordsize] == NULL) {
            root[wordsize] = new trie();
            revers[wordsize] = new trie();
            
            root[wordsize]->insert(words[i].c_str());
            reverse(words[i].begin(), words[i].end());
            revers[wordsize]->insert(words[i].c_str());
        }
        else {
            root[wordsize]->insert(words[i].c_str());
            reverse(words[i].begin(), words[i].end());
            revers[wordsize]->insert(words[i].c_str());
        }
    }
    
    for(int i=0; i<queries.size(); i++) {
        if(root[queries[i].size()] == NULL) {   // 키워드와 길이가 맞는 단어가 없으면 0개 매치.
            answer.push_back(0);
        }
        else {
            int front = queries[i][0] == '?' ? 1 : 0; // 키워드 앞 글자가 ? 이면 front는 1 아니면 0
            if(front) {
                reverse(queries[i].begin(), queries[i].end());  // front가 1이면 키워드가 ?로 시작하므로 역방향 자료구조를 이용한다.
                answer.push_back(revers[queries[i].size()]->find(queries[i].c_str()));
            }
            else {  // front가 0이면 키워드가 알파벳으로 시작하므로 정방향 자료구조를 이용한다.
                answer.push_back(root[queries[i].size()]->find(queries[i].c_str()));
            }
        }
    }

    return answer;
}