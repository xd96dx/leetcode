/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=21912
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int right = nums.size()-1;
        int left = 0;

        int start = -1, end = -1;

        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left < nums.size() && nums[left] == target) {
            start = left;
        }

        left = 0, right = nums.size()-1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        std::cout << right << std::endl;
        if (right >= 0 && nums[right] == target) {
            end = right;
        }

        return {start, end};
    }
};
