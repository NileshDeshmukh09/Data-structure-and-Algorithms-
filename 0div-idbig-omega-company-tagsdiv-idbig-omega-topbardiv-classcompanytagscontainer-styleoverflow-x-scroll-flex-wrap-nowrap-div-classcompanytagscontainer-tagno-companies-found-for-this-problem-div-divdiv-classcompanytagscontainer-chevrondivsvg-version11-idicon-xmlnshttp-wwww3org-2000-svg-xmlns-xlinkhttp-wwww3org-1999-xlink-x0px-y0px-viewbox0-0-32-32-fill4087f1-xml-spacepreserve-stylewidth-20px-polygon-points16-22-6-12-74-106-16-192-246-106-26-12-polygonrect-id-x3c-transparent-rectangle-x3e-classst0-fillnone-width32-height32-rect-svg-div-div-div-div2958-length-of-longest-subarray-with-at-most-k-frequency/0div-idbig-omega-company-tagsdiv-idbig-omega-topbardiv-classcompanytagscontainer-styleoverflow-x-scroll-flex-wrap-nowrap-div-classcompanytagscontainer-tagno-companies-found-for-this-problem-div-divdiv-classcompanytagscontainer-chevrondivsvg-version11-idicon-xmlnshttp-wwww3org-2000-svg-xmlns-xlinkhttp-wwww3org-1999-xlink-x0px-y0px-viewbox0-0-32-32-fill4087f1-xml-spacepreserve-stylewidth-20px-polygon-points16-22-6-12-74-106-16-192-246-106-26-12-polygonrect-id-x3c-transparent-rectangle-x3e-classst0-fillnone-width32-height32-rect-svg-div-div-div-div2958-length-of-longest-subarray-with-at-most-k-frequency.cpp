class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i=0; 
        int j=0;
        
        int maxLen = 0;
        
        unordered_map<int, int> mp;
        
        while( j<n ){
            
            mp[nums[j]]++;
            
            while( i<j && ( mp[nums[j]] > k)){
                mp[nums[i]]--;
                i++;
                
            }
            
            maxLen= max( maxLen , ( j-i+1));
            j++;
            
        }
        
        return maxLen;
    }
};