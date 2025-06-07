#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;
string ps;
vector<string> answers;

bool CheckValidPS ()
{
    bool isValid = true;
    vector<char> stk;
    
    for (int i = 0; i < ps.size(); ++i)
    {
        char p = ps[i]; // p: parenthesis
        
        if (p == '(')
            stk.push_back(p);
        if (p == ')')
        {
            // '('가 없으면 valid하지 않음
            if (stk.empty())
            {
                isValid = false;
                break;
            }
            
            char previousP = stk.back();
            stk.pop_back();
            
            // 괄호가 )) 이면 valid하지 않음
            if (previousP == ')')
            {
                isValid = false;
                break;
            }
        }
    }
    
    if (stk.size() > 0)
        isValid = false;
    
    return isValid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> T;
    
    for (int t = 0; t < T; ++t)
    {
        cin >> ps;
        
        bool isValid = CheckValidPS();
        
        if (isValid)
            answers.push_back("YES");
        else
            answers.push_back("NO");
    }
    
    for (int i = 0; i < answers.size(); ++i)
        cout << answers[i] << endl;
        

    
    return 0;
}