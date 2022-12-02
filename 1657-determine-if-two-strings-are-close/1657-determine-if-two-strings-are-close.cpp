class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        
        if(N != M){
            return false;
        }
        
        int count1[26] = {0}, count2[26] = {0};
        
        for(int i = 0; i < N; i++){
            count1[word1[i] - 'a']++;
            count2[word2[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(count1[i] != 0 && count2[i] == 0){
                return false;
            }
            else if(count1[i] == 0 && count2[i] != 0){
                return false;
            }
        }
        
        sort(count1, count1 + 26);
        sort(count2, count2 + 26);
        
        for(int i = 0; i < 26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        
        return true;
    }
};

/*

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        
        if(N != M){
            return false;
        }
        
        unordered_map<char, int> count1, count2;
        
        for(int i = 0; i < N; i++){
            count1[word1[i]]++;
            count2[word2[i]]++;
        }
        
        vector<int> values1, values2;
        
        for(auto it: count1){
            if(count2.find(it.first) == count2.end()){
                return false;
            }
            values1.push_back(it.second);
        }
        
        for(auto it: count2){
            if(count1.find(it.first) == count1.end()){
                return false;
            }
            values2.push_back(it.second);
        }
        
        int valSize1 = values1.size();
        int valSize2 = values2.size();
        
        if(valSize1 != valSize2){
            return false;
        }
        
        sort(values1.begin(), values1.end());
        sort(values2.begin(), values2.end());
        
        return (values1 == values2);
    }
};


//  word1 = "cabbba", word2 = "abbccc"
 
//  {
//   c : 1
//   a : 2
//   b : 3
//  }

//  {
//     a: 1
//     b: 2
//     c: 3
//  }
 
//  check the values of two maps are equal or not


*/