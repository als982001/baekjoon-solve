#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    priority_queue<pair<int, int>> pq;
    
    for (int idx = 0; idx < rank.size(); ++idx)
    {
        bool isValidRank = attendance[idx];
        int currentRank = rank[idx];
        
        if (isValidRank)
            pq.push({ -currentRank, idx });
    }
    
    /*
    pair<int, int> a = pq.top();
    pq.pop();
    pair<int, int> b = pq.top();
    pq.pop();
    pair<int, int> c = pq.top();
    pq.pop();
    
    string tempResult = "";
    tempResult += to_string(a.first);
    tempResult += to_string(a.second);
    tempResult += to_string(b.first);
    tempResult += to_string(b.second);
    tempResult += to_string(c.first);
    tempResult += to_string(c.second);
    
    return stoi(tempResult);
    */
    
    
    int a = pq.top().second;
    pq.pop();
    
    int b = pq.top().second;
    pq.pop();
    
    int c = pq.top().second;
    pq.pop();
    
    answer = (10000 * a) + (100 * b) + c;
    
    return answer;
}