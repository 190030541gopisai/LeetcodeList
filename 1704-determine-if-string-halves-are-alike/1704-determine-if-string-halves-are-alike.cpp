class Solution {
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    bool halvesAreAlike(string s) {
        int N = s.size();
        int c = 0, mid = N/2;
        for(int i = 0; i < mid; i++){
            c += isVowel(s[i]);
            c -= isVowel(s[i+mid]);
        }
        return (c == 0);
    }
};


/*
// TC = O(N)
// SC = O(1)
#include <algorithm>
class Solution {
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int countVowels(string s, int low, int high){
        int ans = 0;
        for(int i = low; i <= high; i++){
            ans += isVowel(s[i]);
        }
        return ans;
    }
public:
    bool halvesAreAlike(string s) {
        int N = s.size();
        int mid = N / 2;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int c1 = countVowels(s, 0, mid - 1);
        int c2 = countVowels(s, mid, N-1);
        return c1 == c2;
    }
};
*/