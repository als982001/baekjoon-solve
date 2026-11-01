#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int idx1 = 0;
    int idx2 = people.size() - 1;
    
    while(idx1 <= idx2)
    {
        int light = people[idx1];
        int heavy = people[idx2];
        
        if (idx1 == idx2)
        {
            ++answer;
            break;
        }
        
        if (light + heavy > limit)
        {
            --idx2;
        }
        else
        {
            ++idx1;
            --idx2;
        }
        
        ++answer;
    }
    
    return answer;
}