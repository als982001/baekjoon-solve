#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    
    map<int, int> records;
    
    for (int i = 0; i < strArr.size(); ++i)
    {
        int strLen = strArr[i].size();
        
        records[strLen] += 1;        
    }
    
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        int record = it->second;
        
        if (answer < record)
            answer = record;
    }
    
    return answer;
}