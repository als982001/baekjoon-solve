#include <string>
#include <vector>

using namespace std;

vector<int> graph;

double Area(int startX, int endX)
{
    int gap = endX - startX;
    
    if (gap == 0)
        return 0.0;
    else if (gap == 1)
    {
        double y1 = graph[startX];
        double y2 = graph[endX];
        
        return (y1 + y2) / 2;
    }
    else
    {
        int midX = (startX + endX) / 2;
        
        return Area(startX, midX) + Area(midX, endX);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    int lastX = 0;
    int y = k;
    
    while(y > 1)
    {
        graph.push_back(y);
        
        if (y % 2 == 0)
            y /= 2;
        else
            y = (y * 3) + 1;
        
        ++lastX;
    }
    
    graph.push_back(y);
    
    for (int i = 0; i < ranges.size(); ++i)
    {
        vector<int> range = ranges[i];
        
        int startX = range[0];
        int endX = lastX + range[1];
        
        if (startX > endX)
            answer.push_back(-1);
        else
        {
            double area = Area(startX, endX);
            answer.push_back(area);
        }
    }
    
    
    return answer;
}