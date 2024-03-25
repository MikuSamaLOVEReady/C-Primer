//
// Created by 罗瑞笛 on 2024/3/22.
//

#ifndef OFFER_HOT_92_H
#define OFFER_HOT_92_H

class Solution_92 {
public:

    ListNode* reverseBetween_slow_complex(ListNode* head, int left, int right) {

        /// 寻找 字串的begin 与 end
        ListNode* begin = head , *pre_begin = nullptr;
        int count = right-left;             ///从 being -> end 还需要移动几次
        while( left-1  > 0 ){
            left--;
            pre_begin = begin;
            begin = begin->next;
        }

        /// 保留 begin 之前一个 、以及end之后的一个
        ListNode* end = begin , *after_end = end->next;
        while(  count > 0) {
            count--;
            end = end -> next;
            after_end = end->next;
        }

        /// 如果head  与 being 一致 则直接返回
        if(begin == end) return head;

        /// 反转 begin & end
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

        /// pre_begin == null 表示从头开始反转、此时需要单独将 pre-返回
        if (pre_begin == nullptr) {
            begin_backup->next = after_end;
            return pre;
        }
        return head;
    }
};

#endif //OFFER_HOT_92_H
