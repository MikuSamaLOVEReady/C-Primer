//
// Created by 罗瑞笛 on 2024/2/28.
//

#ifndef OFFER_HOT_21_H
#define OFFER_HOT_21_H



class Solution_21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if( list1 == nullptr ) return list2;
        if( list2 == nullptr ) return list1;

        /// 选择当前的header
        if( list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next , list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1 , list2->next);
            return list2;
        }

    }


};


#endif //OFFER_HOT_21_H
