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
    // 当nums 长度小于5 时, 改变三个数字, 差值最小一定为0.
    if (n < 5) { return 0;}
    std::sort(nums.begin(), nums.end());
    int ret = INT_MAX;
    // 排序后, 在最大的三个和最小的三个中寻找找差值最小的, 即为整个数组差值最小的.
    /* 
    [
        [1,2,2,3]
        [4,6,7,8]
    ]
    在一个有序二维数组中, 同一列求差, 肯定是最小的. 不需要遍历两个数组.
    */
    for (int i = 0; i < 4; i++) {
        ret = std::min(ret, nums[n - 4 + i] - nums[i]);
    }

    return ret;
}
