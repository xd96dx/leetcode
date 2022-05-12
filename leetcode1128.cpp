#include <unordered_map>
#include <vector>

/*
给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。
*/
int question1128(std::vector<std::vector<int>>& dominoes) {
    std::unordered_map<int, int> map;
    int ret = 0;
    for (auto &v : dominoes) {
        // 将所有[a, b] 型的数组转换成 ab 型的两位数字
        int num = v[0] > v[1] ? v[0] * 10 + v[1] : v[1] * 10 + v[0];
        // 当 map 中有key 值, 则value +1, 没有时则初始化 key 为 1.
        map[num] += 1;
        // 因为初始化的时候, 每个key 都做了 += 1, 导致初始的value值都是 1, 所以在此处应该减去 1.
        ret += map[num] - 1;
    }
    return ret;
}

int main() {

    return 0;
}