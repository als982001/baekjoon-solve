#include <string>
#include <vector>
#define MAX 102

using namespace std;

vector<int> win[MAX];   // win[x]: x가 이긴 선수들
vector<int> lose[MAX];  // lose[x]: x가 진 선수들
bool check[MAX][MAX];   // check[x][y] == true: x와 y간의 사이를 체크함

void Check(int winner, int loser)
{
    for (int i = 0; i < win[loser].size(); ++i)
    {
        int weaker = win[loser][i];
        
        if (check[winner][weaker] == false)
        {
            check[winner][weaker] = true;
            check[weaker][winner] = true;
            
            Check(winner, weaker);
            
            win[winner].push_back(weaker);
            lose[weaker].push_back(winner);
        }
    }
    
    for (int i = 0; i < lose[winner].size(); ++i)
    {
        int stronger = lose[winner][i];
        
        if (check[stronger][loser] == false)
        {
            check[stronger][loser] = true;
            check[loser][stronger] = true;
            
            Check(stronger, loser);
            
            win[stronger].push_back(loser);
            lose[loser].push_back(stronger);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int i = 0; i < results.size(); ++i)
    {
        vector<int> result = results[i];
        
        int winner = result[0];
        int loser = result[1];
        
        if (check[winner][loser] == false)
        {
            Check(winner, loser);
            check[winner][loser] = true;
            check[loser][winner] = true;
            
            win[winner].push_back(loser);
            lose[loser].push_back(winner);
        }
    }
    
    for (int player = 1; player <= n; ++player)
    {
        if (win[player].size() + lose[player].size() == n - 1)
            ++answer;
    }
    
    return answer;
}