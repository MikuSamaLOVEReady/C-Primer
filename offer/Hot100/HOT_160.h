//
// Created by ����� on 2024/3/25.
//

#ifndef OFFER_HOT_160_H
#define OFFER_HOT_160_H

class Solution_160 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* start_a = headA;
        ListNode* start_b = headB;

        /// ����֪������null��ʱ�� ��ʱǰ��������
        while ( headA!= nullptr && headB != nullptr){
            headA = headA->next;
            headB = headB->next;
        }

        if( !headA ) {      /// ���A�ǿյ�
            while (headB!= nullptr){
                headB  = headB->next;
                start_b = start_b->next;
            }
        }else{              /// ���B�ǿյ� �� A��һЩ��Ҫ���ƶ�
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
