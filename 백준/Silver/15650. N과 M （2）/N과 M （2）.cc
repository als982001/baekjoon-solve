#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool check[10] = { false, };
int arr[10];

void Solve(int idx, int currentNum)
{
    if (idx == m) 
    {
        for (int i = 0; i < m; ++i)
            printf("%d ", arr[i]);
        
        cout << "\n";
        return;
    }
    
    for (int num = currentNum; num <= n; ++num)
    {
        if (check[num] == false) 
        {
            check[num] = true;
            arr[idx] = num;
            
            Solve(idx + 1, num + 1);
            
            check[num] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    
    Solve(0, 1);
    
    
    return 0;
}