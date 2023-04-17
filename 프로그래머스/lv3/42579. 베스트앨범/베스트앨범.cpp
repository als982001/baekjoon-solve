#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

vector<string> genreList;
priority_queue<pair<int, string>> sortedGenres;
map<string, int> playCount;
map<string, priority_queue<pair<int, int>>> songsByGenre;

void Record(string genre, int play, int idx)
{
    songsByGenre[genre].push({ -play, idx });
    
    if (songsByGenre[genre].size() > 2)
        songsByGenre[genre].pop();
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int idx = 0; idx < genres.size(); ++idx)
    {
        string genre = genres[idx];
        int play = plays[idx];
        
        if (playCount[genre] == 0)
        {
            playCount[genre] = play;
            genreList.push_back(genre);
        }
        else
            playCount[genre] += play;
        
        Record(genre, play, idx);
    }
    
    for (int i = 0; i < genreList.size(); ++i)
    {
        string genre = genreList[i];
        int totalPlay = playCount[genre];
        
        sortedGenres.push({ totalPlay, genre });
    }
    
    while(!sortedGenres.empty())
    {
        string genre = sortedGenres.top().second;
        sortedGenres.pop();
        
        stack<int> songIndexes;
        
        while(!songsByGenre[genre].empty())
        {
            songIndexes.push(songsByGenre[genre].top().second);
            songsByGenre[genre].pop();
        }
        
        while(!songIndexes.empty())
        {
            answer.push_back(songIndexes.top());
            songIndexes.pop();
        }
    }
    
    return answer;
}