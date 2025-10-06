#include <string>
#include <vector>

using namespace std;

string ConvertString(string str)
{
    string result = "";
    
    for (int i = 0; i < str.size(); ++i)
    {
        result += str[i] == 'A' ? 'B' : 'A';
    }
    
    return result;
}

int solution(string myString, string pat) {
    int answer = 0;
    
    string convertedString = ConvertString(myString);
    
    int patIndex = convertedString.find(pat);
    
    if (patIndex == -1)
        answer = 0;
    else
        answer = 1;
    
    return answer;
}