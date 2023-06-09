//
// Created by ����� on 2023/5/23.
//

#ifndef OFFER_02_H
#define OFFER_02_H


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* cur = head;

    bool pre_exceed = false;
    int val1 = 0 , val2 = 0;
    while( l1!= nullptr || l2!= nullptr||pre_exceed){

        if( l1 != nullptr ){
            val1 = l1->val;
            l1 = l1->next;
        }
        else {
            val1 = 0;
        }
        if( l2 != nullptr){
            val2 = l2->val;
            l2 = l2->next;
        }
        else{
            val2 = 0;
        }

        //��λ�ж�
        int final = val1 + val2;
        if(pre_exceed){
            final += 1;
        }
        //����10ֻȡ��λ
        if(final >= 10){
            final = final%10;
            pre_exceed = true;
        }
        else{
            pre_exceed  = false;
        }
        ListNode* node = new ListNode(final);
        cur->next = node;
        cur = cur->next;
    }
    //����������ȫ�������Ϻ󣬲鿴�Ƿ���ʣ���λ
    if(pre_exceed){
        ListNode* node = new ListNode(1);
        cur->next = node;
        cur = cur->next;
    }

    return head->next;
}



#endif //OFFER_02_H
