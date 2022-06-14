/*
1157. 子数组中占绝大多数的元素
设计一个数据结构，有效地找到给定子数组的 多数元素 。

子数组的 多数元素 是在子数组中出现 threshold 次数或次数以上的元素。

实现 MajorityChecker 类:

MajorityChecker(int[] arr) 会用给定的数组 arr 对 MajorityChecker 初始化。
int query(int left, int right, int threshold) 返回子数组中的元素  arr[left...right] 至少出现 threshold 次数，如果不存在这样的元素则返回 -1。
*/

// 有问题 慢的一比 暂时没时间看了 先搁到这 后续优化

#include <iostream>
#include <unordered_map>
#include <vector>

class MajorityChecker {
public:
    MajorityChecker(std::vector<int>& arr) {
        iner_array = arr;
    }

    int query(int left, int right, int threshold) {
        std::unordered_map<int, int> m;
        for (int i = left; i < right; i++) {
            int key = iner_array[i];
            m[key]++;
            if (m[key] >= threshold) 
                return key;
        }
        for (auto& k : m) {
            if (k.second >= threshold) 
                return k.first;
        }
        return -1;
    }

    std::vector<int> iner_array;
};
