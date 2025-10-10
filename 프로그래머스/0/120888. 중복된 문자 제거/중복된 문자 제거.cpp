#include <string>
#include <vector>
#include <set>

using namespace std;

set<char> lettersRecord;

bool CanSave(char letter)
{
    return lettersRecord.find(letter) == lettersRecord.end();
}

string solution(string my_string) {
    string answer = "";
    
    for (char letter : my_string)
    {
        bool canSave = CanSave(letter);
        
        if (canSave)
        {
            lettersRecord.insert(letter);
            answer += letter;
        }
    }
    
    return answer;
}