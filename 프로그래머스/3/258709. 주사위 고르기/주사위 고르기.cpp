#include <string>
#include <vector>
#include <iostream>

#define MAX 11

using namespace std;

bool chosen[MAX];
int chosenNum = 0;
vector<int> aDices;
vector<int> bDices;
vector<int> aSums;
vector<int> bSums;
vector<vector<int>> dices;

int maxWin = -1;
vector<int> answer;

void Sum(int diceIdx, int sum, vector<int>& curDices, vector<int>& curSums)
{
    if (diceIdx == curDices.size())
    {
        curSums.push_back(sum);
        return;
    }
    
    for (int num : dices[curDices[diceIdx]])
        Sum(diceIdx + 1, sum + num, curDices, curSums);
}

void Choose(int idx)
{    
    if (chosenNum == dices.size() / 2)
    {
        // 2. 모든 경우의 수를 따진다.
        int curWin = 0;
        
        // 2-1. a, b 주사위를 나눈다.
        aDices.clear();
        bDices.clear();
        
        aSums.clear();
        bSums.clear();
        
        for (int i = 0; i < dices.size(); ++i)
        {
            if (chosen[i])
                aDices.push_back(i);
            else
                bDices.push_back(i);
        }
        
        // 2-2. a, b 모든 케이스를 기록한다.
        Sum(0, 0, aDices, aSums);
        Sum(0, 0, bDices, bSums);
        
        // 2-3. 모든 케이스를 비교한다.
        for (int aSum : aSums)
        {
            for (int bSum : bSums)
            {
                if (aSum > bSum)
                    ++curWin;
            }
        }
        
        // 2-4. 갱신할 수 있으면 갱신
        if (maxWin < curWin)
        {
            maxWin = curWin;
            
            answer.clear();
            
            for (int aDice : aDices)
                answer.push_back(aDice + 1);
        }
        
        return;
    }
    
    for (int nxtIdx = idx; nxtIdx < dices.size(); ++nxtIdx)
    {
        chosen[nxtIdx] = true;
        ++chosenNum;
        
        Choose(nxtIdx + 1);
        
        --chosenNum;
        chosen[nxtIdx] = false;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    dices = dice;
    
    // 1. n/2개의 주사위를 선택한다.
    Choose(0);    
    
    return answer;
}












/*

#include <string>
#include <vector>
#include <iostream>

#define MAX 11

using namespace std;

int maxWinCount = -1;
vector<int> answer;
bool taken[MAX];
vector<int> aDices;
vector<int> bDices;
vector<int> aScores;
vector<int> bScores;
vector<vector<int>> dices;

void Sum(int diceIdx, vector<int>& nums, vector<int>& scores, vector<int>& diceIdxes)
{
    if (diceIdxes.size() <= diceIdx)
    {
        int score = 0;
        
        for (int num : nums)
            score += num;
        
        scores.push_back(score);
        
        return;
    }
    
    for (int i = 0; i < dices[diceIdxes[diceIdx]].size(); ++i)
    {
        nums.push_back(dices[diceIdxes[diceIdx]][i]);
        Sum(diceIdx + 1, nums, scores, diceIdxes);
        nums.pop_back();
    }
}

int CheckWinCount()
{
    bDices.clear();
    aScores.clear();
    bScores.clear();
    
    for (int i = 0; i < dices.size(); ++i)
    {
        if (!taken[i])
            bDices.push_back(i);
    }
    
    vector<int> nums;
    
    Sum(0, nums, aScores, aDices);
    
    nums.clear();
    
    Sum(0, nums, bScores, bDices);
    
    
    int winCount = 0;
    
    for (int aScore : aScores)
    {
        for (int bScore : bScores)
        {
            if (aScore > bScore)
                ++winCount;
        }
    }
    
    return winCount;
}

void TakeDice(int startIdx)
{    
    
    if (startIdx >= dices.size())
        return;
    
    if (aDices.size() == (dices.size() / 2))
    {
        int winCount = CheckWinCount();
        
        if (maxWinCount < winCount)
        {
            maxWinCount = winCount;
            answer.clear();
    
            for (int aDice : aDices)
                answer.push_back(aDice + 1);
        }
        
        return;
    }
    
    for (int idx = startIdx; idx < dices.size(); ++idx)
    {
        if (!taken[idx])
        {
            taken[idx] = true;
            aDices.push_back(idx);
        
            TakeDice(idx);
        
            aDices.pop_back();
            taken[idx] = false;
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    dices = dice;
    
    TakeDice(0);
    
    return answer;
}

*/