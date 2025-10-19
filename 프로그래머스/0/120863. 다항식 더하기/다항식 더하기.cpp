#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    
    vector<string> tokens;
    
    istringstream iss(polynomial);
    string w;
    
    while(iss >> w)
    {
        tokens.push_back(w);
    }
    
    
    int a = 0; // x 앞에 붙는 거
    int b = 0; // x 없는 거
    
    for (string token : tokens)
    {   
        if (token == "+")
            continue;
        
        if (token.find("x") == string::npos)
        {
            b += stoi(token);
        }
        else
        {
            string numStr = token.substr(0, token.size() - 1);
            cout << numStr.size() << endl;
            
            if (numStr.size() == 0)
                a += 1;
            else
                a += (stoi(numStr));
            
        }
    }
    
    if (a > 0 && b > 0)
    {
        if (a == 1)
            answer = "x + " + to_string(b);
        else
            answer = to_string(a) + "x + " + to_string(b);
    }
    else if (a == 0 && b > 0)
        answer = to_string(b);
    else if (a > 0 && b == 0)
    {
        if (a == 1)
            answer = "x";
        else
            answer = to_string(a) + "x";
    }
    
    return answer;
}