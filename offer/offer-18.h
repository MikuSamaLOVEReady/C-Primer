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

    //人造一个空head节点,它永远不动，最终返回head->next
    //lastNode滞后于cur节点一个位置
    //head节点当作遍历的目标，探针
    ListNode* myhead = new ListNode(0);
    ListNode* lastNode = new ListNode(0);
    //初始化
    myhead->next = head;
    lastNode = myhead;

    while(head != nullptr){
        //如果找到了该值
        if(head->val == val){
             lastNode->next = head->next;
             head->next = nullptr;
             return myhead->next;
        }
        //如果没找到
        else{
            head = head->next;
            lastNode = lastNode->next;
        }
    }
    return  myhead->next;
}


#endif //OFFER_OFFER_18_H
