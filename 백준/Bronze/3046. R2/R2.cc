#include <iostream>

using namespace std;

int R1, S;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> R1 >> S;

	cout << (S * 2) - R1 << endl;
	
	
	return 0;
}

