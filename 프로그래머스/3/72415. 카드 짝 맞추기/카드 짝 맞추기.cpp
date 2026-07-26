#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define CARDS_NUM 7
#define BOARD_LEN 4

using namespace std;

int answer = 987654321;
int initR, initC; // 처음 주어진 시작 좌표

vector<vector<int>> board;
vector<int> cardTypes; // 카드 종류들 (1~6)
vector<pair<int, int>> cardPoses[CARDS_NUM]; // 카드별 위치(2개씩 존재)
vector<int> cardsOrder; // 카드별 찾아가는 순서
bool hasOrder[CARDS_NUM]; // 카드별 찾아가는 순서가 정해졌는지
vector<int> firstPosOfCards; // 카드별 2장 중 무엇을 먼저 찾아가는지 (0 혹은 1)

int nxtDir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

bool IsIn(int r, int c)
{
    return 0 <= r && r < BOARD_LEN && 0 <= c && c < BOARD_LEN;
}

// 모든 카드의 종류와 위치를 저장하는 함수
void FindCardTypes()
{
    vector<bool> check(CARDS_NUM, false); // 카드 존재 유무를 체크했는지 여부
    
    for (int r = 0; r < BOARD_LEN; ++r)
    {
        for (int c = 0; c < BOARD_LEN; ++c)
        {
            if (board[r][c] != 0)
            {
                int card = board[r][c];
                
                cardPoses[card].push_back({ r, c });
                
                if (check[card] == false)
                {
                    check[card] = true;
                    cardTypes.push_back(card);
                }
            }
        }
    }
    
    sort(cardTypes.begin(), cardTypes.end());
}

// 카드 종류 순서와 각 카드별 2중 중에 뭐 먼저 찾아갈지 다 정해지면, 특정 카드 특정 위치를 탐색하는 함수
int BFS(vector<vector<int>>& tempBoard, int targetCard, int targetCardPosIdx, int cardCnt, int startR, int startC)
{
    // 카드별로 두 장씩 있기 때문에 2면 다 찾은 케이스라 0을 반환
    if (cardCnt == 2)
        return 0;
    
    int totalMove = 0;

    bool visited[BOARD_LEN][BOARD_LEN];
    
    for (int r = 0; r < BOARD_LEN; ++r)
    {
        for (int c = 0; c < BOARD_LEN; ++c)
            visited[r][c] = false;
    }
    
    visited[startR][startC] = true;
    
    int targetR = cardPoses[targetCard][targetCardPosIdx].first;
    int targetC = cardPoses[targetCard][targetCardPosIdx].second;

    queue<pair<pair<int, int>, int>> q;
    
    q.push({ { startR, startC }, 0 });
    
    while(!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int curMove = q.front().second;
        
        q.pop();
        
        if (curR == targetR && curC == targetC)
        {
            tempBoard[curR][curC] = 0;
            
            int nxtTargetCardPosIdx = targetCardPosIdx == 0 ? 1 : 0;
            
            totalMove = curMove + BFS(tempBoard, targetCard, nxtTargetCardPosIdx, cardCnt + 1, targetR, targetC);
            
            break;
        }
        
        // 한 칸씩 움직이는 경우
        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nxtDir[i][0];
            int nxtC = curC + nxtDir[i][1];
            
            if (IsIn(nxtR, nxtC) && !visited[nxtR][nxtC])
            {
                visited[nxtR][nxtC] = true;
                q.push({ { nxtR, nxtC }, curMove + 1 });
            }
        }
        
        // 한 번에 쭉 이동하는 경우
        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nxtDir[i][0];
            int nxtC = curC + nxtDir[i][1];
            
            while(true)
            {
                // 범위를 벗어난 경우
                if (!IsIn(nxtR, nxtC))
                {
                    nxtR -= nxtDir[i][0];
                    nxtC -= nxtDir[i][1];
                    break;
                }
                
                // 다른 카드인 경우
                if (tempBoard[nxtR][nxtC] != 0)
                    break;
                
                nxtR += nxtDir[i][0];
                nxtC += nxtDir[i][1];
            }
            
            // 위의 while문으로 인해 IsIn 안 해도 됨
            if (!visited[nxtR][nxtC])
            {
                visited[nxtR][nxtC] = true;
                q.push({ { nxtR, nxtC }, curMove + 1 });
            }
        }
    }
    
    return totalMove;
}

void MakeFirstPosesOfCards()
{
    // 카드별 두 곳 중 뭐 먼저 갈지 정해진 경우
    if (firstPosOfCards.size() == cardTypes.size())
    {
        // 탐색을 진행한다.
        int result = 0;
        
        int startR = initR;
        int startC = initC;
        
        vector<vector<int>> tempBoard = board; // 이번 탐색에서 이용할 board
        
        for (int idx = 0; idx < cardsOrder.size(); ++idx)
        {
            int card = cardsOrder[idx];
            int firstPos = firstPosOfCards[idx];
            int secondPos = firstPos == 0 ? 1 : 0;
            
            result += BFS(tempBoard, card, firstPos, 0, startR, startC);
            
            startR = cardPoses[card][secondPos].first;
            startC = cardPoses[card][secondPos].second;
        }
        
        answer = min(answer, result);
        
        return;
    }
    
    for (int firstPosIdx = 0; firstPosIdx < 2; ++firstPosIdx)
    {
        firstPosOfCards.push_back(firstPosIdx);
        
        MakeFirstPosesOfCards();
        
        firstPosOfCards.pop_back();
    }
}

void MakeCardsOrder()
{
    // 카드 순서를 모두 정한 경우
    if (cardsOrder.size() == cardTypes.size())
    {
        // 각 카드별로 두 장씩 board에 존재하는데, 두 장 중에 무엇을 먼저 찾아갈지 정한다.
        MakeFirstPosesOfCards();
        
        return;
    }
    
    for (int card : cardTypes)
    {
        if (hasOrder[card] == false)
        {
            hasOrder[card] = true;
            cardsOrder.push_back(card);
            
            MakeCardsOrder();
            
            cardsOrder.pop_back();
            hasOrder[card] = false;
        }
    }
}

int solution(vector<vector<int>> _board, int r, int c) 
{
    // 초기값 설정
    board = _board;
    initR = r;
    initC = c;
    
    for (int card = 0; card < CARDS_NUM; ++card)
        hasOrder[card] = false;
    
    // 1. board에 존재하는 카드의 종류와 각 카드 별 위치(2장씩)를 저장한다.
    FindCardTypes();
    
    // 2. 어떤 카드 순서대로 찾을지 순서를 정한 후, 실제로 탐색(BFS)한다.
    MakeCardsOrder();
    
    answer += (cardTypes.size() * 2); // 카드 뒤집는 동작도 횟수로 포함
    
    return answer;
}