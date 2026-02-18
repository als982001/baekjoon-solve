#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> room;

long long GetEmptyRoom(long long roomNumber)
{
    if (room[roomNumber] == 0)
    {
        room[roomNumber] = roomNumber + 1;
        return roomNumber;
    }
    
    return room[roomNumber] = GetEmptyRoom(room[roomNumber]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for (long long roomNumber : room_number)
    {
        long long emptyRoom = GetEmptyRoom(roomNumber);
        answer.push_back(emptyRoom);
    }
        
    return answer;
}