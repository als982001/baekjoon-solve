#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

map<string, int> reportedCount;
map<string, vector<string>> reportIds;

bool ReportedId(string reporter, string reportedId)
{
    bool isReportedId = false;
    
    for (string reportId : reportIds[reporter])
    {
        if (reportId == reportedId)
        {
            isReportedId = true;
            break;
        }
    }
    
    return isReportedId;
}

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer;
    
    for (string id : id_list)
    {
        reportedCount[id] = 0;
        reportIds[id] = {};
    }
    
    for (string report : reports)
    {
        stringstream ss(report);
        string segment;
        
        vector<string> reportInfo;
        
        while(getline(ss, segment, ' '))
            reportInfo.push_back(segment);
        
        if (ReportedId(reportInfo[0], reportInfo[1]) == false)
        {
            ++reportedCount[reportInfo[1]];
            reportIds[reportInfo[0]].push_back(reportInfo[1]);
        }
    }
    
    for (string id : id_list)
    {
        int mail = 0;
        
        for (string reportedId : reportIds[id])
        {
            if (reportedCount[reportedId] >= k)
                ++mail;
        }
        
        answer.push_back(mail);
    }
    
    return answer;
}










/*

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<pair<string, string>, bool> reportRecord;
    map<string, int> reportedCount;
    map<string, vector<string>> reports;
    
    for (string id : id_list)
        reportedCount[id] = 0;
    
    for(string rep : report)
    {
        stringstream ss(rep);
        string segment;
        
        vector<string> reportInfo;
        
        while(getline(ss, segment, ' '))
            reportInfo.push_back(segment);
        
        if (!reportRecord[{reportInfo[0], reportInfo[1]}])
        {
            reportRecord[{reportInfo[0], reportInfo[1]}] = true;
            reports[reportInfo[0]].push_back(reportInfo[1]);
            ++reportedCount[reportInfo[1]];
        }
    }
    
    for (string id : id_list)
    {
        int cnt = 0;
        
        for (string reportedId : reports[id])
        {
            if (reportedCount[reportedId] >= k)
                ++cnt;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}


*/