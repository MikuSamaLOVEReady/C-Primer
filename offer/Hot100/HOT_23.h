//
// Created by ÂÞÈðµÑ on 2024/2/28.
//

#ifndef OFFER_HOT_23_H
#define OFFER_HOT_23_H


class Solution_23 {

public:

    ListNode* mergeTwoLists( ListNode* l1 , ListNode* l2)
    {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        if( l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next , l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1 , l2->next);
            return l2;
        }

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        /// µÝ¹é³ö¿Ú
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 2)
        {
            return mergeTwoLists(lists[0], lists[1]);
        }

        auto lis_left = vector<ListNode*>(lists.begin()+1,lists.end());
        ListNode* left_merged = mergeKLists( lis_left );
        ListNode* cur = mergeTwoLists(lists[0] ,left_merged);
        return cur;
    }

};


#endif //OFFER_HOT_23_H
