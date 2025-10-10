#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    vector<char> letters;
    
    for (char letter : my_string)
    {
        if ('A' <= letter && letter <= 'Z')
            letters.push_back(letter - 'A' + 'a');
        else
            letters.push_back(letter);
    }
    
    sort(letters.begin(), letters.end());
    
    for (char letter : letters)
        answer += letter;
    
    
    
    return answer;
}