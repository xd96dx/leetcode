/*
给你一个字符串数组 nums 和一个整数 k 。nums 中的每个字符串都表示一个不含前导零的整数。

返回 nums 中表示第 k 大整数的字符串。

注意：重复的数字在统计时会视为不同元素考虑。例如，如果 nums 是 ["1","2","2"]，那么 "2" 是最大的整数，"2" 是第二大的整数，"1" 是第三大的整数。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

struct comp {
    bool operator() (const std::string k1, const std::string k2) {
        return (k1.size() < k2.size()) || (k1.size() == k2.size() && k1 < k2);
    }
};

// 利用map 的排序性, 写一个 comp 函数来排序就好了
std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
    std::map<std::string, int, comp> m;
    for (auto &s : nums) {
        m[s] = 1;
    }
    for (auto it = m.rbegin(); it != m.rend(); it++) {
        k -= it->second;
        if (k <= 0) {
            return it->first;
        }
    }
    return nums[0];
}

int main() {
    auto v = std::vector<std::string>{"683339452288515879","7846081062003424420","4805719838","4840666580043","83598933472122816064","522940572025909479","615832818268861533","65439878015","499305616484085","97704358112880133","23861207501102","919346676","60618091901581","5914766072","426842450882100996","914353682223943129","97","241413975523149135","8594929955620533","55257775478129","528","5110809","7930848872563942788","758","4","38272299275037314530","9567700","28449892665","2846386557790827231","53222591365177739","703029","3280920242869904137","87236929298425799136","3103886291279"};
    std::cout << kthLargestNumber(v, 3) << std::endl;
    return 0;
}
