class Solution {
    public int specialArray(int[] nums) {
        
        int n = nums.length;
        
        int x = -1;
        
         Map<String, Integer> mp = new HashMap<>();
        
        for( int i=0; i<=n; i++){
            int count =0;
            for( int j=0; j<n; j++){   
                if( nums[j] >= i ) count++;
         }
            
            if( count == i ) x= i;
        }
        
        
        return x;
        
    }
}