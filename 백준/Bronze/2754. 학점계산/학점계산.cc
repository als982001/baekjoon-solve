#include <iostream>
#include <string>
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
// #include <map>
#pragma warning(disable:4996)

using namespace std;

string grade;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> grade;

	if (grade == "A+")
		cout << "4.3" << endl;
	else if (grade == "A0")
		cout << "4.0" << endl;
	else if (grade == "A-")
		cout << "3.7" << endl;
	else if (grade == "B+")
		cout << "3.3" << endl;
	else if (grade == "B0")
		cout << "3.0" << endl;
	else if (grade == "B-")
		cout << "2.7" << endl;
	else if (grade == "C+")
		cout << "2.3" << endl;
	else if (grade == "C0")
		cout << "2.0" << endl;
	else if (grade == "C-")
		cout << "1.7" << endl;
	else if (grade == "D+")
		cout << "1.3" << endl;
	else if (grade == "D0")
		cout << "1.0" << endl;
	else if (grade == "D-")
		cout << "0.7" << endl;
	else if (grade == "F")
		cout << "0.0" << endl;

	return 0;
}
