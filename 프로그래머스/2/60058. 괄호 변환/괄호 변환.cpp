#include <string>
#include <vector>
#include <iostream>

#define LEFT '('
#define RIGHT ')'

using namespace std;

bool CorrectString(string s)
{
    bool correctString = true;
    int cnt = 0; // '('와 ')'를 매칭하고 남은 '('의 개수 (음수가 될 수도 있음) 
    
    for (char c : s)
    {
        if (c == LEFT)
            ++cnt;
        else
        {
            --cnt;
            
            if (cnt < 0)
            {
                correctString = false;
                break;
            }
        }
    }
    
    if (correctString == false)
        return false;
    
    return cnt == 0 ? true : false;
}

string Solve(string s)
{
    // 1단계: 빈 문자열이면 빈 문자열 반환
    // (최적화: 이미 완벽한 문자열이면 더 쪼갤 필요 없이 그대로 반환해도 무방함)
    if (s.size() == 0 || CorrectString(s))
        return s; 
    
    int cutIdx = s.size();
    int cnt = s[0] == LEFT ? 1 : -1;
    
    // 2단계: u와 v로 분리
    for (int idx = 1; idx < s.size(); ++idx)
    {
        if (s[idx] == LEFT) ++cnt;
        else --cnt;
        
        if (cnt == 0)
        {
            cutIdx = idx + 1;
            break;
        }
    }
    
    string u = s.substr(0, cutIdx);
    string v = s.substr(cutIdx);
    
    // 3단계: u가 올바른 괄호 문자열인 경우
    if (CorrectString(u))
        return u + Solve(v); 
        
    // 4단계: u가 올바른 괄호 문자열이 아닌 경우
    else
    {
        // 4-1 ~ 4-3: '(' + Solve(v) + ')'
        string result = "(" + Solve(v) + ")";
        
        // 4-4: u의 첫 번째와 마지막 문자 제거 및 방향 뒤집기
        string modifiedU = "";
        for (int i = 1; i < u.size() - 1; ++i)
        {
            if (u[i] == LEFT) modifiedU += RIGHT;
            else modifiedU += LEFT;
        }
        
        // 4-5: 이어 붙여서 반환
        return result + modifiedU; 
    }
}

string solution(string p) 
{
    if (CorrectString(p))
        return p;
    
    return Solve(p);
}
     