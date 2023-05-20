//
// Created by di on 2023/5/15.
//

#ifndef OFFER_OFFER_REVERSE_H
#define OFFER_OFFER_REVERSE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    while( head!= nullptr && head->next!= nullptr){
            ListNode* temp = head->next->next; //�����ٿ���һλ��Ԫ��
            head->next->next  = cur; //�ı���һ���ڵ������һ��ָ��
            cur  = head->next;   //�ƶ�cur����һ����������������ע��������head->next ��Ϊcur->next�Ѿ��Ͽ�
            head->next = temp; //�ƶ�head��next����һ��Ԫ��
    }
    return cur;
}


#endif //OFFER_OFFER_REVERSE_H
