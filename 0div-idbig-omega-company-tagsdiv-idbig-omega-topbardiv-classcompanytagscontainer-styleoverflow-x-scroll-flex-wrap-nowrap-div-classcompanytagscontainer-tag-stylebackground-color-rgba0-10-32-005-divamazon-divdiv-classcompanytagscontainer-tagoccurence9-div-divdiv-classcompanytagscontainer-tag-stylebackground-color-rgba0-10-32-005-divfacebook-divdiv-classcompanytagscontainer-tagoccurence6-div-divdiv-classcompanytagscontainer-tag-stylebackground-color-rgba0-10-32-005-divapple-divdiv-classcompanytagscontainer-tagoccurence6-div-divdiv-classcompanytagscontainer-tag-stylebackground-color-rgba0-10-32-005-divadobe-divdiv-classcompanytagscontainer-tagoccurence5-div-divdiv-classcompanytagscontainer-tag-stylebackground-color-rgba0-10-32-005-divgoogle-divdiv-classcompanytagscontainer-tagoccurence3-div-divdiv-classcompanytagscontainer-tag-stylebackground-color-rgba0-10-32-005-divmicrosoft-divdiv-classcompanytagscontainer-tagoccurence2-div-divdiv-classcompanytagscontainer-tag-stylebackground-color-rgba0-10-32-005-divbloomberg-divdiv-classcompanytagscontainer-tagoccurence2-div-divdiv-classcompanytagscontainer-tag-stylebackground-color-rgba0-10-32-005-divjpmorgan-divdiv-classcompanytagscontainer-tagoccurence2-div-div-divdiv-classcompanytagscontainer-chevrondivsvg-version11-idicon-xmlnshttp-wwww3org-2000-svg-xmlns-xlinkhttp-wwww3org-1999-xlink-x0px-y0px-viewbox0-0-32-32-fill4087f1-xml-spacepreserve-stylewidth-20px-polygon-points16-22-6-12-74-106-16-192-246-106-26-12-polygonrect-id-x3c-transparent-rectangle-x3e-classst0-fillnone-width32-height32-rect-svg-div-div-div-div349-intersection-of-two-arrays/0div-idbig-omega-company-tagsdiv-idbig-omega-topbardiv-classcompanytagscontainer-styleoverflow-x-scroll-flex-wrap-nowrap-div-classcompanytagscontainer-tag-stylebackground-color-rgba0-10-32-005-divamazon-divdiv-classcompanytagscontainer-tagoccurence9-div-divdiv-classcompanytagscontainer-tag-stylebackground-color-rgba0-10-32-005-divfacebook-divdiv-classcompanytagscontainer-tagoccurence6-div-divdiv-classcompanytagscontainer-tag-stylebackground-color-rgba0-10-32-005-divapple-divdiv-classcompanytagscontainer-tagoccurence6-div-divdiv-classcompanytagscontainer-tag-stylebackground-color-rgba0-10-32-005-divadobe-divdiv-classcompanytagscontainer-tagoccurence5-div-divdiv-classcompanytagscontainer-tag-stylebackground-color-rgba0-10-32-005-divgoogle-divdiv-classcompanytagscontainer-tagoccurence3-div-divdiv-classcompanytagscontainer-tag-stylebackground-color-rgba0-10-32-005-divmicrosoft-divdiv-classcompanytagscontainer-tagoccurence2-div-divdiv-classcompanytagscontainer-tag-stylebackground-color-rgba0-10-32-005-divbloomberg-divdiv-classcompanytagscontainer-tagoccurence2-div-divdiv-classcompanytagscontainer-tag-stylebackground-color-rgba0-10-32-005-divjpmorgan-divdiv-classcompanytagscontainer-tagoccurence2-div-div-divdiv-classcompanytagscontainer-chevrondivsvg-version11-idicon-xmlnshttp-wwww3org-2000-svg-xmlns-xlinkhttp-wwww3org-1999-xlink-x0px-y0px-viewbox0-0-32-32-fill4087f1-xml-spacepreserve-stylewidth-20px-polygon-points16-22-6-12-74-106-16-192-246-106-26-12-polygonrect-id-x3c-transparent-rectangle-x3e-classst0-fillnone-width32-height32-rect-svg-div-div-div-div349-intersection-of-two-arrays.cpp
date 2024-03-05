class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> mp;
        vector<int> res;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {
            mp[nums1[i]] = false;
        }

        for (int i = 0; i < m; i++) {
            auto it = mp.find(nums2[i]);
            if (it != mp.end()) {
                it->second = true;
            }
        }

        for ( auto& pair : mp) {
            if (pair.second == true) {
                res.push_back(pair.first);
            }
        }

        return res;
    }
};