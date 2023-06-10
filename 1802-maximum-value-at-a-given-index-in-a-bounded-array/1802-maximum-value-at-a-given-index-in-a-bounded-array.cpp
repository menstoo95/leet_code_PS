class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum;
        
        while (left < right) {
            int mid = (left + right + 1) / 2;
            
            if (test(n, index, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }

    long long test(int n, int index, int target) {
        int b = max(target - index, 0);
        long long res = (long long)(target + b) * (target - b + 1) / 2;
        b = max(target - ((n - 1) - index), 0);
        res += (long long)(target + b) * (target - b + 1) / 2;
        
        return res - target;
    }
};