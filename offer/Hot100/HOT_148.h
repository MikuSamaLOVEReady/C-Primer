//
// Created by 罗瑞笛 on 2024/3/24.
//

#ifndef OFFER_HOT_148_H
#define OFFER_HOT_148_H

class Solution_148 {
public:

    /// \return 返回合并过后的有序
    ListNode* merge(ListNode* l1 , ListNode* l2){

        /// 每次融合完需要返回的时候出现麻烦 , 预先设置dummy、返回 dummy->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* pre_node = dummy;

//        while( l1 != nullptr && l2 != nullptr){
//            ListNode* cur_node = new ListNode(0);           /// 需要额外空间、没有在l1、l2已有元素上操作
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


        /// 一一对比结束
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


    /// \return 排序后的子问题的head
    ListNode* divide_sort(ListNode* head , ListNode* tail){
        /// Head 可能是null吗？ 、、、 仅处理输入=null的情况？

        /// 递归出口  只有一个节点
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }

        /// 快慢指针、 找mid
        ListNode* fast = head;
        ListNode* mid  = head;           /// mid 为后半段的开头
        while( fast!= tail && fast->next != tail ){       /// fast 判定不能是null 得是tail，在还没有return的时候、前半段数组是没有被切断的
            fast =  fast->next->next;
            mid  = mid->next;
        }

        return merge(divide_sort(head ,mid) , divide_sort(mid , tail));
    }

    /// 分治 + 合并两个数组
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;

       return divide_sort(head , nullptr);
    }
};


#endif //OFFER_HOT_148_H
