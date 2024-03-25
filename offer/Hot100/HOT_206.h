//
// Created by 罗瑞笛 on 2024/3/22.
//

#ifndef OFFER_HOT_206_H
#define OFFER_HOT_206_H


class Solution_206 {
public:
    ListNode* reverseList(ListNode* head) {
        if( head == nullptr||head->next == nullptr)
        {
            return head;
        }

        ListNode* return_back_head = reverseList(head->next); //返回则表示找到了末端
        head->next->next = head;
        head->next = nullptr;               ///太草了
        return return_back_head;
    }
};



#endif //OFFER_HOT_206_H
