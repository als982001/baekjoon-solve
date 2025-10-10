#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    
    map<char, int> letterCounts;
    
    for (char letter : s)
    {
        letterCounts[letter] += 1;
    }
    
    // letterCounts를 순회해서 second가 1인 것들에 대해 first를 answer에 붙인다.
    for (auto iter : letterCounts) 
    {
        char letter = iter.first;
        char letterCount = iter.second;
        
        if (letterCount == 1)
            answer += letter;
    }
    
    return answer;
}