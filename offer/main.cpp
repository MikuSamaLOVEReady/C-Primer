#include <iostream>
#include <cstring>
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
#include "15.h"
#include "11.h"
#include "13.h"
#include "offer-12.h"
#include "16.h"
#include "239H.h"
#include "2058.h"



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

    vector<int>::iterator re = vt2.erase(vt2.begin()+1);
    std::cout<< *re << std::endl;

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
    //std::cout << climbStairs(44) << std::endl;

    vector<int> testtt = {2,0,-2,-5,-5,-3,2,-4};
    auto fianl2 = threeSum(testtt);



    vector<int> area = {1,8,6,2,5,4,8,3,7};
    vector<int> area2 = {1,2,4,3};

    int valtt = maxArea2(area2);
    auto va = RomaToint({"MCMXCIV"});
    auto va_roma = intToRoman(1994);

    vector<int> test_vec =  {1,3,-1,-3,5,3,6,7};
    //int my_ret = threeSumClosest2( test_vec ,16 );

    auto outpp = maxSlidingWindow(test_vec,3);

    vector<string >s1 = {"leetcode","is","amazing","as","is"};
    vector<string >s2 = {"amazing","leetcode","is"};

    leet_2058::countwords(s1 , s2);
    leet_2058::official_solu(s1,s2);

    leet_2058::A inst1;                     // default init
    leet_2058::A* inst2 = new leet_2058::A; //default init
    leet_2058::A* inst3 = new leet_2058::A(); // value init

    const char* myStr = "Hello";
    const char arrstr[] = "hello";
    size_t length = std::strlen(myStr);
    std::cout << sizeof arrstr << std::endl;


    printNumbers2(3);
    //-2^31 ÊÇÕûÊýµÄ×îÐ¡Öµ£¬¼´ -2147483648£¬Ëü¿ÉÒÔÔÚ int ÀàÐÍÖÐ×¼È·µØ±íÊ¾¡£Í¬Ñù£¬2^31-1 ÊÇÕûÊýµÄ×î´óÖµ£¬¼´ 2147483647
    return 0;
}
