#include <iostream>
#include <vector>
#include <string>

using namespace std;

int answer = 0;
int N;
vector<string> words;

int main()
{
    ios_base::sync_with_stdio(0);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    cin >> N;
    
    for (int n = 0; n < N; ++n)
    {
        string word;
        cin >> word;
        
        words.push_back(word);
    }
    
    for (int i = 0; i < words.size(); ++i)
    {
        bool isGoodWord = true;
        
        string word = words[i];
        
        vector<char> stk;
        
        for (int k = 0; k < word.size(); ++k)
        {
            char alp = word[k];
            
            if (stk.empty())
                stk.push_back(alp);
            else
            {
                char prevAlp = stk.back();
                
                if (alp == prevAlp)
                    stk.pop_back();
                else
                    stk.push_back(alp);
            }
        }
        
        if (stk.empty() == false)
            isGoodWord = false;
                
        if (isGoodWord)
            ++answer;
    }
    
    cout << answer << endl;
    
    return 0;
}