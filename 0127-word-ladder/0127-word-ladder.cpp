class Solution
{

    public:
        int ladderLength(string beginWord, string endWord, vector<string> &wordList)
        {
            int n = beginWord.length();
            int m = endWord.length();
            int wordListSize = wordList.size();
            int level = 0;
            unordered_set<string> visited;
            queue<string> q;
            q.push(beginWord);
            unordered_set<string> myset;
            for(auto word: wordList){
                myset.insert(word);
            }
            
            while (!q.empty())
            {

                int qsize = q.size();
                level++;
                while (qsize-- > 0)
                {
                    string cur = q.front();
                    q.pop();
                    if(cur == endWord){
                        return level;
                    }
                    for (int i = 0; i < n; i++)
                    {
                        string temp = cur;
                        for (char ch = 'a'; ch <= 'z'; ch++)
                        {
                            temp[i] = ch;
                            // for(int k = 0; k < wordListSize; k++){
                            //     if(temp == wordList[k] && !visited[k]){
                            //         visited[k] = true;
                            //         q.push(temp);
                            //     }
                            // }
                            if(myset.find(temp)!=myset.end() && visited.find(temp) == visited.end()){
                                visited.insert(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
            }
            return 0;
        }
};