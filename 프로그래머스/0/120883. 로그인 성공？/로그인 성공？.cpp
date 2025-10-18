#include <string>
#include <vector>

using namespace std;

string LOGIN = "login";
string FAIL = "fail";
string WRONG_PW = "wrong pw";

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = FAIL;
    
    string id = id_pw[0];
    string password = id_pw[1];
    
    for (int i = 0; i < db.size(); ++i)
    {
        string dbId = db[i][0];
        string dbPassword = db[i][1];
        
        bool isValidId = id == dbId;
        
        if (isValidId)
        {
            bool isValidPassword = password == dbPassword;
            
            if (isValidPassword)
            {
                answer = LOGIN;
                break;
            }
            else
                answer = WRONG_PW;
        }
    }
    
    return answer;
}