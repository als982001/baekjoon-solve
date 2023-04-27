#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#include <map>
#pragma warning(disable:4996)

using namespace std;


int N;
int agreememt;
int opposition;
int abstention;

int main()
{
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int v;
        cin >> v;

        switch(v){
            case 1:
                ++agreememt;
                break;
            case -1:
                ++opposition;
                break;
            case 0:
                ++abstention;
                break;
        }
    }
    
    if (abstention * 2 >= N)
        cout << "INVALID" << endl;
    else if (agreememt > opposition)
        cout << "APPROVED" << endl;
    else 
        cout << "REJECTED" << endl;

}
