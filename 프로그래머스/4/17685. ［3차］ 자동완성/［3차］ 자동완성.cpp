#include <string>
#include <vector>
#include <iostream>

#define MAX 26

using namespace std;

struct Trie
{
    int count;
    Trie* node[MAX];
    
    Trie()
    {
        this->count = 0;
        
        for (int i = 0; i < MAX; ++i)
            this->node[i] = NULL;
    }
    
    void Insert(const string& str, int idx)
    {
        ++this->count;
        
        if (idx >= str.size())
            return;
        
        int num = str[idx] - 'a';
        
        if (this->node[num] == NULL)
            this->node[num] = new Trie();
        
        this->node[num]->Insert(str, idx + 1);
    }
    
    int GetInputCount(const string& str, int idx)
    {
        // 현재까지에 해당하는 문자열(문자열 일부)이 하나밖에 없는 경우
        if (this->count == 1)
            return idx;
        
        // 문자열 끝까지 다 확인했는데 매칭되는 게 하나밖에 없는 경우
        if (idx >= str.size())
            return str.size();
        
        int num = str[idx] - 'a'; 
        
        return this->node[num]->GetInputCount(str, idx + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    
    Trie* trie = new Trie();
    
    // 먼저 전부 Insert를 한다.
    for (string word : words)
        trie->Insert(word, 0);
    
    // word를 하나씩 확인한다.
    for (string word : words)
    {
        int inputCount = trie->GetInputCount(word, 0);
                
        answer += inputCount;
    }
    
    return answer;
}