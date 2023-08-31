#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;
/*
bool check[5][5];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool Is_In(int r, int c)
{
    return 0 <= r && r < 5 && 0 <= c && c < 5;
}

bool Dangerous_Zone(int r, int c, int pr, int pc)
{
    int diffR = abs(r - pr);
    int diffC = abs(c - pc);

    if (diffR + diffC <= 2)
        return true;
    else
        return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); ++i)
    {
        memset(check, false, sizeof(check));

        vector<string> curPlace = places[i];

        bool isSafe = true;

        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c < 5; ++c)
            {
                if (isSafe && curPlace[r][c] == 'P')
                {
                    queue<pair<int, int>> q;
                    q.push(make_pair(r, c));
                    isSafe = true;

                    check[r][c] = true;

                    while (!q.empty())
                    {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();

                        if (curPlace[curR][curC] == 'P')
                        {
                            if (curR != r || curC != c)
                            {
                                // 실패
                                isSafe = false;
                                break;
                            }
                        }

                        for (int i = 0; i < 4; ++i)
                        {
                            int nxtR = curR + nr[i];
                            int nxtC = curC + nc[i];

                            if (Is_In(nxtR, nxtC) && 
                                Dangerous_Zone(nxtR, nxtC, r, c) && 
                                !check[nxtR][nxtC] && 
                                curPlace[nxtR][nxtC] != 'X')
                            {
                                check[nxtR][nxtC] = true;
                                q.push(make_pair(nxtR, nxtC));
                            }
                        }
                    }
                }
            }
        }

        if (isSafe)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}
*/

#define SIZE 5
int nr[3][4] = { { 1, -1, 0, 0 }, { 2, -2, 0, 0 }, { 1, 1, -1, -1 } };
int nc[3][4] = { { 0, 0, 1, -1 }, { 0, 0, 2, -2 }, { 1, -1, -1, 1 } };
bool Is_In(int r, int c)
{
	return 0 <= r && r < 5 && 0 <= c && c < 5;
}

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;

	for (int placeIdx = 0; placeIdx < places.size(); ++placeIdx)
	{
		vector<string> place = places[placeIdx];

		bool followRule = true;

		for (int r = 0; r < SIZE && followRule; ++r)
		{
			for (int c = 0; c < SIZE && followRule; ++c)
			{
				if (place[r][c] == 'P')
				{
					int curR = r;
					int curC = c;

					for (int i = 0; i < 4; ++i)
					{
						int nxtR = curR + nr[0][i];
						int nxtC = curC + nc[0][i];

						if (!Is_In(nxtR, nxtC))
							continue;

						if (place[nxtR][nxtC] == 'P')
						{
							followRule = false;
							break;
						}
					}

					if (followRule)
					{
						for (int i = 0; i < 4; ++i)
						{
							int nxtR = curR + nr[1][i];
							int nxtC = curC + nc[1][i];

							if (!Is_In(nxtR, nxtC))
								continue;

							if (place[nxtR][nxtC] == 'P')
							{
								int midR = nxtR - nr[0][i];
								int midC = nxtC - nc[0][i];

								if (place[midR][midC] == 'O')
								{
									followRule = false;
									break;
								}
							}
						}
					}

					if (followRule)
					{
						for (int i = 0; i < 4; ++i)
						{
							int nxtR = curR + nr[2][i];
							int nxtC = curC + nc[2][i];

							if (!Is_In(nxtR, nxtC))
								continue;

							if (place[nxtR][nxtC] == 'P')
							{
								switch (i)
								{
								case 0:
								{
									if (!(place[curR + 1][curC] == 'X' && place[curR][curC + 1] == 'X'))
										followRule = false;

									break;
								}
								case 1:
								{
									if (!(place[curR + 1][curC] == 'X' && place[curR][curC - 1] == 'X'))
										followRule = false;

									break;
								}
								case 2:
								{
									if (!(place[curR - 1][curC] == 'X' && place[curR][curC - 1] == 'X'))
										followRule = false;

									break;
								}
								case 3:
								{
									if (!(place[curR - 1][curC] == 'X' && place[curR][curC + 1] == 'X'))
										followRule = false;

									break;
								}
								}
							}

							if (followRule == false)
								break;
						}

					}
				}
			}
		}

		if (followRule == true)
			answer.push_back(1);
		else
			answer.push_back(0);
	}

	return answer;
}