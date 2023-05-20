//
// Created by ����� on 2023/5/14.
#ifndef OFFER_OFFER2_27_H
#define OFFER_OFFER2_27_H

ListNode* find_mid(ListNode* head){
    //����ָ�����е㣨�������ڵ��ʱ��
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
/// \param head ����mid�ĺ�һ��pointer
/// \return ��ת���������head
ListNode* reverse_List(ListNode* head){
    if(head == nullptr) return nullptr;
    ListNode* cur = nullptr;
    ListNode* pre = head;
    while(pre!= nullptr){
        //����pre����һ��
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
    mid->next = nullptr; //�ж�ǰ���ϵ
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
