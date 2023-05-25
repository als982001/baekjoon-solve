#include <iostream>
using namespace std;

int card[2];

int main()
{   
    cin >> card[0];
    cin >> card[1];

    cout << (card[0] > card[1] ? card[0] : card[1]) << endl;

    return 0;
}