class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;

        for (int i = 1; i <= n; i++) {
            int sum = getDigitSum(i);
            mp[sum]++;
        }

        int maxSize = 0;
        for (auto &p : mp) {
            maxSize = max(maxSize, p.second);
        }

        int count = 0;
        for (auto &p : mp) {
            if (p.second == maxSize)
                count++;
        }

        return count;
    }
};