class UnionFind{
    vector<int> parent, rank;
public:
    UnionFind(int N){
        parent.resize(N+1);
        rank.resize(N+1);
        
        for(int i = 0; i <= N; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
    }
    int findSet(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findSet(parent[node]);
    }   
    void unionSet(int u, int v){
        int s1 = findSet(u);
        int s2 = findSet(v);
        if(rank[s1] < rank[s2]){
            parent[s1] = s2;
        }else if(rank[s1] > rank[s2]){
            parent[s2] = s1;
        }else{
            parent[s1] = s2;
            rank[s1]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        int count_provinces = N;
        UnionFind uf(N);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(isConnected[i][j]){
                    int s1 = uf.findSet(i);
                    int s2 = uf.findSet(j);
                    if(s1!=s2){
                        uf.unionSet(s1, s2);
                        count_provinces--;
                    } 
                }
            }
        }
        
        return count_provinces;
    }
};

/*

//  Tc see in youtube once i did not understand

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

*/