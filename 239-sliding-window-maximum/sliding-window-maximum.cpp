class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;  // Stores indices
        vector<int> ans;

        for (int right = 0; right < n; right++) {

            // 1. Remove indices outside the window
            if (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order of values
            while (!dq.empty() &&
                   nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(right);

            // 4. Record maximum once window has size k
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};