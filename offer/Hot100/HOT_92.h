//
// Created by ����� on 2024/3/22.
//

#ifndef OFFER_HOT_92_H
#define OFFER_HOT_92_H

class Solution_92 {
public:

    ListNode* reverseBetween_slow_complex(ListNode* head, int left, int right) {

        /// Ѱ�� �ִ���begin �� end
        ListNode* begin = head , *pre_begin = nullptr;
        int count = right-left;             ///�� being -> end ����Ҫ�ƶ�����
        while( left-1  > 0 ){
            left--;
            pre_begin = begin;
            begin = begin->next;
        }

        /// ���� begin ֮ǰһ�� ���Լ�end֮���һ��
        ListNode* end = begin , *after_end = end->next;
        while(  count > 0) {
            count--;
            end = end -> next;
            after_end = end->next;
        }

        /// ���head  �� being һ�� ��ֱ�ӷ���
        if(begin == end) return head;

        /// ��ת begin & end
        ListNode* begin_backup = begin;

        ListNode* pre = nullptr;
        while(begin != after_end){
            ListNode* temp = begin->next;
            begin->next = pre;
            pre = begin;
            begin = temp;
        }
        if( pre_begin != nullptr && begin_backup != nullptr){
            pre_begin ->next = pre;
            begin_backup->next = after_end;
        }

        /// pre_begin == null ��ʾ��ͷ��ʼ��ת����ʱ��Ҫ������ pre-����
        if (pre_begin == nullptr) {
            begin_backup->next = after_end;
            return pre;
        }
        return head;
    }
};

#endif //OFFER_HOT_92_H
