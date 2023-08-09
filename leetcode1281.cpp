/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 * @lcpr version=21912
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        std::vector<int> v;
        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }

        int mul = 1;
        for (auto num : v)
            mul *= num;

        int sum = 0;
        for (auto num : v)
            sum += num;
        
        return mul - sum;
    }
};
