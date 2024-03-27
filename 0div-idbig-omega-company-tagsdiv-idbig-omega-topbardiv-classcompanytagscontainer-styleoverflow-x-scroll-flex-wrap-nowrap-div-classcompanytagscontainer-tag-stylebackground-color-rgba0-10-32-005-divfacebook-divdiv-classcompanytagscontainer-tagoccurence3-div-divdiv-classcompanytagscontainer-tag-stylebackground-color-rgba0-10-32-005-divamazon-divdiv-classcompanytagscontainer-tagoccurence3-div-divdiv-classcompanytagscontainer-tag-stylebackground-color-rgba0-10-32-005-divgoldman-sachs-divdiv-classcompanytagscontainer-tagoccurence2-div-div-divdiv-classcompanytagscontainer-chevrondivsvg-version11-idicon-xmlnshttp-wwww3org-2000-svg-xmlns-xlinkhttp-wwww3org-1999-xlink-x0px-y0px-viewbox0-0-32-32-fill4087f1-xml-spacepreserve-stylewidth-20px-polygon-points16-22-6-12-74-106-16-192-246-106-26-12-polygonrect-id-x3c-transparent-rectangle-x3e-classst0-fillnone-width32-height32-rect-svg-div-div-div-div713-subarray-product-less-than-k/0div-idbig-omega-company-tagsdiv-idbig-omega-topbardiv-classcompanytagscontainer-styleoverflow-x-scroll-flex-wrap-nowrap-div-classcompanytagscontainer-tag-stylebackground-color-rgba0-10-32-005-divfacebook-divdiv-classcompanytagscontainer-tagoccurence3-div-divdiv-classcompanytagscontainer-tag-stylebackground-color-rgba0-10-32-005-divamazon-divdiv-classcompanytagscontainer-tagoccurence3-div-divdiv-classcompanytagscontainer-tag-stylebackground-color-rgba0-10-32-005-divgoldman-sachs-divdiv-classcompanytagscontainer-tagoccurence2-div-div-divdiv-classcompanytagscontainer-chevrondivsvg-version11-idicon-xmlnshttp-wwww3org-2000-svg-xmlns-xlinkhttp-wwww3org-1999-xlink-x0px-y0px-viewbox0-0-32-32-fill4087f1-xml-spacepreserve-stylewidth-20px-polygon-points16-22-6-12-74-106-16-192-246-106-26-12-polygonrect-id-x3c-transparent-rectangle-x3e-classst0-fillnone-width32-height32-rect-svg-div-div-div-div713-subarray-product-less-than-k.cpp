class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) { 
        int n = nums.size();
        
        if( k <= 1) return 0;
        
        int l = 0;
        int r=0;
        
        int count = 0;
        int product = 1;
        
        while( r < n){
            product *= nums[r];
            while( product >= k){
                product /= nums[l];
                l++;
            }
            count += (r-l+1);
             r++;  
        }
        

        return count;
        
    }
};

