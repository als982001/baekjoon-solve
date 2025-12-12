#include <string>
#include <vector>

using namespace std;

struct Trie {
    bool finish;
    Trie* node[10];
    
    Trie() {
        this->finish = false;
        
        for (int i = 0; i < 10; ++i)
            this->node[i] = NULL;
    }
    
    void Insert(string str, int idx);
    bool IsPrefix(string str, int idx);
};

void Trie::Insert(string str, int idx)
{
    if (idx >= str.size())
    {
        this->finish = true;
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
        for (int i = 0; i < 10; ++i)
        {
            if (this->node[i] != NULL)
                return true;
        }
        
        return false;
    }
    
    int num = str[idx] - '0';
    
    return this->node[num]->IsPrefix(str, idx + 1);
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    Trie* trie = new Trie();

    for (string phone : phone_book)
        trie->Insert(phone, 0);
    
    for (string phone : phone_book)
    {
        bool isPrefix = trie->IsPrefix(phone, 0);
        
        if (isPrefix)
        {
            answer = false;
            break;
        }
    }
    
    return answer;
}