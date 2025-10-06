#include <string>
#include <vector>

#define a 97
#define TO_CAPITAL 32

using namespace std;

string solution(string myString) {
    string answer = "";
    
    // A: 65
    // a: 97
    
    for (int i = 0; i < myString.size(); ++i)
    {
        char curChar = myString[i];
        
        if (curChar >= a)
            curChar -= TO_CAPITAL;
        
        answer += curChar;
        
    }
    
    return answer;
}