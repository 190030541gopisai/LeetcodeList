//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<int, int> adj;
    int f(int source, int dest){
        
        bool visited[31];
        memset(visited, false, sizeof(visited) / sizeof(bool));

        queue<int> q;

        int dist[31];
        memset(dist, 0, sizeof(dist)/sizeof(int));
        
        visited[source] = true;
        q.push(source);
        dist[source] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == dest)
            {
                break;
            }
            for(int die = 1; die <= 6; die++){
                int nextJump = die + node;
                
                if(adj.count(nextJump)){
                    nextJump = adj[nextJump];
                }
                
                if(nextJump <= 30 && nextJump>=1){
                    if(!visited[nextJump]){
                        visited[nextJump] = true;
                        q.push(nextJump);
                        dist[nextJump] = dist[node] + 1;
                    }
                }
            }
        }
        return dist[30];
    }
    
    int minThrow(int N, int arr[]){
        // code here
        adj.clear();
        for(int i = 0; i < 2 * N; i+=2){
            adj[arr[i]] = arr[i+1];
        }
        return f(1, 30);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends