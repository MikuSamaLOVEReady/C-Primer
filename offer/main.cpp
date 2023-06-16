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
#include "offer2/offer-30.h"
#include "classics-Alg/MergeSort.h"
#include "classics-Alg/QuickSort.h"
#include "704.h"
#include "02.h"
#include "05.h"
#include "03.h"
#include "1480.h"
#include "04.h"
#include "146.h"
#include "2460.h"
#include "offer2/70.h"
#include "59.h"
#include "15.h"



int negateMinimumInt() {
    long long int value = -2147483648LL;  // Ê¹ÓÃ long long int ÀàÐÍ´æ´¢¸ºÊý
    int negatedValue = static_cast<int>(-value);  // È¡·´²¢×ª»»»Ø int ÀàÐÍ
    return negatedValue;
}


int main() {

    std::vector<std::vector<int*>> vec1(10, std::vector<int*>(10, nullptr));
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
    /*
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
      */
    //std::cout << movingAverage->next(10)<< std::endl;
    //std::cout << movingAverage->next(3) << std::endl;
   //std::cout <<  cuttingRope_DP(10) << std::endl;
   //std::cout <<  hammingWeight(4294967293) << std::endl;
   //std::cout <<  myPow(2.0,10) << std::endl;
   //std::cout << myPow(1,-2147483648) <<std::endl;

    //ListNode* head0 = new ListNode(1);
    //ListNode* head1 = new ListNode(0);
    //ListNode* head2 =  new ListNode(1);
    //ListNode* head3 =  new ListNode(3);
    //ListNode* head4 =  new ListNode(2);
    //ListNode* sigle = new ListNode(1);
    //ListNode* head5 =  new ListNode(1);


    //head0->next = head1;
    //head1->next = head2;
    //head2->next = head3;
    //head3->next = head4;
    //head4->next = head5;

    MinStack stk;
    stk.push(0);
    stk.push(1);
    stk.push(0);
    //int val =  stk.min();
    stk.pop();
    //val = stk.min();

    std::cout<<INT_MAX<<std::endl;

    vector<int> nums = {1,2,4,7};
    //bool final = containsDuplicate(nums);
    //QuickSort(nums,0,nums.size()-1);
    int serach_val = search(nums,2);

    string s_test = "a";
    //auto re =  longestPalindrome(s_test);

    string s_lognset = "pwwkew";
    int max_val =  lengthOfLongestSubstring2(s_lognset);

    vector<int> vvv ={3,1,2,10,1};
    auto rr = runningSum(vvv);

    vector<int> vt1 ={1,2};
    vector<int> vt2 ={3,4};

    auto final_re = findMedianSortedArrays(vt1,vt2);

    //LRUCache* obj = new LRUCache(2);
    //obj->put(2,1);
    //obj->put(1,1);
    //obj->put(2,3);
    //obj->put(4,1);
    //int param_1 = obj->get(1);
    //int param_3 = obj->get(2);

    vector<int> vvtt = {847,847,0,0,0,399,416,416,879,879,206,206,206,272};
    auto fianl = applyOperations(vvtt);
    std::cout << climbStairs(44) << std::endl;

    auto result =generateMatrix(3);

    vector<int> cur_ques{7,-10,7,3,14,3,-2,-15,7,-1,-7,6,-5,-1,3,-13,6,-15,-10,14,8,5,-10,-1,1,1,11,6,8,5,-4,0,3,10,-12,
                         -6,-2,-6,-6,-10,8,-5,12,10,1,-8,4,-8,-8,2,-9,-15,14,-11,-1,-8,5,-13,14,-2,0,-13,14,-12,12,-13,
                         -3,-13,-12,-2,-15,4,8,4,-1,-6,11,11,-7,-12,-2,-8,10,-3,-4,-6,4,-14,-12,-5,0,3,-3,-9,-2,-6,-15,2
                         ,-11,-11,8,-11,8,-7,8,14,-5,4,10,3,-1,-15,10,-6,-11,13,-5,1,-15};

    vector<int> cur_ques2{0,0,0};
    auto my_resu = threeSum2(cur_ques2);
    auto my_result = threeSum2(cur_ques);

    printNumbers2(3);
    //-2^31 ÊÇÕûÊýµÄ×îÐ¡Öµ£¬¼´ -2147483648£¬Ëü¿ÉÒÔÔÚ int ÀàÐÍÖÐ×¼È·µØ±íÊ¾¡£Í¬Ñù£¬2^31-1 ÊÇÕûÊýµÄ×î´óÖµ£¬¼´ 2147483647
    return 0;
}
