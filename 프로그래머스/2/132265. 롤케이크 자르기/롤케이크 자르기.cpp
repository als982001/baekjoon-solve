#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<vector<int>> toppingTypeCounts(topping.size(), vector<int>(2, 0));
    
    set<int> leftSet;
    set<int> rightSet;
    
    for (int leftIdx = 0, rightIdx = topping.size() - 1; leftIdx < topping.size(); ++leftIdx, --rightIdx)
    {
        int leftNum = topping[leftIdx];
        
        if (leftSet.find(leftNum) == leftSet.end())
        {
            leftSet.insert(leftNum);
            
            toppingTypeCounts[leftIdx][0] = (leftIdx == 0) ? 1 : toppingTypeCounts[leftIdx - 1][0] + 1;
        }
        else
            toppingTypeCounts[leftIdx][0] = toppingTypeCounts[leftIdx - 1][0];
        
        int rightNum = topping[rightIdx];
        
        if (rightSet.find(rightNum) == rightSet.end())
        {
            rightSet.insert(rightNum);
            
            toppingTypeCounts[rightIdx][1] = (rightIdx == topping.size() - 1) ? 1 : toppingTypeCounts[rightIdx + 1][1] + 1;
        }
        else
            toppingTypeCounts[rightIdx][1] = toppingTypeCounts[rightIdx + 1][1];
    }
    
    for (int idx = 0; idx < topping.size() - 1; ++idx)
    {
        if (toppingTypeCounts[idx][0] == toppingTypeCounts[idx + 1][1])
            ++answer;
    }
    
    
    return answer;
}