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

long long num;
long long result;
char opt;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> result;
    cin >> opt;

    while(opt != '=')
    {
        cin >> num;
        


        switch(opt) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                result /= num;
                break;
        }

         cin >> opt;           

        if (opt == '=')
            break;   
    }

    cout << result << endl;
   

    return 0;
}
