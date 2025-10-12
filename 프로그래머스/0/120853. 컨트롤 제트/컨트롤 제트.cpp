#include <string>
#include <vector>
#include <sstream>


using namespace std;

int solution(string s) {
    int answer = 0;
    
    vector<string> tokens;
    istringstream iss(s);
    string w;
    
    int befNum = 0;
    
    // 공백을 기준으로 단어 추출
    while (iss >> w) 
    {          
        tokens.push_back(w);
    }
    
    for (string token : tokens)
    {
        if (token == "Z")
        {
            answer -= befNum;
        }
        else
        {
            int num = stoi(token);
            answer += num;
            befNum = num;
        }
    }
    
    
    
    
    
    return answer;
}