#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> weights;

bool Compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), Compare);
    
    for (int i = 0; i < people.size(); ++i)
        weights.push_back(people[i]);
    
    while(!weights.empty())
    {
        int curLimit = limit;
        curLimit -= weights.front();
        weights.pop_front();
        
        if (!weights.empty())
        {
            int lightest = weights.back();
            
            if (curLimit >= lightest)
            {
                curLimit -= lightest;
                weights.pop_back();
            }
        }
        
        ++answer;
    }
    
    return answer;
}