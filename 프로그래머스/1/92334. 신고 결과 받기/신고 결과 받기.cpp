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
