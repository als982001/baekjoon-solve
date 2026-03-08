#include <string>
#include <vector>

#define MAX 1500001

using namespace std;

int check[MAX];

int solution(vector<vector<int>> signals) {
    int answer = -1;

    for (int t = 0; t < MAX; ++t)
        check[t] = signals.size();
    
    for (vector<int> signal : signals)
    {
        int green = signal[0];
        int yellow = signal[1];
        int red = signal[2];
        
        int yellowStart = green + 1;
        int yellowEnd = yellowStart + yellow - 1;
        
        while(answer == -1 && yellowEnd < MAX)
        {
            for (int t = yellowStart; t <= yellowEnd; ++t)
            {
                --check[t];
                
                if (check[t] == 0)
                {
                    answer = t;
                    break;
                }
            }
            
            yellowStart = yellowEnd + red + green + 1;
            yellowEnd = yellowStart + yellow - 1;
        }
    }

    return answer;
}