#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> records;
vector<string> menusSet;

// 단품메뉴들을 course개만큼 전부 조합해서 기록
void Record(string order, string menu, int startIdx, int course)
{
    if (menu.size() == course)
    {
        if (records[menu] == 0)
        {
            records[menu] = 1;
            menusSet.push_back(menu);
        }
        else
            records[menu]++;
        
        return;
    }
    
    for (int idx = startIdx; idx < order.size(); ++idx)
    {
        menu.push_back(order[idx]);
        Record(order, menu, idx + 1, course);
        menu.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> courses) {
    vector<string> answer;
    
    sort(orders.begin(), orders.end());
    
    for (int i = 0; i < orders.size(); ++i)
        sort(orders[i].begin(), orders[i].end());
    
    for (int course : courses)
    {
        records.clear();
        menusSet.clear();
        
        for (string order : orders)
            Record(order, "", 0, course);
        
        int maxRecordCount = -1;
        
        for (string menus : menusSet)
        {
            if (records[menus] > 1 && maxRecordCount < records[menus])
                maxRecordCount = records[menus];
        }
        
        for (string menus : menusSet)
        {
            if (maxRecordCount == records[menus])
                answer.push_back(menus);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}













/*

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> record;
vector<vector<char>> orders;
vector<string> courseMenus;

void Check(string order, string curMenus, int startIdx, int course)
{
    if (curMenus.size() == course)
    {
        if (record[curMenus] == 0)
        {
            record[curMenus] = 1;
            courseMenus.push_back(curMenus);
        }
        else
            ++record[curMenus];
        
        return;
    }
    
    for (int idx = startIdx; idx < order.size(); ++idx)
    {
        curMenus.push_back(order[idx]);
        Check(order, curMenus, idx + 1, course);
        curMenus.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> courses) {
    vector<string> answer;
    
    sort(orders.begin(), orders.end());
    
    for (int i = 0; i < orders.size(); ++i)
        sort(orders[i].begin(), orders[i].end());
    
    for (int course : courses)
    {
        record.clear();
        courseMenus.clear();
        
        for (string order : orders)
        {
            Check(order, "", 0, course);
        }
        
        int maxCount = 0;
        vector<string> maxCountCourseMenus;
        
        for (string courseMenu : courseMenus)
        {
            if (record[courseMenu] > 1 && maxCount < record[courseMenu])
                maxCount = record[courseMenu];
        }
        
        if (maxCount == 0)
            continue;
        
        for (string courseMenu : courseMenus)
        {
            if (maxCount == record[courseMenu])
                maxCountCourseMenus.push_back(courseMenu);
        }
        
        for (auto maxCountCourseMenu : maxCountCourseMenus)
            answer.push_back(maxCountCourseMenu);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

*/