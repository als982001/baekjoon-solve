#include <string>
#include <vector>
#include <sstream>

#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for (string q : quiz)
    {
        vector<string> tokens;
        istringstream iss(q);
        string w;
        
        while(iss >> w)
            tokens.push_back(w);
        
        int x = stoi(tokens[0]);
        int y = stoi(tokens[2]);
        int z = stoi(tokens[4]);
        
        cout << x << " " << tokens[1] << " " << y << " " << tokens[3] << " " << z << endl;
        
        if (tokens[1] == "+")
        {
            answer.push_back(x + y == z ? "O" : "X");
        }
        else
            answer.push_back(x - y == z ? "O" : "X");
    }
    
        
    
    
    return answer;
}