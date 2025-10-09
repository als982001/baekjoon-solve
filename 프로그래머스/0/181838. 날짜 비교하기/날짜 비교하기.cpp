#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    for (int i = 0; i < 3; ++i) 
    {
        if (date1[i] < date2[i])
            return 1;  
        if (date1[i] > date2[i]) 
            return 0;      
    }
    
    return 0; // 연-월-일 모두 동일
}