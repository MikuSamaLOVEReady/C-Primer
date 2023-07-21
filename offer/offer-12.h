//
// Created by 罗瑞笛 on 2023/7/14.
//

#ifndef OFFER_OFFER_12_H
#define OFFER_OFFER_12_H

string intToRoman(int num) {

    //建立一张映射表
    /*
    map< int , string> roma{
            {1,"I"} , {5 , "V"} , {10 , "X"} , {50 , "L"},
            {100,"C"}, {500, "D"} , {1000 ,"M"}
    };*/

    map< int , string> value2roma{
            {1,"I"} ,  {4 ,"IV"}, {5 , "V"} ,  {9,"IX"} , {10 , "X"} ,
            {40,"XL"},{50 , "L"},{90,"XC"},{100,"C"},
            {400 ,"CD" } ,  {500, "D"} ,  {900, "CM"} , {1000 ,"M"}

    };

    string result = "";
    while(num != 0){
        //遍历所有因子
       for(auto it = value2roma.rbegin() ; it != value2roma.rend() ; ++it){
           //找到 最大公约数
           if( num < it->first ) continue;
           //如果有值正好能表示
           if(value2roma.find(num) != value2roma.end())
           {
               result += value2roma[it->first];
               num = 0; // 直接设回0
               break;
           }
            // 拆出高位值优先表示
           int yushu = num % (it->first);
           int high  = num / (it->first);  //先把高位转化成字符 , high 是几就要加入几个对应字符
           num = yushu;
           while(high){
               result += value2roma[it->first];
               --high;
           }
       }
    }

    return result;
}

#endif //OFFER_OFFER_12_H
