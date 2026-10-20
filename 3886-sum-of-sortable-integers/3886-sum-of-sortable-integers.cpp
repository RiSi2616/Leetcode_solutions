class Solution {
public:
    bool isRotation(vector<int>& a, vector<int>& b,
                    int start, int k) {
        vector<int> lps(k, 0);

        // Build LPS for the original block a
        for (int i = 1, len = 0; i < k;) {
            if (a[start + i] == a[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search a block inside b[start..start+k) repeated twice
        int i = 0, j = 0;

        while (i < 2 * k - 1) {
            int value = b[start + i % k];

            if (value == a[start + j]) {
                i++;
                j++;

                if (j == k) return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sortedNums, start, k)) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};