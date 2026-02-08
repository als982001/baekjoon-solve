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