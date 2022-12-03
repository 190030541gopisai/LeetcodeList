class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
            int N = arr.size();
            unordered_map<int, int> freq;
            unordered_set<int> lookup;
            
            for (int i = 0; i < N; i++)
            {
                freq[arr[i]]++;
            }
            
            for (pair<const int, int> it: freq)
            {
                int value = it.second;
                lookup.insert(value);
            }
            
            return lookup.size() == freq.size();
    }
};

// ==========================================================
// class Solution
// {
//     public:
//         bool uniqueOccurrences(vector<int> &arr)
//         {
//             int N = arr.size();
//             unordered_map<int, int> freq;
//             unordered_set<int> lookup;
            
//             for (int i = 0; i < N; i++)
//             {
//                 freq[arr[i]]++;
//             }
            
//             for (pair<const int, int> it: freq)
//             {
//                 int value = it.second;
                
//                 if (lookup.find(value) != lookup.end())
//                 {
//                     return false;
//                 }
//                 lookup.insert(value);
//             }
            
//             return true;
//         }
// };