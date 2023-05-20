//
// Created by 罗瑞笛 on 2023/5/14.
#ifndef OFFER_OFFER2_27_H
#define OFFER_OFFER2_27_H

ListNode* find_mid(ListNode* head){
    //快慢指针找中点（奇数个节点的时候）
    ListNode* slow = head;
    ListNode* fast = head;
    while(true){
        if(fast->next == nullptr || fast->next->next == nullptr){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

///
/// \param head 传入mid的后一个pointer
/// \return 反转过后的链表head
ListNode* reverse_List(ListNode* head){
    if(head == nullptr) return nullptr;
    ListNode* cur = nullptr;
    ListNode* pre = head;
    while(pre!= nullptr){
        //保存pre的下一个
        ListNode* temp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = temp;
    }
    return cur;
}

bool isPalindrome(ListNode* head) {
    ListNode* mid = find_mid(head);
    ListNode* back = reverse_List(mid->next);
    if(back== nullptr) return true;
    mid->next = nullptr; //切断前后关系
    while(head != nullptr && back != nullptr)
    {
        if(back->val == head->val){
            head = head->next;
            back = back->next;
        }else{
            return false;
        }
    }
    return true;
}





#endif //OFFER_OFFER2_27_H
