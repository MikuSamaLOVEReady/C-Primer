//
// Created by di on 2023/5/17.
//

#ifndef OFFER_OFFER_25_H
#define OFFER_OFFER_25_H
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    ListNode* head1= l1;
    ListNode* head2= l2;
    //两个链表其中之一达到了最后就停止
    while( l1->next != nullptr && l2->next != nullptr ){
        //l2小，保存l2下一个，将l1连在l2之后
        if(l1->val >= l2->val){
          ListNode* temp = l1->next;
          l1->next = l2->next;
          l2->next = l1;
          l2 = l1->next;
          l1 = temp;
        }
        //l1
        else{
            ListNode* temp = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
            l2 = temp;
        }
    }

    //l1为空,让l1直接接l2
    if(l1->next == nullptr){
        l1->next = l2;
        return head1;
    }
    else if(l2->next == nullptr){
        l2->next = l1;
        return head2;
    }

}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

    ListNode* cur= new ListNode(0);
    ListNode* result = cur;
    while( l1 != nullptr && l2 != nullptr ){
        if(l1->val <= l2->val){
            ListNode* temp = l1->next;
            l1->next = nullptr;
            cur->next = l1;
            l1 = temp;
        }
        else{
            ListNode* temp = l2->next;
            l2->next = nullptr;
            cur->next = l2;
            l2 = temp;
        }
        //最终链表的移动指针
       cur = cur->next;
    }

    if(l1 == nullptr){
        cur->next = l2;
    }
    else{
        cur->next = l1;
    }
    return result->next;
}
#endif //OFFER_OFFER_25_H
