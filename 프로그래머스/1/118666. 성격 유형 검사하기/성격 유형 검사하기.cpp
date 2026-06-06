#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> scores;
    scores['R'] = 0;
    scores['T'] = 0;
    scores['C'] = 0;
    scores['F'] = 0;
    scores['J'] = 0;
    scores['M'] = 0;
    scores['A'] = 0;
    scores['N'] = 0;
    
    for (int i = 0; i < survey.size(); ++i)
    {
        string s = survey[i];
        int choice = choices[i];
        
        if (choice < 4)
        {
            char curType = s[0];
            
            if (choice == 1)
                scores[curType] += 3;
            else if (choice == 2)
                scores[curType] += 2;
            else if (choice == 3)
                scores[curType] += 1;
        }
        else if (choice > 4)
        {
            char curType = s[1];
            
            if (choice == 7)
                scores[curType] += 3;
            else if (choice == 6)
                scores[curType] += 2;
            else if (choice == 5)
                scores[curType] += 1;
        }
    }
    
    if (scores['R'] >= scores['T'])
        answer += 'R';
    else
        answer += 'T';
    
    if (scores['C'] >= scores['F'])
        answer += 'C';
    else
        answer += 'F';
    
    if (scores['J'] >= scores['M'])
        answer += 'J';
    else
        answer += 'M';
    
    if (scores['A'] >= scores['N'])
        answer += 'A';
    else
        answer += 'N';
    
    return answer;
}












/*

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";

    map<char, int> score;
    score['R'] = 0, score['T'] = 0;
    score['C'] = 0, score['F'] = 0;
    score['J'] = 0, score['M'] = 0;
    score['A'] = 0, score['N'] = 0;

    int len = survey.size();

    for (int i = 0; i < len; ++i)
    {
        string curSurvey = survey[i];
        int choice = choices[i];

        char disagree = curSurvey[0];
        char agree = curSurvey[1];

        switch (choice)
        {
        case 1:
            score[disagree] += 3;
            break;
        case 2:
            score[disagree] += 2;
            break;
        case 3:
            score[disagree] += 1;
            break;
        case 5:
            score[agree] += 1;
            break;
        case 6:
            score[agree] += 2;
            break;
        case 7:
            score[agree] += 3;
            break;
        }
    }

    if (score['R'] < score['T'])
        answer += 'T';
    else
        answer += 'R';

    if (score['C'] < score['F'])
        answer += 'F';
    else
        answer += 'C';

    if (score['J'] < score['M'])
        answer += 'M';
    else
        answer += 'J';

    if (score['A'] < score['N'])
        answer += 'N';
    else
        answer += 'A';

    return answer;
}


*/