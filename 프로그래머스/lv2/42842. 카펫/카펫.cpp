#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    for (int height = 1; height * height <= yellow; ++height)
    {
        if (yellow % height != 0)
            continue;
        int width = yellow / height;
        
        int currentBrown = (width * 2) + (height * 2) + 4;
        
        if (currentBrown == brown)
            return { width + 2, height + 2 };
    }
}