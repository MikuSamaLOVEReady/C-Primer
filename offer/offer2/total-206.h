//
// Created by 罗瑞笛 on 2023/5/14.
//

#ifndef OFFER_TOTAL_206_H
#define OFFER_TOTAL_206_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// 反转链表
/// 双指针
/// \param head
/// \return
ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* pre = head;
    ListNode* cur = nullptr;
    while( pre!= nullptr ){
        //保存下一个位置
        ListNode* temp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = temp;
    }
    return cur;
}


/// 递归求解
/// 关键1. 我该如何保留末尾指针？ 只返回相同的元素，记住递归结束的时候修改它
/// 关键2. 不递归到当前节点后续为Null就停止，这样他前一个是谁的信息就丢失了。
/// 要保证
/// \param head
/// \return
ListNode* reverseList2(ListNode* head) {
    if(head->next == nullptr || head->next->next == nullptr)
    {
        return head;
    }

    ListNode* return_back_head = reverseList2(head->next); //返回则表示找到了末端
    head->next->next = head;
    head->next = nullptr;
    return return_back_head;
}





#endif //OFFER_TOTAL_206_H
