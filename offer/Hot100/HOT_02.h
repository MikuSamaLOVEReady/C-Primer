//
// Created by 罗瑞笛 on 2024/2/22.
//

#ifndef OFFER_HOT_02_H
#define OFFER_HOT_02_H
#include "../offer-18.h"

class HOT_02 {

};

class Solution_01 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool exceed_flag = false;
        ListNode* p_head = new ListNode(-1);     //虚空头节点
        ListNode* cur    = p_head;

        while( l1!=nullptr || l2 != nullptr)
        {
            int va = 0 , vb = 0;
            if( l1 != nullptr)
            {
                va = l1->val;
                l1 = l1->next;
            }
            if( l2 != nullptr)
            {
                vb = l2->val;
                l2 = l2->next;
            }
            int result = exceed_flag ? va + vb + 1 : va + vb;
            exceed_flag = result / 10 == 1;
            result = result % 10;
            auto* new_node = new ListNode(result);
            cur->next = new_node;
            cur = cur->next;
        }

        /// 特殊情况、当最后加完后、仍有进位时、需要额外操作
        if( exceed_flag )
        {
            auto* new_node = new ListNode(1);
            cur->next = new_node;
            cur = cur->next;
        }
        return p_head->next;
    }
};

#endif //OFFER_HOT_02_H
