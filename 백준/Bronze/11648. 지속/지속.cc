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

int answer = 0;
string num;

int main()
{
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> num;

    while(num.size() > 1)
    {
        ++answer;
        int result = 1;

        for (int i = 0; i < num.size(); ++i)
            result *= (num[i] - '0');

        if (result < 10)
            break;

        num = to_string(result);
    }

    cout << answer << endl;
}
