class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        mp[0] = -1;  // Empty prefix ka index

        int sum = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {

            // 1 -> +1, 0 -> -1
            if (nums[i] == 1)
                sum++;
            else
                sum--;

            if (mp.find(sum) != mp.end()) {
                // Same prefix sum mila
                maxi = max(maxi, i - mp[sum]);
            }
            else {
                // Sirf first occurrence store karo
                mp[sum] = i;
            }
        }

        return maxi;
    }
};