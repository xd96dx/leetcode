/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=21912
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t length = nums.size();
        if (length < 1) {
            return -1;
        }
        if (length == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int index = 0;
        if (nums[0] > target) {
            index = length - 1; 
        }

        if (index) {
            for (; index > 0; index--) {
                if (nums[index] == target) {
                    return index;
                }
            }
        } else {
            for (; index < length; index++) {
                if (nums[index] == target) {
                    return index;
                }
            }
        }
        return -1;
    }
};
