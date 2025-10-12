#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    
    for (int i = 0; i < dic.size(); ++i)
    {
        string word = dic[i];
        
        if (word.size() != spell.size())
            continue;
        
        bool hasAllSpell = true;
        
        for (int k = 0; k < spell.size(); ++k)
        {
            string alp = spell[k];
            
            bool noSpell = (word.find(alp) == string::npos);
            
            if (noSpell)
            {
                hasAllSpell = false;
                break;
            }
        }
        
        if (hasAllSpell)
        {
            answer = 1;
            break;
        }
    }
    
    return answer;
}