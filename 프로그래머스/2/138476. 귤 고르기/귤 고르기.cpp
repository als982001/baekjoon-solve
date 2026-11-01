#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> sizeCounts;
vector<int> sizes;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for (int size : tangerine)
    {
        if (sizeCounts[size])
            ++sizeCounts[size];
        else
        {
            sizeCounts[size] = 1;
            sizes.push_back(size);
        }
    }
    
    sort(sizes.begin(), sizes.end(), [&](int a, int b) { 
             return sizeCounts[a] > sizeCounts[b]; 
         });
    
    for (int size : sizes)
    {
        int curSizeCount = sizeCounts[size];
        
        k -= curSizeCount;
        ++answer;
    
        if (k <= 0)
            break;
    }
    
    return answer;
}
