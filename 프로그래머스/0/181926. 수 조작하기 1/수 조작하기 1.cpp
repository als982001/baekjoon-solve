#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = 0;
    
    for (int i = 0; i < control.size(); ++i)
    {
        char letter = control[i];
        
        switch(letter) 
        {
            case 'w':
                ++n;
                break;
            case 's':
                --n;
                break;
            case 'd':
                n += 10;
                break;
            case 'a':
                n -= 10;
                break;
        }               
    }
    
    answer = n;
    
    return answer;
}