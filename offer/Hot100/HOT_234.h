//
// Created by ����� on 2024/4/2.
//

#ifndef OFFER_HOT_234_H
#define OFFER_HOT_234_H


class Solution_234 {
public:
    /// ��תhead
    ListNode* inversNode(ListNode* head , ListNode* end_node) {
        ListNode* cur = nullptr;
        ListNode* next = head;

        while( next!= end_node ) {
            ListNode* tmp = next -> next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }

    bool isPalindrome(ListNode* head) {
        /// 1�� ��תlist ֮�� ��һһ�Ա�

        /// 2�� ����ָ��
        ListNode* slow = head;
        ListNode* fast = head;

        bool even_size = false;

        while( fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr){
                fast = fast -> next;    /// ��������ƶ����� null ���ʾ����ż�����ڵ㡣 slow Ϊ���ε�head
            }
        }

        if( fast == nullptr){
            even_size = true;
        }
        else if( fast->next == nullptr ) {
            even_size = false;
        }

        /// slow ��Ϊ����node����slow֮ǰ�Ľڵ㷴ת
        ListNode* half_begin = inversNode( head , slow );
        /// even_size ���������
        if(!even_size)  /// ������Ԫ�ء�slow��һ�� ��Ϊ��ʼ
            slow = slow->next;

        while (slow != nullptr){
            if(slow->val != half_begin->val){
                return false;
            }
            slow = slow->next;
            half_begin = half_begin->next;
        }
        return true;

    }
};
#endif //OFFER_HOT_234_H
