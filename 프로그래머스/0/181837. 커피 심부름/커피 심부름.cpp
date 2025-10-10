#include <string>
#include <vector>

using namespace std;

int GetCoffeeCost(string coffee)
{
    if (coffee == "anything" || coffee.find("americano") != string::npos)
        return 4500;
    if (coffee.find("cafelatte") != string::npos)
        return 5000;
    return 0;
}

int solution(vector<string> order) {
    int answer = 0;
    
    for (int i = 0; i < order.size(); ++i)
    {
        string coffee = order[i];
        
        answer += GetCoffeeCost(coffee);
    }
    
    return answer;
}