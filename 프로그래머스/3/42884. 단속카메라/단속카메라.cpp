#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    
    int cameraPos = routes[0][1];
    int answer = 1;
    
    for (int i = 1; i < routes.size(); ++i)
    {
        int posA = routes[i][0];
        int posB = routes[i][1];
        
        if (cameraPos < posA)
        {
            ++answer;
            cameraPos = posB;
        }
        else if (posB < cameraPos)
            cameraPos = posB;        
    }
    
    return answer;
}