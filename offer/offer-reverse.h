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
            ListNode* temp = head->next->next; //保存再靠后一位的元素
            head->next->next  = cur; //改变下一个节点的在下一个指向，
            cur  = head->next;   //移动cur到下一个，………………注意这里是head->next 因为cur->next已经断开
            head->next = temp; //移动head的next到下一个元素
    }
    return cur;
}


#endif //OFFER_OFFER_REVERSE_H
