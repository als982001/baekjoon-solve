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

int N, W, H, L;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> N >> W >> H >> L;
   
    answer = min((W / L) * (H / L), N);

    cout << answer << endl;

    return 0;
}
