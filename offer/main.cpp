#include <iostream>
#include <cstring>
#include <numeric>
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
#include "LCR_156.h"


#include "Niuke/BM49.h"
#include "Hot100/HOT_05.h"
#include "Hot100/HOT_15.h"
#include "Hot100/HOT_17.h"
#include "Hot100/HOT_19.h"
#include "Hot100/HOT_21.h"
#include "Hot100/HOT_22.h"
#include "Hot100/HOT_23.h"
#include "Hot100/HOT_31.h"
#include "Hot100/HOT_32.h"
#include "Hot100/HOT_461.h"
#include "Hot100/HOT_33.h"
#include "Hot100/HOT_34.h"
#include "classics-Alg/BinarySearch.h"
#include "Hot100/HOT_39.h"
#include "classics-Alg/Permute.h"
#include "Hot100/HOT_42.h"
#include "Hot100/HOT_46.h"
#include "Hot100/HOT_48.h"
#include  "Hot100/HOT_49.h"
#include  "Hot100/HOT_53.h"
#include "Hot100/HOT_55.h"
#include "Hot100/HOT_56.h"
#include "Hot100/HOT_62.h"
#include "Hot100/HOT_64.h"
#include "Hot100/HOT_70.h"
#include "Hot100/HOT_72.h"
#include "Hot100/HOT_78.h"
#include "offer-07.h"
#include "Hot100/HOT_226.h"
#include "Hot100/HOT_617.h"
#include "Hot100/HOT_338.h"
#include "Hot100/HOT_104.h"
#include "Hot100/HOT_538.h"
#include "classics-Alg/mid_order.h"
#include "Hot100/HOT_406.h"
#include "Hot100/HOT_238.h"
#include "Hot100/HOT_114.h"
#include "classics-Alg/pre_order.h"
#include "Hot100/HOT_136.h"
#include "Hot100/HOT_208.h"
#include "Hot100/HOT_105.h"
#include "Hot100/HOT_96.h"
#include "Hot100/HOT_236.h"
#include "Hot100/HOT_312.h"
#include "Hot100/HOT_739.h"
#include "Hot100/HOT_647.h"
#include "Hot100/HOT_102.h"
#include "classics-Alg/BFS.h"
#include "Hot100/HOT_448.h"
#include "Hot100/HOT_206.h"
#include "Hot100/HOT_92.h"
#include "Hot100/HOT_169.h"
#include "Hot100/HOT_309.h"
#include "Hot100/HOT_148.h"
#include "Hot100/HOT_121.h"
#include "Hot100/HOT_283.h"
#include "Hot100/HOT_160.h"
#include "Hot100/HOT_287.h"
#include "Hot100/HOT_141.h"
#include "Hot100/HOT_198.h"
#include "Hot100/HOT_101.h"
#include "Hot100/HOT_300.h"
#include "Design_Patterns/Factory_learn.h"
#include "Hot100/HOT_347.h"
#include "heapAndStack/Heap_imp.h"
#include "Hot100/HOT_215.h"
#include "Hot100/HOT_98'.h"
#include "Hot100/HOT_142.h"
#include "Hot100/HOT_332.h"
#include "Hot100/HOT_234.h"
#include "Hot100/HOT_75.h"
#include "GigBits/54_LuoXuanMatrix.h"
#include "GigBits/63_Mid_difPath.h"
#include "GigBits/157_OrderSequence.h"
#include "GigBits/tiankong.h"
#include "Design_Patterns/Observers.h"
#include "Design_Patterns/share_mode.h"
#include "Hot100/HOT1277.h"
#include "Hot100/DP_416.h"
#include "Hot100/HOT_322.h"
#include "Hot100/HOT_518.h"
#include "Hot100/HOT_377.h"
#include "Hot100/HOT_486.h"
#include "Hot100/HOT_464.h"
#include "Hot100/HOT_437.h"
#include "Hot100/HOT_560.h"
#include "Hot100/HOT_581.h"
#include "classics-Alg/insert_sort.h"
#include "Hot100/HOT_337.h"

