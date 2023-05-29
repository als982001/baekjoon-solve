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

int laptopWidth;
int laptopHeight;
int stickerWidth;
int stickerHeight;
int answer;

int main()
{
    cin >> laptopWidth >> laptopHeight >> stickerWidth >> stickerHeight;

    answer = ((laptopWidth >= stickerWidth + 2) && (laptopHeight >= stickerHeight + 2)) ? 1 : 0;

    cout << answer << endl;

    return 0;
}