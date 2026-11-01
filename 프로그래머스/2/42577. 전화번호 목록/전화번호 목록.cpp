#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Trie
{
    bool finish;
    Trie* node[10];
    
    Trie()
    {
        this->finish = false;
        
        for (int num = 0; num < 10; ++num)
            this->node[num] = NULL;
    }
    
    void Insert(string str, int idx);
    bool IsPrefix(string str, int idx);
    bool Search(string str, int idx);
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
        bool isPrefix = false;
        
        for (int num = 0; num < 10; ++num)
        {
            if (this->node[num] != NULL)
            {
                isPrefix = true;
                break;
            }
        }
        
        return isPrefix;
    }
    
    int num = str[idx] - '0';
    
    if (this->node[num] == NULL)
        return false;
    
    return this->node[num]->IsPrefix(str, idx + 1);
}

bool Trie::Search(string str, int idx)
{
    if (idx >= str.size())
        return this->finish;
    
    int num = str[idx] - '0';
    
    if (this->node[num] == NULL)
        return false;
    
    return this->node[num]->Search(str, idx + 1);
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
    
    for (string phone : phone_book)
    {        
        bool searched = trie->Search(phone, 0);
        
        // cout << phone << " => " << (searched ? "찾음" : "못 찾음") << endl;
    }
    
    return answer;
}
