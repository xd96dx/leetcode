#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
给你一个数组 nums ，每次操作你可以选择 nums 中的任意一个元素并将它改成任意值。

请你返回三次操作后， nums 中最大值与最小值的差的最小值。

示例 1：

输入：nums = [5,3,2,4]
输出：0
解释：将数组 [5,3,2,4] 变成 [2,2,2,2].
最大值与最小值的差为 2-2 = 0 。
*/
int minDifference(std::vector<int>& nums) {
    int n = nums.size();
    if (n < 4) { return 0;}
    std::sort(nums.begin(), nums.end());
    int ret = INT_MAX;
    for (int i = 0; i < 4; i++) {
        ret = std::min(ret, nums[n - 4 + i] - nums[i]);
    }

    return ret;
}
