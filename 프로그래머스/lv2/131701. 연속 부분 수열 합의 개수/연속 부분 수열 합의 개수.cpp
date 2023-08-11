#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, bool> check;

int Count(vector<int> elements, int len)
{
    int count = 0;
    
    for (int startIdx = 0; startIdx < elements.size(); ++startIdx)
    {
        int sum = 0;
       
        for (int idx = startIdx, t = 0; t < len; ++t)
        {
            sum += elements[idx];
            
            ++idx;
            
            if (idx >= elements.size())
                idx = 0;
        }
       
        if (check[sum] == false)
        {
            ++count;
            check[sum] = true;
        }
    }
    
    return count;
}

int solution(vector<int> elements) {
    int answer = 0;
    
    for (int len = 1; len <= elements.size(); ++len)
    {
        int count = Count(elements, len);
        
        answer += count;
    }
    
    return answer;
}