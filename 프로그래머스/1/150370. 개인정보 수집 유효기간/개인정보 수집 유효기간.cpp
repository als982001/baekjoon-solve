#include <string>
#include <vector>
#include <map>
#include <iostream>

#define YEAR 12
#define MONTH 28

using namespace std;

int DateToInt(string date)
{   
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    int sum = (year * YEAR * MONTH) + (month * MONTH) + day;
    
    return sum;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<string, int> termsByKey;

    int todayNum = DateToInt(today);

    for (string term : terms)
    {
        string key = term.substr(0, 1);
        string month = term.substr(2, term.size() - 2);
        
        int monthNum = (stoi(month)) * MONTH;
     
        termsByKey[key] = monthNum;
    }
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        string privacy = privacies[i];
        string date = privacy.substr(0, 10);
        string key = privacy.substr(11, privacy.size() - date.size() - 1);
        
        int dateNum = DateToInt(date);
        int termNum = termsByKey[key];
        
        int lastDayNum = dateNum + termNum - 1;
        
        if (todayNum > lastDayNum)
            answer.push_back(i + 1);
    }
    
    return answer;
}
