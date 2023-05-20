#include <iostream>
#include "offer2-41.h"
#include "offer-25.h"
//#include "offer-26.h"
//#include "offer-21.h"
#include "offer-27.h"
#include "offer28.h"
#include "offer-62.h"

#include "offer-079.h"
#include "offer-14.h"
#include "offer-15.h"
#include "offer-16.h"
#include "offer-17.h"
#include "offer-012.h"
#include "offer2/total-206.h"
#include "offer2/offer2-27.h"


int negateMinimumInt() {
    long long int value = -2147483648LL;  // Ê¹ÓÃ long long int ÀàÐÍ´æ´¢¸ºÊý
    int negatedValue = static_cast<int>(-value);  // È¡·´²¢×ª»»»Ø int ÀàÐÍ
    return negatedValue;
}


int main() {

    /*
    int t=0;
    while(true){
        if(t++>5)
            break;
        std::cout << t << std::endl;
    }s
    MovingAverage* movingAverage = new MovingAverage(3);

    vector<int> nums = {};
    exchange(nums);
     */

    //[1,2,2,null,3,null,3]
    TreeNode* node = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(3);
    node->left = node2;
    node->right = node3;
    node2->left = nullptr;
    node2->right = node4;
    node3->right = nullptr;
    node3->right = node5;

    int val = lastRemaining(5,3);

    vector<bool> iteNum(15);
    vector<int*> myvec;
    myvec.push_back(nullptr);
    bool result = isSymmetric(node);
    std::cout << "wic" << std::endl;
    //std::cout << movingAverage->next(10)<< std::endl;
    //std::cout << movingAverage->next(3) << std::endl;
   //std::cout <<  cuttingRope_DP(10) << std::endl;
   //std::cout <<  hammingWeight(4294967293) << std::endl;
   //std::cout <<  myPow(2.0,10) << std::endl;
   //std::cout << myPow(1,-2147483648) <<std::endl;

    ListNode* head0 = new ListNode(1);
    ListNode* head1 = new ListNode(0);
    ListNode* head2 =  new ListNode(1);
    //ListNode* head3 =  new ListNode(3);
    //ListNode* head4 =  new ListNode(2);
   // ListNode* sigle = new ListNode(1);
    //ListNode* head5 =  new ListNode(1);


    head0->next = head1;
    head1->next = head2;
    //head2->next = head3;
    //head3->next = head4;
    //head4->next = head5;

    bool result =  isPalindrome(head0);
    reverseList2(head0);

    printNumbers2(3);
    //-2^31 ÊÇÕûÊýµÄ×îÐ¡Öµ£¬¼´ -2147483648£¬Ëü¿ÉÒÔÔÚ int ÀàÐÍÖÐ×¼È·µØ±íÊ¾¡£Í¬Ñù£¬2^31-1 ÊÇÕûÊýµÄ×î´óÖµ£¬¼´ 2147483647
    return 0;
}
