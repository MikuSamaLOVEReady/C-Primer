//
// Created by ����� on 2024/3/24.
//

#ifndef OFFER_HOT_148_H
#define OFFER_HOT_148_H

class Solution_148 {
public:

    /// \return ���غϲ����������
    ListNode* merge(ListNode* l1 , ListNode* l2){

        /// ÿ���ں�����Ҫ���ص�ʱ������鷳 , Ԥ������dummy������ dummy->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* pre_node = dummy;

//        while( l1 != nullptr && l2 != nullptr){
//            ListNode* cur_node = new ListNode(0);           /// ��Ҫ����ռ䡢û����l1��l2����Ԫ���ϲ���
//            if( l1->val < l2->val ){
//                cur_node->val = l1->val;
//                l1 = l1->next;
//            }else{
//                cur_node->val = l2->val;
//                l2  = l2->next;
//            }
//            pre_node->next = cur_node;
//            pre_node = cur_node;
//        }

        while( l1 != nullptr && l2 != nullptr){
            if( l1->val <= l2->val){
                pre_node -> next = l1;
                l1 = l1->next;
            }
            else {
                pre_node -> next =l2;
                l2 = l2->next;
            }
            pre_node = pre_node->next;
        }


        /// һһ�ԱȽ���
        if( !l1  )  pre_node->next = l2;
        else pre_node->next = l1;
        return dummy->next;
    }

//    ListNode* merge(ListNode* head1, ListNode* head2) {
//        ListNode* dummyHead = new ListNode(0);
//        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
//        while (temp1 != nullptr && temp2 != nullptr) {
//            if (temp1->val <= temp2->val) {
//                temp->next = temp1;
//                temp1 = temp1->next;
//            } else {
//                temp->next = temp2;
//                temp2 = temp2->next;
//            }
//            temp = temp->next;
//        }
//        if (temp1 != nullptr) {
//            temp->next = temp1;
//        } else if (temp2 != nullptr) {
//            temp->next = temp2;
//        }
//        return dummyHead->next;
//    }


    /// \return �������������head
    ListNode* divide_sort(ListNode* head , ListNode* tail){
        /// Head ������null�� ������ ����������=null�������

        /// �ݹ����  ֻ��һ���ڵ�
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }

        /// ����ָ�롢 ��mid
        ListNode* fast = head;
        ListNode* mid  = head;           /// mid Ϊ���εĿ�ͷ
        while( fast!= tail && fast->next != tail ){       /// fast �ж�������null ����tail���ڻ�û��return��ʱ��ǰ���������û�б��жϵ�
            fast =  fast->next->next;
            mid  = mid->next;
        }

        return merge(divide_sort(head ,mid) , divide_sort(mid , tail));
    }

    /// ���� + �ϲ���������
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;

       return divide_sort(head , nullptr);
    }
};


#endif //OFFER_HOT_148_H
