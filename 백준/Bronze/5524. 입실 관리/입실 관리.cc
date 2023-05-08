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
string name;
vector<string> answer;

int main()
{
    cin >> N;
	
    for (int n = 0; n < N; ++n)
    {
        cin >> name;
            
        for (int i = 0; i < name.size(); ++i)
        {
            if ('A' <= name[i] && name[i] <= 'Z')
                name[i] = (name[i] - 'A') + 'a';
        }

        answer.push_back(name);
    }

    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << endl;


    return 0;
}
