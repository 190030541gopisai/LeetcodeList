class Solution {
    
public:
    string frequencySort(string s) {
        int count[256] = {0};
        for(char ch: s){
            count[ch]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) -> bool{
            return (count[a] > count[b]) || (count[a] == count[b] && a < b);
        });
        return s;
    }
};

/*


class Solution {
    static bool cmp(pair<int, char> &a, pair<int, char> &b){
        return a.first > b.first;
    }
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for(auto ch: s){
            count[ch]++;
        }
        vector<pair<int, char>> arr;
        for(auto it: count){
            arr.push_back({it.second, it.first});
        }
        sort(arr.begin(), arr.end(), cmp);
        string ans;
        for(int i = 0; i < arr.size(); i++){
            int c = arr[i].first;
            char ch = arr[i].second;
            while(c-- > 0){
                ans += ch;
            }
        }
        return ans;
    }
};
*/