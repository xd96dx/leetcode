/*
23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
*/

#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp {
    bool operator() (ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> pr_;
    // 创建 priority_queue, 将各个链表的第一个元素放入 queue 中
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i])
        pr_.push(lists[i]);
    }
    ListNode *new_node = new ListNode();
    ListNode *n = new_node;
    while (!pr_.empty()) {
        // 因为传入的链表本身是已经排序的, 此时queue中的数据链表头都是排序号的 接收 queue 中的第一个元素并删除
        ListNode* tmp = pr_.top();
        pr_.pop();
        // 当拿出一个链表时, 同时将链表的下一个元素放入quueue 中进行排序, 如此往复即可
        if (tmp -> next) {
            pr_.push(tmp->next);
        }
        n->next = tmp;
        n = n->next;
    }
    return new_node->next;
}

int main() {
    return 0;
}