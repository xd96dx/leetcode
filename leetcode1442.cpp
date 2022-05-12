#include <iostream>
#include <vector>


/*
1442. 形成两个异或相等数组的三元组数目
给你一个整数数组 arr 。

现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。

a 和 b 定义如下：

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
注意：^ 表示 按位异或 操作。

请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
*/
int countTriplets(std::vector<int>& arr) {
    // 这种方法就是按照给定的逻辑, 硬写, 没啥技巧, 很垃圾...
    // 按照题目给定的i,j,k 的逻辑关系, 写循环即可
    int size = arr.size();
    if (size < 2) {return 0;}
    int num = 0;
    for (int i = 0; i < size; i++) {
        int a = arr[i];
        for (int j = i+1; j < size; j++) {  // 此处题目中给定 i < j
            a ^= arr[j];
            int b = arr[j];
            for (int k = j; k < size; k++) {  // 此处题目中给定 j <= k
                b ^= arr[k];
                if (a == b) {
                    num ++;
                }
            }
        }
    }
    return num;
}
