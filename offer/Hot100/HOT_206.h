//
// Created by ����� on 2024/3/22.
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

        ListNode* return_back_head = reverseList(head->next); //�������ʾ�ҵ���ĩ��
        head->next->next = head;
        head->next = nullptr;               ///̫����
        return return_back_head;
    }
};



#endif //OFFER_HOT_206_H
