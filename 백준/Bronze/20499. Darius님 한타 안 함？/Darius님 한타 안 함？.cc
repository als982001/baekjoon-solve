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

string KDA;
int K, D, A;

vector<string> Split(string str)
{
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while(getline(iss, buffer, '/')) {
        result.push_back(buffer);
    }

    return result;
}

int main()
{
    cin >> KDA;

    vector<string> result = Split(KDA);
    
    K = stoi(result[0]);
    D = stoi(result[1]);
    A = stoi(result[2]);

    if (D == 0 || K + A < D)
        cout << "hasu" << endl;
    else
        cout << "gosu" << endl;
	
    return 0;
}
