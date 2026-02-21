#include <string>
#include <vector>
#include <algorithm>

#define MAX 27
#define MAX_LEN 100005

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
    
    int GetMatchCount(const string& str, int idx)
    {
        if (str[idx] == '?')
            return this->count;
        
        int num = str[idx] - 'a';
        
        if (this->node[num] == NULL)
            return 0; // 매칭되는 단어 없음
        
        return this->node[num]->GetMatchCount(str, idx + 1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    Trie* forwardTries[MAX_LEN] = { NULL }; // ?가 뒤에 오는 케이스
    Trie* reverseTries[MAX_LEN] = { NULL }; // ?가 앞에 오는 케이스
    
    for (int i = 0; i < MAX_LEN; ++i)
    {
        forwardTries[i] = new Trie();
        reverseTries[i] = new Trie();
    }
    
    for (string word : words)
    {
        int wordLen = word.size();
        
        if (forwardTries[wordLen] == NULL)
        {
            forwardTries[wordLen] = new Trie();
            reverseTries[wordLen] = new Trie();
        }
        
        forwardTries[wordLen]->Insert(word, 0);
        
        string reversedWord = word; 
        reverse(reversedWord.begin(), reversedWord.end());
        
        reverseTries[wordLen]->Insert(reversedWord, 0);
    }
    
    for (string query : queries)
    {   
        int queryLen = query.size();
        
        // ★ 해당 길이의 트라이 자체가 생성된 적이 없다면 당연히 0개
        if (forwardTries[queryLen] == NULL)
        {
            answer.push_back(0);
            continue;
        }
        
        if (query[0] == '?')
        {
            reverse(query.begin(), query.end());
            answer.push_back(reverseTries[queryLen]->GetMatchCount(query, 0));
        }
        else
            answer.push_back(forwardTries[queryLen]->GetMatchCount(query, 0));
    }
    
   
    
    return answer;
}