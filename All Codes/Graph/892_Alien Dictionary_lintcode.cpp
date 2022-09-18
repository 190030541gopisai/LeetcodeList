// 892 · Alien Dictionary
// lintcode
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        int N = words.size();
        map<char, vector<char>> gr;
        unordered_map<char, int> indegre;

        for(int i = 0; i < N; i++){
            for(auto &c: words[i]){
                vector<char> temp;
                gr[c] = temp;
                indegre[c] = 0;
            }
        }

        for(int i = 1; i < N; i++){
            string s1 = words[i-1], s2 = words[i];
            if(s1.length() > s2.length()){
                bool flag = false;
                for(int j = 0; j < s2.length(); j++){
                    if(s1[j] != s2[j]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    return "";
                }
            }
            for(int j = 0; j < min(s1.length(), s2.length()); j++){
                if(s1[j] != s2[j]){
                    gr[s1[j]].push_back(s2[j]);
                    indegre[s2[j]]++;
                    break;
                }
            }
        }

        priority_queue<char, vector<char>, greater<char>> q;

        for(auto &it: gr){
            char key = it.first;
            if(indegre.count(key) && indegre[key] == 0){
                q.push(key);
            }
        }

        string ans = "";
        int count = 0;
        while(!q.empty()){
            char cur = q.top();
            q.pop();
            count++;
            ans += cur;
            for(auto &nbr : gr[cur]){
                indegre[nbr]--;
                if(indegre[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(count != gr.size()){
            return "";
        }   
        return ans;
    }
};

int main(){
    // {"wrt","wrf","er","ett","rftt"};
    vector<string> words = {"w", "w", "xyz"};
    Solution s;
    cout << s.alienOrder(words) << endl;
}