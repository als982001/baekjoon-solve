#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> clothes(n + 2, 1);
    
    for (int l : lost)
        clothes[l] = 0;
    
    for (int r : reserve)
        ++clothes[r];
    
    for (int student = 1; student <= n; ++student)
    {
        if (clothes[student] > 0)
            continue;
        
        int prevStudent = student - 1;
        int nextStudent = student + 1;
        
        if (prevStudent >= 1 && clothes[prevStudent] > 1)
        {
            --clothes[prevStudent];
            ++clothes[student];
        }
        else if (nextStudent <= n && clothes[nextStudent] > 1)
        {
            --clothes[nextStudent];
            ++clothes[student];
        }
    }
    
    for (int student = 1; student <= n; ++student)
    {
        if (clothes[student] > 0)
            ++answer;
    }
    
    return answer;
}