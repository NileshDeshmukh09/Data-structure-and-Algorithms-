class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0;
        int maxCnt = 0;
        
        for( int i=0; i < n; i++ ){
            if( s[i] == '('){
                cnt++;
                if( maxCnt < cnt ) maxCnt = cnt;
                
            }else if( s[i] == ')'){
                cnt--;
                
            }
            
            // cout << cnt << endl;
            
            
        }
      return maxCnt;   
    }
};
    