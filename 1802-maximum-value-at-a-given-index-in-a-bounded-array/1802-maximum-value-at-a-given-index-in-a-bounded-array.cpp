class Solution {
public:
    long getSum(long long mid, int numElements) {
        long long ans = 0, extraOnes = 0;
        if (numElements >= mid) {
            ans = 1;
            extraOnes = numElements - mid;
        } else if (numElements < mid) {
            extraOnes = 0;
            ans = mid - numElements + 1;
        }
        return ((ans + mid) * (mid - ans + 1)) / 2 + extraOnes;
    }
    
    bool isValid(int n, int index, int maxSum, long long mid) {
        long long sum = 0;
        int elementsToLeft = index;
        int elementsToRight = n - index;
        sum += getSum(mid - 1, elementsToLeft);
        sum += getSum(mid, elementsToRight);
        return sum <= maxSum;
    }
    
    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = 2e9;
        while (high - low > 1) {
            long long mid = low + (high - low) / 2;
            if (isValid(n, index, maxSum, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (isValid(n, index, maxSum, high)) {
            return high;
        } else {
            return low;
        }
        return 0;
    }
};