#include <iostream>
#include "offer-079.h"
#include "offer-14.h"
#include "offer-15.h"
#include "offer-16.h"
#include "offer-17.h"
#include "offer-012.h"
#include "offer2/total-206.h"
#include "offer2/offer2-27.h"


int negateMinimumInt() {
    long long int value = -2147483648LL;  // ʹ�� long long int ���ʹ洢����
    int negatedValue = static_cast<int>(-value);  // ȡ����ת���� int ����
    return negatedValue;
}


int main() {

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
    //-2^31 ����������Сֵ���� -2147483648���������� int ������׼ȷ�ر�ʾ��ͬ����2^31-1 �����������ֵ���� 2147483647
    return 0;
}
