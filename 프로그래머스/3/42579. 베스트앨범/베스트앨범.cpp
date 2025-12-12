#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>

using namespace std;

vector<string> uniqueGenres;
map<string, int> totalGenrePlayTimes;
map<string, vector<pair<int, int>>> musicPlayTimes;
map<string, int> includedMusicNums;

bool CompareTotalGenrePlayTimes(string a, string b)
{
    int aPlayTimes = totalGenrePlayTimes[a];
    int bPlayTimes = totalGenrePlayTimes[b];
    
    return aPlayTimes > bPlayTimes;
}

bool CompareGenreMusicPlayTimes(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
        return true;
    else if (a.second < b.second)
        return false;
    else
        return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int musicNum = genres.size();
    
    for (int idx = 0; idx < musicNum; ++idx)
    {
        string genre = genres[idx];
        int play = plays[idx];
        
        if (totalGenrePlayTimes[genre] == 0)
        {    
            totalGenrePlayTimes[genre] = play;
            uniqueGenres.push_back(genre);
        }
        else
            totalGenrePlayTimes[genre] += play;
        
        musicPlayTimes[genre].push_back({ idx, play });
    }
    
    // 1. 장르를 장르 재생 횟수 총합 순서에 따라 정렬
    sort(uniqueGenres.begin(), uniqueGenres.end(), CompareTotalGenrePlayTimes);
    
    for (string genre :  uniqueGenres)
    {
        vector<pair<int, int>> genreMusicPlayTimes = musicPlayTimes[genre];
        
        // 2. 많이 재생한 횟수 순서 + 고유 번호 낮은 순서로 정렬
        sort(genreMusicPlayTimes.begin(), genreMusicPlayTimes.end(), CompareGenreMusicPlayTimes);
        
        // 3. 조건에 따라 answer에 저장
        for (int i = 0; i < genreMusicPlayTimes.size(); ++i)
        {
            // 3-1. 이미 장르별 2개 저장되어 있으면 
            if (includedMusicNums[genre] == 2)
                break;
            
            pair<int, int> playInfo = genreMusicPlayTimes[i];
            
            // 3-2. answer에 저장 후 저장 개수 1 증가
            answer.push_back(playInfo.first);
            ++includedMusicNums[genre];
        }
            
    }
    
    return answer;
}