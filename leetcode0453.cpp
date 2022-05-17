/*
453. 最小操作次数使数组元素相等
给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

// n-1 个数加1, 就是最大的那个数减1, 每个数要挨个往最小的那个减, 循环每个数减到最小值的差值相加, 就ok了
int minMoves(std::vector<int>& nums) {
    int minNum = *std::min_element(nums.begin(),nums.end());
    int res = 0;
    for (int num : nums) {
        res += num - minNum;
    }
    return res;
}

int main() {
    std::vector<int> v = {1, 2, 3};
    std::cout << minMoves(v);
}