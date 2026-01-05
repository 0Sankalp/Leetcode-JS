#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbs = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (val < 0)
                    negativeCount++;

                int absVal = abs(val);
                totalSum += absVal;
                minAbs = min(minAbs, absVal);
            }
        }

        // If negatives are odd, one smallest absolute value must stay negative
        if (negativeCount % 2 != 0) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }
};
