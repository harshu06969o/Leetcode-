class Solution {
public:
    int minOperations(string s) {
        string dingu = s;
        int n = s.size();
        sort(dingu.begin(), dingu.end());
        if (s.size() == 1 || dingu == s)
            return 0;

        else if (s.size() == 2 && dingu != s)
            return -1;
        if (dingu[0] == s[0] || dingu[s.size() - 1] == s[s.size() - 1])
            return 1;
        else if (dingu[0] == s[n - 1] && dingu[n - 1] == s[0]) {

            if (count(s.begin(), s.end(), s[0]) == 1 &&
                count(s.begin(), s.end(), s[n - 1]) == 1) {
                return 3;
            }

            return 2;
        } else if (dingu[0] != s[0] && dingu[s.size() - 1] != s[s.size() - 1])
            return 2;
        return -1;
    }
};