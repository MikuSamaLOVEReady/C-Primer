//
// Created by di on 2023/5/15.
//

#ifndef OFFER_OFFER_18_H
#define OFFER_OFFER_18_H

#include <cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteNode(ListNode* head, int val){

    //����һ����head�ڵ�,����Զ���������շ���head->next
    //lastNode�ͺ���cur�ڵ�һ��λ��
    //head�ڵ㵱��������Ŀ�꣬̽��
    ListNode* myhead = new ListNode(0);
    ListNode* lastNode = new ListNode(0);
    //��ʼ��
    myhead->next = head;
    lastNode = myhead;

    while(head != nullptr){
        //����ҵ��˸�ֵ
        if(head->val == val){
             lastNode->next = head->next;
             head->next = nullptr;
             return myhead->next;
        }
        //���û�ҵ�
        else{
            head = head->next;
            lastNode = lastNode->next;
        }
    }
    return  myhead->next;
}


#endif //OFFER_OFFER_18_H
