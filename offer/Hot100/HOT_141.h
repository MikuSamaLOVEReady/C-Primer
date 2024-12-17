//
// Created by 罗瑞笛 on 2024/3/26.
//

#ifndef OFFER_HOT_141_H
#define OFFER_HOT_141_H


class Solution_141 {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        /// 特殊情况处理
        if( head == nullptr || head->next == nullptr ) return false;

        while( fast != nullptr){
            if(fast == slow) return true;
             slow = slow->next;
             fast = fast->next;
             if(fast != nullptr){
                 fast = fast->next;
             }
        }
        return false;

    }
};

#endif //OFFER_HOT_141_H
