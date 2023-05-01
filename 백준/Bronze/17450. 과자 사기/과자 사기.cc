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

double price, weight;
char snack[3] = { 'S', 'N', 'U' };
priority_queue<pair<double, char>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cout.tie(NULL);

    for (int i = 0; i < 3; ++i)
    {
        cin >> price >> weight;
        
        double totalWeight = weight * 10;
        double totalPrice = (price * 10) >= 5000 ? (price * 10) - 500 : price * 10;
        
        double value = totalWeight / totalPrice;

        pq.push({ value, snack[i] });
    }

    cout << pq.top().second << endl;
    

    return 0;
}
