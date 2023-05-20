//
// Created by ����� on 2023/5/14.
//

#ifndef OFFER_TOTAL_206_H
#define OFFER_TOTAL_206_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// ��ת����
/// ˫ָ��
/// \param head
/// \return
ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* pre = head;
    ListNode* cur = nullptr;
    while( pre!= nullptr ){
        //������һ��λ��
        ListNode* temp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = temp;
    }
    return cur;
}


/// �ݹ����
/// �ؼ�1. �Ҹ���α���ĩβָ�룿 ֻ������ͬ��Ԫ�أ���ס�ݹ������ʱ���޸���
/// �ؼ�2. ���ݹ鵽��ǰ�ڵ����ΪNull��ֹͣ��������ǰһ����˭����Ϣ�Ͷ�ʧ�ˡ�
/// Ҫ��֤
/// \param head
/// \return
ListNode* reverseList2(ListNode* head) {
    if(head->next == nullptr || head->next->next == nullptr)
    {
        return head;
    }

    ListNode* return_back_head = reverseList2(head->next); //�������ʾ�ҵ���ĩ��
    head->next->next = head;
    head->next = nullptr;
    return return_back_head;
}





#endif //OFFER_TOTAL_206_H
