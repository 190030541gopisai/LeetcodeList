class Solution {
    vector<int> parent;
    vector<int> rank;

    int findSet(int vertex){
        if(parent[vertex] == -1){
            return vertex;
        }
        return parent[vertex] = findSet(parent[vertex]);
    }

    void unionSet(int u, int v){
        int s1 = findSet(u);
        int s2 = findSet(v);

        if(rank[s1] > rank[s2]){
            parent[s2] = s1;
        }else if(rank[s2] > rank[s1]){
            parent[s1] = s2;
        }else{
            parent[s2] = s1;
            rank[s1]++;
        }
    }
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        
        parent.resize(n, -1);
        rank.resize(n, 0);

       if(edges.size() == 0){
           return n == 1;
       }
       unordered_set<int> uniqueNodes;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            uniqueNodes.insert(u);
            uniqueNodes.insert(v);
            int s1 = findSet(u);
            int s2 = findSet(v);

            if(s1 != s2){
                unionSet(u, v);
            }else{
                return false;
            }
        }
        return uniqueNodes.size() == n;
    }
};





===========================================================================

--using directed cycle detection

class Solution {
    unordered_set<int> visit;
    vector<vector<int>> gr;
    bool dfs(int cur, int par){
        if(visit.count(cur)){
            return false;
        }
        visit.insert(cur);
        for(auto &nbr: gr[cur]){
            if(nbr != par){
                if(dfs(nbr, cur) == false){
                    return false;
                }
            }
        }
        return true;
    }
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        visit.clear();
        gr.resize(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        return dfs(0, -1) && visit.size() == n;
    }
};