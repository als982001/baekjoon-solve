#include <string>
#include <vector>
using namespace std;

#define MAX 11

struct Trie 
{
    bool isFinish;
    Trie* node[MAX];
    
    Trie()
    {
        this->isFinish = false;
        
        for (int i = 0; i < MAX; ++i)
                this->node[i] = NULL;
    }
    
    void Insert(string str, int idx);
    bool IsPrefix(string str, int idx);
};

void Trie::Insert(string str, int idx)
{
    if (idx >= str.size())
    {
        this->isFinish = true;
        return;
    }
    
    int num = str[idx] - '0';
    
    if (this->node[num] == NULL)
        this->node[num] = new Trie();
    this->node[num]->Insert(str, idx + 1);
}

bool Trie::IsPrefix(string str, int idx)
{
    if (idx >= str.size())
    {
        for (int i = 0; i < MAX; ++i)
        {
            if (this->node[i] != NULL)
                return false;
        }
        
        return true;
    }
    
    int num = str[idx] - '0';
    
    return this->node[num]->IsPrefix(str, idx + 1);
}

bool solution(vector<string> phone_book) {
    Trie* trie = new Trie();
    
    for (int i = 0; i < phone_book.size(); ++i)
    {
        string phoneNum = phone_book[i];
        
        trie->Insert(phoneNum, 0);
    }
    
    for (int i = 0; i < phone_book.size(); ++i)
    {
        string phoneNum = phone_book[i];
        
        bool result = trie->IsPrefix(phoneNum, 0);
        
        if (result == false)
            return false;
    }
    
    return true;
}