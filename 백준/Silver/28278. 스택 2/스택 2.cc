#include <iostream>
#include <vector>

using namespace std;

int N, k;
vector<int> v;
vector<int> results;

bool IsStackEmpty()
{
    return v.size() == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int n = 0; n < N; ++n)
    {
        cin >> k;
        
        if (k == 1)
        {
            int x;
            cin >> x;
            
            v.push_back(x);
        }
        
        if (k == 2)
        {
            bool isStackEmpty = IsStackEmpty();
            
            if (isStackEmpty)
            {
                results.push_back(-1);
            }
            else
            {   
                
                int num = v.back();
                v.pop_back();
                
                results.push_back(num);
            }
        }
        
        if (k == 3)
        {
            int numCount = v.size();
            
            results.push_back(numCount);
        }
        
        if (k == 4)
        {
            bool isStackEmpty = IsStackEmpty();
            
            if (isStackEmpty)
            {
                results.push_back(1);
            }
            else
            {
                results.push_back(0);
            }
        }
        
        if (k == 5)
        {
            bool isStackEmpty = IsStackEmpty();
            
            if (isStackEmpty)
            {
                results.push_back(-1);
            }
            else
            {
                results.push_back(v.back());
            }
        }
    }
        
    for (int i = 0; i < results.size(); ++i)
        printf("%d\n", results[i]);

    
    return 0;
}