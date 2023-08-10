#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int keyCol;
vector<int> sums;

bool Compare(vector<int> a, vector<int> b)
{
    if (a[keyCol] < b[keyCol])
        return true;
    else if (a[keyCol] > b[keyCol])
        return false;
    else
        return a[0] > b[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    col -= 1;
    row_begin -= 1;
    row_end -= 1;
    
    keyCol = col;
    
    sort(data.begin(), data.end(), Compare);
    
    for (int row = row_begin; row <= row_end; ++row)
    {
        int sum = 0;
        
        for (int col = 0; col < data[row].size(); ++col)
        {
            int remainder = data[row][col] % (row + 1);
            sum += remainder;
        }
        
        sums.push_back(sum);
    }
    
    answer = sums[0];
    
    for (int i = 1; i < sums.size(); ++i)
        answer = answer ^ sums[i];
    
    return answer;
}