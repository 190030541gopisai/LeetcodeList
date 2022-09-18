//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool checkHelper(int u, int count, bool *visited, list<int> *gr, int N){
        if(count == N){
            return true;
        }
        visited[u] = true;
        for(auto v: gr[u]){
            if(!visited[v]){
                if(checkHelper(v, count+1, visited, gr, N)){
                    return true;
                }
            }
        }
        visited[u] = false;
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        list<int> gr[N+1];
        for(int i = 0; i < M; i++){
            int u = Edges[i][0];
            int v = Edges[i][1];
            
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        bool visited[N+1];
        for(int i = 1; i <= N; i++){
            if(checkHelper(i, 1, visited, gr, N)){
                return true;
            }
        }
        return false;
        
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends