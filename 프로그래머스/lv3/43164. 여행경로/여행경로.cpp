#include <string>
#include <vector>
#define MAX 10000000
#define START "ICN"
using namespace std;

bool used[MAX];
vector<vector<string>> allTickets;
vector<int> ticketsOrder;
vector<string> answer;

bool CanUpdate(vector<string> airports)
{
    if (answer.size() == 0)
        return true;
    
    for (int i = 0; i < answer.size(); ++i)
    {
        if (airports[i] < answer[i])
            return true;
        else if (airports[i] > answer[i])
            return false;
    }
    
    return false;
}

void Check(string airport)
{
    if (ticketsOrder.size() == allTickets.size())
    {
        vector<string> airports;
        
        airports.push_back(START);
        
        for (int i = 0; i < ticketsOrder.size(); ++i)
        {
            int ticket = ticketsOrder[i];
            airports.push_back(allTickets[ticket][1]);
        }
        
        if (CanUpdate(airports))
            answer = airports;
        
        return;
    }
    
    for (int i = 0; i < allTickets.size(); ++i)
    {
        if (used[i] == false)
        {
            vector<string> ticket = allTickets[i];
            string departure = ticket[0];
            string arrival = ticket[1];

            if (airport == departure)
            {
                ticketsOrder.push_back(i);
                used[i] = true;
                
                Check(arrival);
                
                used[i] = false;
                ticketsOrder.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    allTickets = tickets;
    
    for (int i = 0; i < allTickets.size(); ++i)
    {
        if (allTickets[i][0] == START)
        {
            used[i] = true;
            ticketsOrder.push_back(i);
            
            Check(allTickets[i][1]);
            
            ticketsOrder.pop_back();
            used[i] = false;
        }
    }
    
    return answer;
}