/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 * @lcpr version=21912
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int min_prev = numeric_limits<int>::max();
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        min_prev = min(min_prev, dp[i-1][k]);
                    }
                }
                dp[i][j] = grid[i][j] + min_prev;
            }
        }
        
        int ret = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            ret = min(dp[n-1][i], ret);
        }

        return ret;
    }
};
