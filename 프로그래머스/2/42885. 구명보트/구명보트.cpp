#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    deque<int> sorted;
    
    for (int person : people)
        sorted.push_back(person);
    
    sort(sorted.begin(), sorted.end());
    
    while(!sorted.empty())
    {
        int remainingWeight = limit;
        
        int heavy = sorted.back();
        sorted.pop_back();
        
        remainingWeight -= heavy;
        
        if (sorted.empty())
        {
            sorted.pop_back();
            ++answer;
            break;
        }
        
        int light = sorted.front();
        
        if (remainingWeight >= light)
        {
            sorted.pop_front();
            ++answer;
        }
        else
            ++answer;
    }
    
    return answer;
}