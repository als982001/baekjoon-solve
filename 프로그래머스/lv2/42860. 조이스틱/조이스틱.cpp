
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Min(int a, int b){
    return a < b ? a : b;
}
int solution(string name) 
{
    int answer = 0;

    int left = 0;
    int right = 0;
    int shift = name.size() - 1;

    for (int i = 0; i < name.size(); ++i) 
    {
        if (name[i] == 'A') 
        {
            int tmp = i;
            
            while (tmp < name.size() && name[tmp] == 'A')
                ++tmp;

            if (i == 0)
                left = 0;
            else
                left = i - 1;
            right = name.size() - tmp;

            shift = Min(shift, left + right + Min(left, right));
        }
    }
    
    answer += shift;

    for (int i = 0; i < name.size(); ++i)
        answer += Min(name[i] - 'A', 'Z' - name[i] + 1);

    return answer;
}