#include "huawei/full_binary_serach_tree.h"
#include "Hot100/HOT_240.h"
#include "HW/HW_4_24.h"
#include "MT/MT_2024_4_13_01.h"
#include "Hot100/HOT_303.h"
#include "CPU_Eyes/Chapter4_1.h"

void te(){

    istringstream_learn();

}

int negateMinimumInt() {
    long long int value = -2147483648LL;  // Ê¹ÓÃ long long int ÀàÐÍ´æ´¢¸ºÊý
    int negatedValue = static_cast<int>(-value);  // È¡·´²¢×ª»»»Ø int ÀàÐÍ
    return negatedValue;
}

/// ?？？
void erase_test(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    it++;
    vec.erase(it);

    std::cout << *it << std::endl;
}


///ACM testing
void test_06(){
    int rows = 0;
    while(cin >> rows){
            int count = 0;
            while ( cin >> count ){
                int cur = 0;
                int sum = 0;
                while(count--){
                    cin >> cur;
                    sum += cur;
                }

                rows--;
                cout << sum <<endl;

                if(rows != 0){
                    cout << endl;
                }
                else{
                    break;
                }
            }
    }
}

unordered_map<string , function<Design_video::AbstractFactory*()>> m_factory {
        {"Circle" , []() { return new Design_video::CircleFactory(); }},
        {"Square" , []() { return new Design_video::SquareFactory(); }}
};
void Factory_test() {

    int producttime ;
    std::cin >> producttime;

    string s;
    int    num;
    Design_video::AbstractFactory* factory; /// 在stack上
    vector<Design_video::IShape*> shpes;
    /// Design_video::AbstractFactory cur_fac
    while( cin >> s >> num ){
       factory = m_factory[s]();
       for( int i = 0 ; i<num ;++i){
           shpes.push_back(factory->CreateShape());
       }
    }

    for( auto it = shpes.begin() ; it != shpes.end() ;++it){
        (*it)->draw();
    }
}

/// flyweitght test
void flyTest(){

    string obj_name;
    int posx , posy;
    Flyweight_factory fac{};
    while(  cin >> obj_name >> posx >> posy )
    {
        auto ptr = fac.getFlyweight(obj_name);
        ptr->operation(posx , posy);
    }

}


/// 吉比特笔试
void Gig_01(){
    char s[] = "abcdefghijk";
    int p = 9;
    /// std::cout << h(s, cal(s), 0, p) << "wod" << endl;

    ///02
    int va  = f(127);
    int a = 128;
    int b = -128;
    int va2 =  a & b;

}

