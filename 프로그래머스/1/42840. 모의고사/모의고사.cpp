#include <string>
#include <vector>

#include <iostream>

using namespace std;

int GetPerson1Score(vector<int>& answers)
{   
    int score = 0;
    
    for (int idx = 0; idx < answers.size(); ++idx)
    {
        if (answers[idx] == idx % 5 + 1)
            ++score;
    }
    
    return score;
}

int GetPerson2Score(vector<int>& answers)
{
    int score = 0;
    
    for (int idx = 0; idx < answers.size(); ++idx)
    {
        if (idx % 2 == 0)
        {
            if (answers[idx] == 2)
                ++score;
        }
        else
        {
            int val = 1;
            
            if (idx % 8 == 3)
                val = 3;
            else if (idx % 8 == 5)
                val = 4;
            else if (idx % 8 == 7)
                val = 5;
                
            if (answers[idx] == val)
                ++score;
        }    
    }
    
    return score;
}

int GetPerson3Score(vector<int>& answers)
{
    int score = 0;
    
    for (int idx = 0; idx < answers.size(); ++idx)
    {
        if ((idx % 10) < 2)
        {
            if (answers[idx] == 3)
                ++score;
        }
        else if ((idx % 10) < 4)
        {
            if (answers[idx] == 1)
                ++score;
        }
        else if ((idx % 10) < 6)
        {
            if (answers[idx] == 2)
                ++score;
        }
        else if ((idx % 10) < 8)
        {
            if (answers[idx] == 4)
                ++score;
        }
        else if ((idx % 10) < 10)
        {
            if (answers[idx] == 5)
                ++score;
        }
    }
    
    return score;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> scores;
    
    scores.push_back(GetPerson1Score(answers));
    scores.push_back(GetPerson2Score(answers));
    scores.push_back(GetPerson3Score(answers));
    
    int maxScore = Max(Max(scores[0], scores[1]), scores[2]);
    
    for (int i = 0; i < scores.size(); ++i)
    {
        if (scores[i] == maxScore)
            answer.push_back(i + 1);
    }
    
    return answer;
}