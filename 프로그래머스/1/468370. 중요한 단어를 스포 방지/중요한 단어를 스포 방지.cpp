#include <string>
#include <vector>

#define MAX 20002

using namespace std;

struct WordInfo 
{
    int startIdx;
    int endIdx;
    int wordIdx;
    string word;
    bool isRevealed; // 드러나있는 단어인지
    int hiddenCount; // 이 단어를 가리고 있는 스포일러 구간의 개수
};

vector<WordInfo> wordInfos;
int wordsIdxes[MAX]; // message에서 어떤 단어가 포함된 index인지

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    
    for (int i = 0; i < MAX; ++i)
        wordsIdxes[i] = -1;
    
    string word = "";
    int lastWordIdx = 0;
    int startIdx = 0;
    
    for (int i = 0; i < message.size(); ++i)
    {
        if (message[i] == ' ')
        {
            WordInfo wordInfo = { startIdx, i - 1, lastWordIdx, word, true };
            wordInfos.push_back(wordInfo);
            
            for (int k = startIdx; k < i; ++k)
                wordsIdxes[k] = lastWordIdx;
            
            word = "";
            ++lastWordIdx;
            startIdx = i + 1;
        }
        else
            word += message[i];
    }
    
    if (word.size() > 0)
    {
        WordInfo wordInfo = { startIdx, (int)message.size() - 1, lastWordIdx, word, true };
        
        wordInfos.push_back(wordInfo);
        
        for (int i = startIdx; i < message.size(); ++i)
            wordsIdxes[i] = lastWordIdx;
    }
    
    /*
    for (WordInfo wordInfo : wordInfos) 
        cout << wordInfo.word << " => " << wordInfo.startIdx << " ~ " << wordInfo.endIdx << endl;
    */
    
    // 스포 방지를 위해 가린다.
    for (vector<int> spoilerRange : spoiler_ranges)
    {
        int spoStartIdx = spoilerRange[0];
        int spoEndIdx = spoilerRange[1];
        int spoIdx = spoStartIdx;
        
        vector<int> spoWordIdxes;
        
        while(spoIdx <= spoEndIdx)
        {
            if (wordsIdxes[spoIdx] == -1)
                ++spoIdx;
            else
            {
                WordInfo spoWord = wordInfos[wordsIdxes[spoIdx]];
                spoWordIdxes.push_back(spoWord.wordIdx);
                
                spoIdx = spoWord.endIdx + 2;
            }
        }
    
        for (int spoWordIdx : spoWordIdxes)
        {
            wordInfos[spoWordIdx].isRevealed = false; // 스포 방지를 위해 가려졌음을 표시
            wordInfos[spoWordIdx].hiddenCount++; // 이 단어가 가려진 구간 개수를 누적
        }
    }
    
    // 이제는 중요한 단어인지 확인한다.
    for (vector<int> spoilerRange : spoiler_ranges)
    {
        int spoStartIdx = spoilerRange[0];
        int spoEndIdx = spoilerRange[1];
        int spoIdx = spoStartIdx;
        
        vector<WordInfo> spoWords;
        
        while(spoIdx <= spoEndIdx)
        {
            if (wordsIdxes[spoIdx] == -1)
                ++spoIdx;
            else
            {
                WordInfo spoWord = wordInfos[wordsIdxes[spoIdx]];
                
                // 스포일러 클릭했으므로 해당 단어 덮고 있던 가림막 하나 제거
                wordInfos[spoWord.wordIdx].hiddenCount--;
                
                // 이 클릭으로 인해 가림막이 0개가 되어 완전히 다 드러났을 때만 평가 대상에 넣는다
                if (wordInfos[spoWord.wordIdx].hiddenCount == 0)
                    spoWords.push_back(wordInfos[spoWord.wordIdx]);
                
                spoIdx = spoWord.endIdx + 2;
            }
        }
    
        for (int s = 0; s < spoWords.size(); ++s)
        {
            // 단어가 스포 방지 해제되었음
            wordInfos[spoWords[s].wordIdx].isRevealed = true;
            
            WordInfo spoWord = wordInfos[spoWords[s].wordIdx];
            
            // spoEndIdx 이후로 드러난 단어가 있는지
            bool isImportant = true;
            
            for (int k = 0; k <= lastWordIdx; ++k)
            {
                WordInfo wordInfo = wordInfos[k];
                
                bool isCurrentWord = wordInfo.wordIdx == spoWord.wordIdx; // 현재 단어인지
                bool isSameWord = wordInfo.word == spoWord.word; // 현재 단어랑 같은 단어인지
                bool isRevealdWord = wordInfo.isRevealed; // 스포 방지가 해제되어 보이는 단어인지
                
                // 자기 자신이 아니면서, 단어가 같으면서, 보이는 단어인 경우 => 중요한 단어가 아님
                if (!isCurrentWord && isSameWord && isRevealdWord)
                {
                    isImportant = false;
                    break;
                }
            }
            
            if (isImportant)
                ++answer;
        }
    }
    
    return answer;
}