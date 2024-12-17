//
// Created by 罗瑞笛 on 2024/4/1.
//

#ifndef OFFER_HOT_142_H
#define OFFER_HOT_142_H

class Solution_142 {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr){
            slow = slow->next;

            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
            }
            else{
                return nullptr;
            }
            if( slow == fast ){
                  fast = head;  /// 重新换回头部位置
                  while(slow != fast)
                  {
                      slow = slow->next;
                      fast = fast->next;
                  }
                  return slow;
            }
        }

        return nullptr;
    }

};

#endif //OFFER_HOT_142_H
