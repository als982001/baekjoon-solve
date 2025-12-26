#include <string>
#include <vector>
#define MAX 101
#define MOD 1000000007

using namespace std;

int maxR, maxC;
bool canVisit[MAX][MAX];
int record[MAX][MAX];
int dir[2][2] = { { 1, 0 }, { 0, 1 } };

int Visit(int r, int c)
{       
    if (r == maxR && c == maxC)
        return 1;
    
    if (record[r][c] > -1)
        return record[r][c];
    
    record[r][c] = 0;
    
    for (int i = 0; i < 2; ++i)
    {
        int nxtR = r + dir[i][0];
        int nxtC = c + dir[i][1];
                
        if (nxtR <= maxR && nxtC <= maxC && canVisit[nxtR][nxtC])
            record[r][c] = (record[r][c] + Visit(nxtR, nxtC)) % MOD;
    }
    
    return record[r][c];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    maxR = n;
    maxC = m;
    
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
        {
            record[r][c] = -1;
            canVisit[r][c] = true;
        }
    }
    
    for (vector<int> puddle : puddles)
    {
        int r = puddle[1];
        int c = puddle[0];
        
        canVisit[r][c] = false;
    }
        
    answer = Visit(1, 1);    
    
    return answer;
}