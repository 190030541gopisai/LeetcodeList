class Solution {
    
    void dfs(int i, int N, vector<vector<int>>& isConnected, vector<bool> &visited){
        visited[i] = true;
        for(int j = 0; j < N; j++){
            if(isConnected[i][j] && !visited[j]){
                dfs(j, N, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<bool> visited(N, false);
        int count_provinces = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(isConnected[i][j] && !visited[i]){
                    dfs(i, N, isConnected, visited);
                    count_provinces++;
                }
            }
        }
        
        return count_provinces;
    }
};