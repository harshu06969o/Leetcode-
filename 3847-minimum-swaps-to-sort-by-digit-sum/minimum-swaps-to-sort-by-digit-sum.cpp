
class Solution {
public:
    int findo(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({{findo(nums[i]), nums[i]}, i});
        }

        sort(arr.begin(), arr.end());

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || arr[i].second == i)
                continue;

            int j = i;
            int cycle = 0;

            while (!vis[j]) {
                vis[j] = 1;
                j = arr[j].second;
                cycle++;
            }

            if (cycle > 1)
                cnt += cycle - 1;
        }

        return cnt;
    }
};
