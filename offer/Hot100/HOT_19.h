//
// Created by 罗瑞笛 on 2024/2/27.
//

#ifndef OFFER_HOT_19_H
#define OFFER_HOT_19_H



class Solution_19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ///特殊情况、只有一个元素
        if(head->next == nullptr) return nullptr;

        ListNode* pre = head;
        ListNode* cur = head;
        while( pre != nullptr && n >= 0)      ///移动 n+1次 || pre->next = null && n>0 移动n次
        {
            pre = pre->next;
            n--;
        }

        if( n==0 ) /// 特殊！此时删除的是头部节点、理论上除了头部节点、其他时候n==-1
        return head->next;


        while( pre != nullptr)
        {
            cur = cur->next;
            pre = pre->next;
        }

        cur->next = cur->next->next;
        return head;

    }

};

#endif //OFFER_HOT_19_H
