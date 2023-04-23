#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int cameraNum = 1;
    
    sort(routes.begin(), routes.end());
    
    int endPos = routes[0][1];
    
    for (int i = 1; i < routes.size(); ++i)
    {
        int routeStart = routes[i][0];
        int routeEnd = routes[i][1];
        
        if (routeEnd < endPos)
            endPos = routeEnd;
        else if (endPos < routeStart)
        {
            ++cameraNum;
            endPos = routeEnd;
        }
    }
    
    return cameraNum;
}


/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end());

    int lastPos = routes[0][1];

    for (int i = 1; i < routes.size(); ++i)
    {
        if (routes[i][1] < lastPos)
            lastPos = routes[i][1];
        else if (lastPos < routes[i][0])
        {
            ++answer;
            lastPos = routes[i][1];
        }
    }

    return answer;
}
*/