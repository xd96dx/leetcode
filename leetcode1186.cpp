/*
1186. 删除一次得到子数组最大和
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。

 

示例 1：

输入：arr = [1,-2,0,3]
输出：4
解释：我们可以选出 [1, -2, 0, 3]，然后删掉 -2，这样得到 [1, 0, 3]，和最大。
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

int maximumSum(std::vector<int>& arr) {
    int size = arr.size();
    int dp1, dp2; // dp1 表示不删除元素, dp2 表示删除元素
    dp1 = arr[0];
    dp2 = 0;
    int res = arr[0];
    for (int i = 2; i <= size; i ++) {
        int dp = std::max(dp1 + arr[i-1], arr[i-1]);  // max中, 如果 dp 小于1, 则为 arr[i-1], 否则为 arr[i-1] + dp1[i-1]
        // i-1 表示删除arr[i] 这个数, 意味着, 因为dp2 是已经删除的数字的最大值, dp2 和删除 arr[i-1] 相加, 
        // 要么相加之后大, 要么dp1(删除当前元素的和) 大
        int dp_d = std::max(dp2 + arr[i-1], dp1);
        std::cout << dp << " " << dp_d << std::endl;
        res = std::max(res, std::max(dp, dp_d));
        dp2 = dp_d; dp1 = dp;
    }
    return res;
}
