#include <string>
#include <vector>

#include <iostream>

using namespace std;

string GetNewWord(string word)
{
    char lastLetter = word[word.size() - 1];
    string leftWord = word.substr(0, word.size() - 1);
    
    return lastLetter + leftWord;
}

int solution(string A, string B) {
    int answer = -1;
    
    if (A == B)
        return 0;
    
    for (int t = 1; t < A.size(); ++t)
    {        
        A = GetNewWord(A);
        
        if (A == B)
        {
            answer = t;
            break;
        }
    }
    
    return answer;
}