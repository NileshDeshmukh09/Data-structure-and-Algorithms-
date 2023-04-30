//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       map<char , int>mp;
       queue<char>q;
       
       int n = S.length();
       for( int i=0; i<n; i++ ){;
           q.push( S[i] );
           mp[S[i]]++;
       }
       
       
           
           while(!q.empty() ){
               
                char val = q.front();
                q.pop();
                if( (mp.find(val) != mp.end() ) && (mp[val] == 1) )return val;
           }
       
       return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends