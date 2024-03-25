class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result;
        
        for( int ind=0; ind<n; ind++ ){
            int num =  abs(nums[ind]);
            int idx = num -1;
            if( nums[idx] < 0 ){
                result.push_back( num);
            }else{
                nums[idx] *= -1;
            }
        }
        
        return result;
    }
};