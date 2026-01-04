#include <string>
#include <vector>

#define INIT -1

using namespace std;

string firstAirport = "ICN";
vector<string> answer;

bool CanChangeAnswer(vector<string>& airportsOrder)
{
    if (answer.size() == 0)
        return true;
    
    bool canChange = false;
    
    for (int i = 0; i < airportsOrder.size(); ++i)
    {
        if (answer[i] > airportsOrder[i])
        {
            canChange = true;
            break;
        }
        else if (answer[i] < airportsOrder[i])
        {
            canChange = false;
            break;
        }
    }
    
    return canChange;
}

void Check(vector<vector<string>>& tickets, vector<int>& used, int usedTicketsNum, string airport)
{  
    if (usedTicketsNum == tickets.size())
    {
        vector<string> airportsOrder;
        
        airportsOrder.push_back(firstAirport);
        
        for (int ticketIdx = 0; ticketIdx < tickets.size(); ++ticketIdx)
        {
            for (int u = 0; u < used.size(); ++u)
            {
                if (used[u] == ticketIdx)
                {
                    airportsOrder.push_back(tickets[u][1]);
                }
            }
        }
        
        if (CanChangeAnswer(airportsOrder))
            answer = airportsOrder;
        
        return;
    }
    
    for (int i = 0; i < used.size(); ++i)
    {
        if (used[i] == INIT && tickets[i][0] == airport)
        {
            used[i] = usedTicketsNum;
            Check(tickets, used, usedTicketsNum + 1, tickets[i][1]);
            used[i] = INIT;
            
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<int> used(tickets.size(), INIT);
    
    Check(tickets, used, 0, "ICN");
    
    return answer;
}
















/*

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

*/