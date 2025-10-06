#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    string evenNumbers = "";
    string oddNumbers = "";
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        int num = num_list[i];
        
        if (num % 2 == 0)
            evenNumbers = evenNumbers += to_string(num);
        else
            oddNumbers = oddNumbers += to_string(num);
    }
    
    int evenNumber = evenNumbers == "" ? 0 : stoi(evenNumbers);
    int oddNumber = oddNumbers == "" ? 0 : stoi(oddNumbers);
    
    answer = evenNumber + oddNumber;
    
    return answer;
}