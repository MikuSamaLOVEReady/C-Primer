//
// Created by ����� on 2024/2/27.
//

#ifndef OFFER_HOT_19_H
#define OFFER_HOT_19_H



class Solution_19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ///���������ֻ��һ��Ԫ��
        if(head->next == nullptr) return nullptr;

        ListNode* pre = head;
        ListNode* cur = head;
        while( pre != nullptr && n >= 0)      ///�ƶ� n+1�� || pre->next = null && n>0 �ƶ�n��
        {
            pre = pre->next;
            n--;
        }

        if( n==0 ) /// ���⣡��ʱɾ������ͷ���ڵ㡢�����ϳ���ͷ���ڵ㡢����ʱ��n==-1
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
