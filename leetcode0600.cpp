/*
600. 不含连续1的非负整数
给定一个正整数 n ，返回范围在 [0, n] 都非负整数中，其二进制表示不包含 连续的 1 的个数。

 

示例 1:

输入: n = 5
输出: 5
解释: 
下面是带有相应二进制表示的非负整数<= 5：
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。

感觉这个题真的挺难的, 用了一天时间搞完.
*/

#include <iostream>
#include <bitset>
#include <string>

static int F[32];
// 十进制转二进制之后, 有此规律, 保存32位 二进制所有数后, 直接使用
static void f() {
    F[0] = 1;
    F[1] = 2;
    for (int i = 2; i < 32; i++) {
        F[i] = F[i-1] + F[i-2];
    }
}

int findIntergers(int n) {
    f();
    int res = 0;
    int prev = 0;
    int p = 30;  // 32 位二进制中, 30是第31 位, 不从第32 位开始是因为如果数字是 1000 0000 的话, 不能再网上加了, 只用从比它小的 100 0000 开始找.
    while (p >= 0) { // 0100 0000 0000 0000
        if (n & (1 << p) ){
            res += F[p];
            if (prev)   // 当二进制的上一个数和当前数都是1, 则返回, 因为 10101 和 11101 两个数的连续结果是相同的, 没必要继续找下一位
                return res;
            prev = 1;
        }
        else prev = 0;
        --p;
    }
    return res + 1;  // 如果循环完整个二进制位, 再加一个 0.
}

int main() {
    std::cout << findIntergers(100);
    return 0;
}