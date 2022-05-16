/*
1046. 最后一块石头的重量
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

执行用时：
0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
内存消耗：
7.4 MB, 在所有 C++ 提交中击败了 38.82% 的用户
*/

#include <vector>
#include <algorithm>

int lastStoneWeight(std::vector<int>& stones) {
    int size = stones.size();
    if (size == 0) {
        return 0;
    }
    if (size == 1) {
        return stones[0];
    }
    if (size == 2) {
        return std::abs(stones[0] - stones[1]);
    }
    std::sort(stones.begin(), stones.end());
    int end_ = stones[size-1] - stones[size-2];
    if (end_ == 0) {
        // 数组排序后, 如果最后两个数字相同, 直接删除
        stones.pop_back();
        stones.pop_back();
    } else {
        // 排序后, 如果数组最后两个数字不同, 删除倒数第二个, 并重新赋值给倒数第一个数, 就行了
        stones[size-1] = end_;
        stones.erase(stones.end() - 2);
    }
    // 在此处递归即可
    return lastStoneWeight(stones);
}