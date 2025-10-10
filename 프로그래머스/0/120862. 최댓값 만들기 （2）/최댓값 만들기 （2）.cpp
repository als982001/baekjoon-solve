#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -100000000;
    
    for (int a = 0; a < numbers.size() - 1; ++a)
    {
        for (int b = a + 1; b < numbers.size(); ++b)
        {
            int result = numbers[a] * numbers[b];
            
            if (answer < result)
                answer = result;
        }
    }
    
    
    return answer;
}