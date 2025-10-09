#include <string>
#include <vector>

using namespace std;

string ConvertString(string str)
{
    string result = "";
    
    for (int i = 0; i < str.size(); ++i)
    {
        char letter = str[i];
        
        if ('A' <= letter && letter <= 'Z')
            result += (letter + 32);
        else
            result += letter;
    }
    
    return result;
}

int solution(string myString, string pat) {
    string covertedMyString = ConvertString(myString);
    string convertedPat = ConvertString(pat);
    
    return covertedMyString.find(convertedPat) == -1 ? 0 : 1;
}