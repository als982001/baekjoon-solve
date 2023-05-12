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

int age, weight;
string input;
string name, strAge, strWeight;
vector<string> answer;

int main()
{
   while(true)
   {
        getline(cin, input);

        istringstream info(input);

        info >> name >> strAge >> strWeight;

        if (name == "#")
            break;
        
        age = stoi(strAge);
        weight = stoi(strWeight);

        if (age > 17 || weight >= 80)
            answer.push_back(name + " Senior");
        else
            answer.push_back(name + " Junior");
   }

   for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << endl;

    
}
