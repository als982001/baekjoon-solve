#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>

using namespace std;

int x, y, w, h;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> x >> y >> w >> h;
    
    vector<int> diffs(4);
    diffs[0] = x;
    diffs[1] = y;
    diffs[2] = w - x;
    diffs[3] = h - y;
    
    sort(diffs.begin(), diffs.end());
    
    cout << diffs[0] << endl;
	
	return 0;
}