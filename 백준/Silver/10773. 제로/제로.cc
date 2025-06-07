#include <iostream>
#include <vector>

using namespace std;

int K, x;
int answer = 0;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> K;
    
    for (int k = 0; k < K; ++k)
    {
        cin >> x;
        
        if (x == 0)
            v.pop_back();
        else
            v.push_back(x);
    }
    
    for (int i = 0; i < v.size(); ++i)
        answer += v[i];
        
    printf("%d\n", answer);
        

    
    return 0;
}