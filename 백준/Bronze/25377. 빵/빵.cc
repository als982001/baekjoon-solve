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
int arrivalTime, breadTime;
int answer = -1;

int main()
{
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> N;

    for (int n = 0; n < N; ++n)
    {
        cin >> arrivalTime >> breadTime;

        if (arrivalTime <= breadTime)
        {
            if (answer == -1 || answer > breadTime)
                answer = breadTime;
        }
    }   

    cout << answer << endl;

    return 0;
}
