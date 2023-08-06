#include <string>
#include <vector>
#include <map>
using namespace std;

int nr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int nc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

map<pair<int, int>, bool> visited;
map<pair<pair<int, int>, pair<int, int>>, bool> pathPassed;

int solution(vector<int> arrows) {
    int answer = 0;
    int curR = 0;
    int curC = 0;
    
    visited[{ curR, curC }] = true;
    
    for (int i = 0; i < arrows.size(); ++i)
    {
        int arrow = arrows[i];
        
        for (int t = 0; t  < 2; ++t)
        {
            int nxtR = curR + nr[arrow];
            int nxtC = curC + nc[arrow];

            if (visited[{ nxtR, nxtC }] == true && pathPassed[{ { curR, curC }, { nxtR, nxtC } }] == false)
                ++answer;

            visited[{ nxtR, nxtC }] = true;
            pathPassed[{ { curR, curC }, { nxtR, nxtC } } ] = true;
            pathPassed[{ { nxtR, nxtC }, { curR, curC } } ] = true;

            curR = nxtR;
            curC = nxtC;
        }
    }
    
    return answer;
}

/*
#include <queue>
#include <map>
using namespace std;

int nr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int nc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

map<pair<int, int>, bool> visited;
map<pair<pair<int, int>, pair<int, int>>, bool> edgeCheck; 

int solution(vector<int> arrows) {

    int answer = 0;

    int curR = 0;
    int curC = 0;
    visited[{curR, curC}] = true;

    for (int i = 0; i < arrows.size(); ++i) {

        int curArrow = arrows[i];

        for (int moveTime = 0; moveTime < 2; ++moveTime) {

            int nxtR = curR + nr[curArrow];
            int nxtC = curC + nc[curArrow];

            if (visited[{nxtR, nxtC}] == true && edgeCheck[{ {curR, curC}, { nxtR, nxtC }}] == false)
                ++answer;
               

            edgeCheck[{ { curR, curC }, { nxtR, nxtC }}] = true;
            edgeCheck[{ { nxtR, nxtC }, { curR, curC }}] = true;

            visited[{curR, curC}] = true;   
            curR = nxtR;
            curC = nxtC;
        }
    }

    return answer;
}
*/