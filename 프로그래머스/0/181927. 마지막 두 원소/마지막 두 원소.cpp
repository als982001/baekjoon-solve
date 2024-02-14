#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    answer = num_list;
    
    int lastItem = num_list[num_list.size() - 1];
    int befLastItem = num_list[num_list.size() - 2];
    
    if (lastItem > befLastItem)
        answer.push_back(lastItem - befLastItem);
    else
        answer.push_back(lastItem * 2);
    
    return answer;
}