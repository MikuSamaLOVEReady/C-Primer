//
// Created by 罗瑞笛 on 2024/4/2.
//

#ifndef OFFER_HOT_234_H
#define OFFER_HOT_234_H


class Solution_234 {
public:
    /// 反转head
    ListNode* inversNode(ListNode* head , ListNode* end_node) {
        ListNode* cur = nullptr;
        ListNode* next = head;

        while( next!= end_node ) {
            ListNode* tmp = next -> next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }

    bool isPalindrome(ListNode* head) {
        /// 1。 反转list 之后 再一一对比

        /// 2。 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;

        bool even_size = false;

        while( fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr){
                fast = fast -> next;    /// 如果二次移动导致 null 则表示含有偶数个节点。 slow 为后半段的head
            }
        }

        if( fast == nullptr){
            even_size = true;
        }
        else if( fast->next == nullptr ) {
            even_size = false;
        }

        /// slow 作为结束node、将slow之前的节点反转
        ListNode* half_begin = inversNode( head , slow );
        /// even_size 如果是奇数
        if(!even_size)  /// 奇数个元素、slow后一个 作为开始
            slow = slow->next;

        while (slow != nullptr){
            if(slow->val != half_begin->val){
                return false;
            }
            slow = slow->next;
            half_begin = half_begin->next;
        }
        return true;

    }
};
#endif //OFFER_HOT_234_H
