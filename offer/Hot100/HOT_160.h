//
// Created by 罗瑞笛 on 2024/3/25.
//

#ifndef OFFER_HOT_160_H
#define OFFER_HOT_160_H

class Solution_160 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* start_a = headA;
        ListNode* start_b = headB;

        /// 我想知道都到null的时候 此时前后相差多少
        while ( headA!= nullptr && headB != nullptr){
            headA = headA->next;
            headB = headB->next;
        }

        if( !headA ) {      /// 如果A是空的
            while (headB!= nullptr){
                headB  = headB->next;
                start_b = start_b->next;
            }
        }else{              /// 如果B是空的 、 A长一些需要先移动
            while (headA!= nullptr){
                headA  = headA->next;
                start_a = start_a->next;
            }
        }

        while( start_a != start_b){
            start_a = start_a->next;
            start_b = start_b->next;
        }

        return start_a;
    }
};

#endif //OFFER_HOT_160_H
