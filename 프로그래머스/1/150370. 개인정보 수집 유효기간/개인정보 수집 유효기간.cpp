#include <string>
#include <vector>
#include <sstream>
#include <map>

#define YEAR 12
#define MONTH 28

using namespace std;

vector<string> SplitString(string str, char splitTarget)
{
    vector<string> result;
    
    stringstream ss(str);
    string segment;
    
    while(getline(ss, segment, splitTarget))
        result.push_back(segment);
    
    return result;
}

int DateToInt(string day)
{
    int dayNum = 0;
    
    stringstream ss(day);
    string segment;
    
    vector<int> infos;
    
    while(getline(ss, segment, '.'))
        infos.push_back(stoi(segment));
    
    dayNum += (infos[0] * YEAR * MONTH);
    dayNum += (infos[1] * MONTH);
    dayNum += infos[2];
    
    return dayNum;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todayNum = DateToInt(today);
    map<string, int> termsMap;
    
    for (string term : terms)
    {
        vector<string> termInfos = SplitString(term, ' ');
        
        termsMap[termInfos[0]] = stoi(termInfos[1]) * MONTH;
    }
    
    for (int idx = 0; idx < privacies.size(); ++idx)
    {
        string privacy = privacies[idx];
        
        vector<string> privacyInfo = SplitString(privacy, ' ');
        
        int startDateNum = DateToInt(privacyInfo[0]);
        int term = termsMap[privacyInfo[1]];
        
        if (startDateNum + term <= todayNum)
            answer.push_back(idx + 1);
    }
    
    return answer;
}









/*

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


*/
