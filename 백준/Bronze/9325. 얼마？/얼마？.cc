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

int T;
int price, totalOptionNum, optionNum, optionPrice;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        cin >> price;

        cin >> totalOptionNum;

        for (int i = 0; i < totalOptionNum; ++i)
        {
            cin >> optionNum >> optionPrice;

            price += (optionNum * optionPrice);
        }

        answer.push_back(price);
    }

    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << endl;

    return 0;
}
