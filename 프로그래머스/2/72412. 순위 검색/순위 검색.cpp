#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> scores[4][3][3][3];

int GetLanguageIdx(string lang)
{
    if (lang == "cpp")
        return 1;
    else if (lang == "java")
        return 2;
    else if (lang == "python")
        return 3;
    return 0;
}

int GetOccupIdx(string occup)
{
    if (occup == "backend")
        return 1;
    else if (occup == "frontend")
        return 2;
    return 0;
}

int GetHistoryIdx(string history)
{
    if (history == "junior")
        return 1;
    else if (history == "senior")
        return 2;
    return 0;
}

int GetFoodIdx(string food)
{
    if (food == "chicken")
        return 1;
    else if (food == "pizza")
        return 2;
    return 0;
}

// 모든 케이스에 대해 저장
// 0번 인덱스는 모든 케이스(언어의 경우 cpp, java, python)를 포함하는 경우
void PushScoreAtAllCase(int langIdx, int occupIdx, int historyIdx, int foodIdx, int score)
{
    scores[langIdx][occupIdx][historyIdx][foodIdx].push_back(score);
    
    scores[0][occupIdx][historyIdx][foodIdx].push_back(score);
    scores[langIdx][0][historyIdx][foodIdx].push_back(score);
    scores[langIdx][occupIdx][0][foodIdx].push_back(score);
    scores[langIdx][occupIdx][historyIdx][0].push_back(score);
    
    scores[0][0][historyIdx][foodIdx].push_back(score);
    scores[0][occupIdx][0][foodIdx].push_back(score);
    scores[0][occupIdx][historyIdx][0].push_back(score);
    scores[langIdx][0][0][foodIdx].push_back(score);
    scores[langIdx][0][historyIdx][0].push_back(score);
    scores[langIdx][occupIdx][0][0].push_back(score);
    
    scores[0][0][0][foodIdx].push_back(score);
    scores[0][0][historyIdx][0].push_back(score);
    scores[0][occupIdx][0][0].push_back(score);
    scores[langIdx][0][0][0].push_back(score);
    
    scores[0][0][0][0].push_back(score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (int i = 0; i < info.size(); ++i)
    {
        vector<string> volunteer;
        vector<int> infoIdxes;
        
        stringstream ss(info[i]);
        string segment;
        
        while(getline(ss, segment, ' '))
            volunteer.push_back(segment);
        
        int langIdx = GetLanguageIdx(volunteer[0]);
        int occupIdx = GetOccupIdx(volunteer[1]);
        int historyIdx = GetHistoryIdx(volunteer[2]);
        int foodIdx = GetFoodIdx(volunteer[3]);
        int score = stoi(volunteer[4]);
        
        PushScoreAtAllCase(langIdx, occupIdx, historyIdx, foodIdx, score);
    }
    
    // 쿼리 확인 전 점수 크기를 오름차순으로 정렬
    for (int langIdx = 0; langIdx < 4; ++langIdx)
    {
        for (int occupIdx = 0; occupIdx < 3; ++occupIdx)
        {
            for (int historyIdx = 0; historyIdx < 3; ++historyIdx)
            {
                for (int foodIdx = 0; foodIdx < 3; ++foodIdx)
                    sort(scores[langIdx][occupIdx][historyIdx][foodIdx].begin(), scores[langIdx][occupIdx][historyIdx][foodIdx].end());
                    
            }
        }
    }
    
    for (string q : query)
    {
        vector<string> queryInfo;
        
        stringstream ss(q);
        string segment;
        
        int langIdx = 0;
        int occupIdx = 0;
        int historyIdx = 0;
        int foodIdx = 0;
        int targetScore = 0;
        
        int cnt = 0; // 쿼리에 해당하는 케이스 개수를 저장
        
        while(getline(ss, segment, ' '))
        {
            if (segment != "and")
                queryInfo.push_back(segment);
        }
        
        for (int i = 0; i < queryInfo.size(); ++i)
        {
            if (i == 0)
                langIdx = GetLanguageIdx(queryInfo[i]);
            else if (i == 1)
                occupIdx = GetOccupIdx(queryInfo[i]);
            else if (i == 2)
                historyIdx = GetHistoryIdx(queryInfo[i]);
            else if (i == 3)
                foodIdx = GetFoodIdx(queryInfo[i]);
            else if (i == 4)
                targetScore = stoi(queryInfo[i]);
        }
        
        int targetIdx = lower_bound(scores[langIdx][occupIdx][historyIdx][foodIdx].begin(), 
                          scores[langIdx][occupIdx][historyIdx][foodIdx].end(), 
                          targetScore) 
            - scores[langIdx][occupIdx][historyIdx][foodIdx].begin();
        
        cnt = scores[langIdx][occupIdx][historyIdx][foodIdx].size() - targetIdx;
            
        answer.push_back(cnt);
    }
    
    return answer;
}