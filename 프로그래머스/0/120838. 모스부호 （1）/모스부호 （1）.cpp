#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, char> MORSE = {
    {".-",  'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..",  'd'}, {".",    'e'}, {"..-.", 'f'},
    {"--.", 'g'}, {"....", 'h'}, {"..",   'i'}, {".---", 'j'}, {"-.-",  'k'}, {".-..", 'l'},
    {"--",  'm'}, {"-.",   'n'}, {"---",  'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.",  'r'},
    {"...", 's'}, {"-",    't'}, {"..-",  'u'}, {"...-", 'v'}, {".--",  'w'}, {"-..-", 'x'},
    {"-.--",'y'}, {"--..", 'z'}
};

string solution(string letter) {
    string answer = "";
    
    int idx = letter.find(" ");
    
    while(idx != -1)
    {
        string morse = letter.substr(0, idx);
        
        char alp = MORSE.find(morse)->second;
        
        answer += alp;
        
        letter = letter.substr(idx + 1);
        idx = letter.find(" ");
    }
    
    if (letter.size() > 0)
    {
        char alp = MORSE.find(letter)->second;
        answer += alp;
    }
    
    return answer;
}