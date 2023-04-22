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

/*
#include <string>
#include <vector>

using namespace std;

void Swap(int& a, int& b) {

    int temp = a;
    a = b;
    b = temp;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int maxHorizontal = (brown - 6) / 2;

    for (int horizontal = 1; horizontal <= maxHorizontal; ++horizontal) {

        int vertical = (brown - 4 - (2 * horizontal)) / 2;
        
        if (horizontal * vertical == yellow) {

            if (vertical > horizontal)
                Swap(vertical, horizontal);

            answer.push_back(horizontal + 2);
            answer.push_back(vertical + 2);

            return answer;
        }
    }
}
*/