#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    set<string> words;
    
    for (int i = 0; i < s1.size(); ++i)
    {
        string word = s1[i];
        words.insert(word);
    }
    
    for (int i = 0; i < s2.size(); ++i)
    {
        string word = s2[i];
        
        bool hasWord = words.find(word) != words.end();
        
        if (hasWord)
            ++answer;
    }
    
    return answer;
}