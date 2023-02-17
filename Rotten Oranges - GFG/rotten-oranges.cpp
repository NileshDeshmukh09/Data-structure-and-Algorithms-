//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        // figure out the grid size
        int n =grid.size();
        int m = grid[0].size();
        
        // store in queue {{row,col} , time }
        queue<pair <pair<int , int> , int>> q;
        
        int vis[n][m];
        int cntFresh = 0;
        
        for( int i =0; i<n; i++){
            for( int j = 0; j<m ; j++ ){
                
                // make all the rotten oranges mark visited in visited array 
                // send to queue
                if( grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j]= 2;
                }else{
                    vis[i][j] =0;
                }
                
                //count the fresh oranges
                if( grid[i][j] == 1 ) cntFresh++;
            }
        }
        
        int tm = 0;
        // delta row and delta column
        int drow[] = { -1 , 0 , 1 , 0 };
        int dcol[] = { 0 , 1 , 0 , -1 };
        int cnt = 0;
            
        // bfs traversal ( until the queue becomes empty )
        while( !q.empty() ){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t= q.front().second;
            
            tm = max( tm , t);
            q.pop();
            
            
            // exactly 4 neighbours
            for( int i=0; i<4; i++ ){
             
                    // neighbouring row and column
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];
                    
                    // Check for valid cell and then traverse for unvisited rotten oranges
                    if( nrow>= 0 && nrow< n && ncol>= 0 && ncol<m 
                    && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0 ){
                         q.push({ {nrow , ncol} , t+1 });
                         vis[nrow][ncol] = 2;
                         cnt++;
                    }
                
            }
            
        }
        
        // if all the oranges are not rotten
        if( cnt != cntFresh ) return -1;
        
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends