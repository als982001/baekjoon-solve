#include <string>
#include <vector>
#define DOWN 0
#define RIGHT 1
#define UP 2
using namespace std;

int N;
int lastNum = 0;
vector<vector<int>> triangle; 

int nr[3] = { 1, 0, -1 };
int nc[3] = { 0, 1, -1 };

bool IsIn(int r, int c)
{
	if (0 > r || r >= N)
		return false;

	return 0 <= c && c <= r;
}

int ChangeDirection(int dir)
{
    if (dir == UP)
        return DOWN;
    else
        return dir + 1;
}

void Check(int r, int c, int num, int dir)
{
	if (num > lastNum)
        return;

    triangle[r][c] = num;
    
    int nxtR = r + nr[dir];
    int nxtC = c + nc[dir];

	if (IsIn(nxtR, nxtC))
	{
		if (triangle[nxtR][nxtC] > 0)
		{
			dir = ChangeDirection(dir);

			nxtR = r + nr[dir];
			nxtC = c + nc[dir];
		}
	}
	else
	{
		dir = ChangeDirection(dir);

		nxtR = r + nr[dir];
		nxtC = c + nc[dir];
	}

	Check(nxtR, nxtC, num + 1, dir);
}

vector<int> solution(int n) {
    vector<int> answer;
    
    N = n;
    
    for (int h = 1; h <= n; ++h)
    {
        vector<int> line;
        
        for (int k = 0; k < h; ++k)
            line.push_back(0);
        
        triangle.push_back(line);
    }
    
    for (int k = 1; k <= n; ++k)
        lastNum += k;
    
	Check(0, 0, 1, DOWN);

    for (int r = 0; r < triangle.size(); ++r)
    {
        for (int c = 0; c < triangle[r].size(); ++c)
            answer.push_back(triangle[r][c]);
	}
    
    
    return answer;
}