int main() {

    std::vector<std::vector<int*>> vec1(10, std::vector<int*>(10, nullptr));
    // flyTest();
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

    list<int> vaa = {1,2,3,4};
    /// auto& it_lsit = vaa.begin();         /// Non-const lvalue reference 【非常量左值Ref】无法绑定 ---> a temporary of type '_List_iterator<...>' 【】
    Codec cii{};
    Codec* ptr_cii = &cii;

    Codec cii_another{};
    ptr_cii = &cii_another;

    int& ref_lva = getValue();              ///   getValue();
    ///int




    auto it = std::find(s1.begin() , s1.end() , "leeto");
    auto res = cur_str();
    auto sscur = cur_str2();
    //"(12*10-(-104)*20)-2"
    std::string s_BM49 = "((10+2)*10-(100-204)*10*1*2)-2";
    std::string s_BM49_2 = "1-2-3";
    //int va_BM49 = Solution::solve(s_BM49);
    int va_BM49_2 = Solution::solve(s_BM49_2);

    std::vector<int> vecc_push{};
    std::vector<one_int_obj> one_vecc{};
    //vecc_push.push_back(14);            ///  右值引用 底层会启动 move_Ctr 构造出一个真实的Obj
    one_vecc.push_back(15);
    std::cout << one_vecc.front().value << "woc !!!! " << std::endl;

    one_int_obj one_int_obj1(15);
    one_vecc.push_back(one_int_obj1);   /// pass by ref

    ///Solution_05 s1{};
    //s1.longestPalindrome("wpc");

    unordered_multimap<int , int> multi_test;
    multi_test.insert(make_pair(16,1));
    multi_test.insert(make_pair(16,2));
    multi_test.insert(make_pair(16,3));
    multi_test.insert(make_pair(5,5));

    auto  itt =  multi_test.find(16);
    for(auto it = multi_test.begin() ; it != multi_test.end() ; ++it )
    {
        if(it->first == 16)
        {
            cout << "Key: " << it->first << ", Value: " << it->second << endl;
        }
    }

    vector<int> sortest{-1,0,1,2,-1,-4};
    std::sort(sortest.begin(), sortest.end(), [](int a , int b) {
        return a > b;
    });
    std::sort(sortest.begin(), sortest.end());

    threeSum_real(sortest);

    Solution_17 solu17;
    solu17.letterCombinations("2");

    Solution_22 solu22;
    solu22.generateParenthesis(3);

    Solution_31 solu31;
    vector<int> num = {1,1,5};
    solu31.nextPermutation(num);

    Solution_32 solu32;
    string s_32 = "(()())";
    //solu32.longestValidParentheses_WRONG(s_32);
    solu32.longestValidParentheses(s_32);

    Solution_33 solu33{};
    vector<int> nun{1};
    solu33.search(nun , 0);

    Solution_34 solu34{};
    vector<int> nun_34{5,7,7,8,8,10};
    solu34.searchRange( nun_34 , 6 );

    Solution_LCR_083 solu_LCR83{};
    vector<int> nun_83{1,2,3};
    solu_LCR83.permute(nun_83);

    ///int vaa = 2;
    ///int va_next = vaa & 1;

    Solution_42 solu42{};
    vector<int> num_42{0,1,0,2,1,0,1,3,2,1,2,1};
    solu42.trap(num_42);

    Solution_49 solu49{};
    vector<string> s_49{"eat","tea","tan","ate","nat","bat"};
    vector<string> s_49_1{"","b"};
    vector<string> s_49_2{"",""};
    vector<string> s_49_3{"","b",""};
    vector<string> s_49_4{ "and","dans" };
    solu49.groupAnagrams(s_49_4);
    erase_test();

    Solution_62 solu62{};
    int va_62 = solu62.uniquePaths_TimeOut(3,7);
    int va_62_2 = solu62.uniquePaths(23,12);
    int va_64_3 = solu62.uniquePaths_Cmn(3,7);

    long long att = 1515;
    int vava_long = att;

    Solution_64 solu64{};
    vector<vector<int>> test_64;
    vector<int> te_64{1,2,3};
    vector<int> te_64_1{4,5,6};
    //vector<int> te_64_2{4,2,1};
    test_64.push_back(te_64);
    test_64.push_back(te_64_1);
    //test_64.push_back(te_64_2);
    int va_64 = solu64.minPathSum(test_64);

    Solution_70 solu70{};
    solu70.climbStairs(3);

    Solution_72 solu72{};
    string s1_72{"intention"} , s2_72("execution");
    //solu72.minDistance(s1_72 , s2_72);

    Solution_78 solu78{};
    vector<int> vec_78{1,2,3};
    solu78.subsets(vec_78);

    //Solution_226 solu226{};
    //solu226.invertTree();         ///

    Solution_338 solu338{};
    solu338.countBits(5);

    Solution_238 solu238{};
    vector<int> vec_238{4,3,2,1,2};
    solu238.productExceptSelf(vec_238);

    Solution_105 solu105{};
    vector<int> vec_pre{1,2};
    vector<int> vec_in {1,2};
    //auto res = solu105.buildTree(vec_pre , vec_in);

    Solution_96 solu96{};
    solu96.numTrees(3);

    Solution_312 solu312{};
    vector<int> vec_312{3,1,5,8};
    solu312.maxCoins(vec_312);

    Solution_739 solu739{};
    vector<int> vec_739{30 , 40 , 50 ,60};
    solu739.dailyTemperatures(vec_739);

    Solution_647 solu647{};
    string st_647{"aaa"};
    solu647.countSubstrings(st_647);

    Solution_BFS soluBfs{};
    soluBfs.levelOrder(nullptr);

    Solution_448 solu448{};
    vector<int> vec_448{4,3,2,7,8,2,3,1};
    solu448.findDisappearedNumbers(vec_448);

    Solution_283 solu223{};
    vector<int> vec_223{0,1,0,3,12};
    solu223.moveZeroes(vec_223);

    Solution_287 solu287{};
    vector<int> vec_287{  1,3,4,2,2};
    solu287.findDuplicate(vec_287);

    Solution_300 solu300{};
    vector<int> vec_300{7,7,7,7,7,7,7};
    solu300.lengthOfLIS( vec_300 );

    Solution_347 solu347{};
    vector<int> vec_347{4,1,-1,2,-1,2,3};
    solu347.topKFrequent(vec_347 , 2);

    Solution_215 solu215{};
    vector<int> vec_215{3,2,3,1,2,4,5,5,6};
    solu215.findKthLargest(vec_215 , 4);

    vector<int> vec_Quick{3,2,1,5,6,4};
    int vaa_quick = QuickSelect(vec_Quick , 0 , 5 , 4);

    /// Solution_98 solu98{};
    Solution_332 solu_332{};
    vector<int> vec_332{288,160,10,249,40,77,314,429};
    solu_332.coinChange(vec_332 , 9208);


    Solution_Gigbits54 soluGib54{};
    vector<vector<int>>  matrix54;
    vector<int> v1_54{1,2,3,4};
    vector<int> v2_54{5,6,7,8};
    vector<int> v3_54{9,10,11,12};
    matrix54.push_back(v1_54);
    matrix54.push_back(v2_54);
    matrix54.push_back(v3_54);
    soluGib54.spiralOrder(matrix54);

    vector<vector<int>> matrix ={
            {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}
    };
    bool var = searchMatrix(matrix , 14);


    vector<int> v_test{2,6,4,8,10,9,15};
    Solution_581 solu581{};
    solu581.findUnsortedSubarray(v_test);

    vector<int> v_test2{2,6,4,8};
    inser_sort(v_test2);
    /// Gig test
    Gig_01();


    /// design patern
    /// Factory_test();

    ///Observer test
    /* MIKUSubject* m_s = new MIKUSubject();
    LRDObserver* lrd_obs = new LRDObserver();
    LSAMAObserver* lsam_obs = new LSAMAObserver();
    m_s->RegisterObserver(lrd_obs);
    m_s->RegisterObserver(lsam_obs);

    m_s->notifyObservers();
    m_s->RemoveObserver(lrd_obs);
    m_s->notifyObservers(); */

    //std::shared_ptr<observer> ob_sp = std::make_shared<student>("woc");
    //std::shared_ptr<Clock> c = std::make_shared<Clock>(0);


    //Design_video::Circle c_123{};
    //Design_video::Circle& obk = c_123;

    /// ACM 输入training
    // test_06();
    /// te();

//    int cur_va;
//    string str;
//    while( getline(std::cin , str) ){
//        int target = 0;
//        cin >> target;
//
//        std::istringstream iss(str);
//        int dat;
//        while( iss >> dat ) {
//
//        }
//    }


//    MT::goo_matrix();
    chap4_1::A a;
    a.mFunc();
    std::cout << a.func((long)&a) << std::endl;

    chap4_1::A* base_a = new chap4_1::B();
    base_a->func(444); /// 只有虚函数才会
    base_a->func_b();


    printNumbers2(3);
    //-2^31 ÊÇÕûÊýµÄ×îÐ¡Öµ£¬¼´ -2147483648£¬Ëü¿ÉÒÔÔÚ int ÀàÐÍÖÐ×¼È·µØ±íÊ¾¡£Í¬Ñù£¬2^31-1 ÊÇÕûÊýµÄ×î´óÖµ£¬¼´ 2147483647
    return 0;
}
