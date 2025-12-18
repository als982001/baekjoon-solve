#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int width = -1;
    int height = -1;
    
    for (vector<int> size : sizes)
    {
        int val1 = size[0] > size[1] ? size[0] : size[1];
        int val2 = size[0] > size[1] ? size[1] : size[0];
        
        if (width < val1)
            width = val1;
        
        if (height < val2)
            height = val2;
    }
    
    answer = width * height;
    
    return answer;
}