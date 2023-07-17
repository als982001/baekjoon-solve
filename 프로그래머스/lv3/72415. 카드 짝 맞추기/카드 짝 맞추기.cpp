#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ans = 987654322;
bool listCheck[7];
vector<int> cardList;
vector<int> orderOfIndex;
vector<int> orderOfEachIndex;
vector<pair<int, int>> cardPos[7];
vector<vector<int>> originalBoard;

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

int Min(int a, int b)
{
    return a < b ? a : b;
}

bool Is_In(int r, int c)
{
    return 0 <= r && r < 4 && 0 <= c && c < 4;
}

void Find_All_Card_Index_And_Nums()
{
    vector<bool> existCheck(7, false);

    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            if (originalBoard[r][c] != 0)
            {
                cardPos[originalBoard[r][c]].push_back(make_pair(r, c));

                if (existCheck[originalBoard[r][c]] == false)
                {
                    existCheck[originalBoard[r][c]] = true;
                    cardList.push_back(originalBoard[r][c]);
                }
            }
        }
    }

    sort(cardList.begin(), cardList.end());
}

int BFS(vector<vector<int>>& board, int card, int idx, int cardCnt, int startR, int startC)
{
    if (cardCnt == 2)
        return 0;

    queue<pair<pair<int, int>, int>> q;
    bool check[4][4];
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
            check[r][c] = false;
    }
   
    q.push(make_pair(make_pair(startR, startC), 0));
    check[startR][startC] = true;

    int endR, endC;

    if (cardCnt == 0)
    {
        endR = cardPos[card][idx].first;
        endC = cardPos[card][idx].second;
    }
    else
    {
        endR = cardPos[card][!idx].first;
        endC = cardPos[card][!idx].second;
    }

    while (!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int moveCnt = q.front().second;
        q.pop();

        if (curR == endR && curC == endC)
        {
            board[curR][curC] = 0;
            moveCnt += BFS(board, card, idx, cardCnt+1, endR, endC);
            return moveCnt;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nr[i];
            int nxtC = curC + nc[i];

            if (Is_In(nxtR, nxtC) && !check[nxtR][nxtC])
            {
                check[nxtR][nxtC] = true;
                q.push(make_pair(make_pair(nxtR, nxtC), moveCnt + 1));
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nr[i];
            int nxtC = curC + nc[i];

            while (true)
            {
                if (!Is_In(nxtR, nxtC))
                {
                    nxtR -= nr[i];
                    nxtC -= nc[i];
                    break;
                }

                if (board[nxtR][nxtC] != 0)
                    break;
                nxtR += nr[i];
                nxtC += nc[i];
            }

            if (!check[nxtR][nxtC])
            {
                check[nxtR][nxtC] = true;
                q.push(make_pair(make_pair(nxtR, nxtC), moveCnt + 1));
            }
        }
    }


}

void Make_Route_Of_Each_Index(vector<vector<int>> board, int cnt, int firstR, int firstC)
{
    if (cnt == cardList.size())
    {
        int result = 0;

        int startR = firstR;
        int startC = firstC;
        vector<vector<int>> tempBoard = board;

        for (int i = 0; i < cardList.size(); ++i)
        {
            int curCard = orderOfIndex[i];
            int curOrderIdx = orderOfEachIndex[i];
            
            result += BFS(tempBoard, curCard, curOrderIdx, 0, startR, startC);

            startR = cardPos[curCard][!curOrderIdx].first;
            startC = cardPos[curCard][!curOrderIdx].second;
        }
        
        ans = Min(ans, result);

        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        orderOfEachIndex.push_back(i);
        Make_Route_Of_Each_Index(board, cnt+1, firstR, firstC);
        orderOfEachIndex.pop_back();
    }
}

void Make_Route(vector<vector<int>> board, int cnt, int startR, int startC)
{
    if (cnt == cardList.size())
    {
        Make_Route_Of_Each_Index(board, 0, startR, startC);
        return;
    }

    for (int i = 0; i < cardList.size(); ++i)
    {
        if (!listCheck[i])
        {
            listCheck[i] = true;
            orderOfIndex.push_back(cardList[i]);

            Make_Route(board, cnt + 1, startR, startC);

            orderOfIndex.pop_back();
            listCheck[i] = false;
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;

    originalBoard = board;

    Find_All_Card_Index_And_Nums();
    Make_Route(board, 0, r, c);
    
    ans += (cardList.size() * 2);

    answer = ans;
    return answer;
}