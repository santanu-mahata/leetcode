class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = s.size();

        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> prefixSum(n + 1, 0);
        vector<int> prefixCnt(n + 1, 0);
        vector<long long> prefixNum(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            prefixSum[i] = prefixSum[i - 1] + d;
            prefixCnt[i] = prefixCnt[i - 1] + (d != 0);

            if (d != 0)
                prefixNum[i] = (prefixNum[i - 1] * 10 + d) % MOD;
            else
                prefixNum[i] = prefixNum[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int cnt = prefixCnt[r + 1] - prefixCnt[l];
            int sum = prefixSum[r + 1] - prefixSum[l];

            long long x =
                (prefixNum[r + 1] -
                 prefixNum[l] * pow10[cnt] % MOD +
                 MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};