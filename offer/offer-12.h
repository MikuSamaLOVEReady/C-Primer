//
// Created by ����� on 2023/7/14.
//

#ifndef OFFER_OFFER_12_H
#define OFFER_OFFER_12_H

string intToRoman(int num) {

    //����һ��ӳ���
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
        //������������
       for(auto it = value2roma.rbegin() ; it != value2roma.rend() ; ++it){
           //�ҵ� ���Լ��
           if( num < it->first ) continue;
           //�����ֵ�����ܱ�ʾ
           if(value2roma.find(num) != value2roma.end())
           {
               result += value2roma[it->first];
               num = 0; // ֱ�����0
               break;
           }
            // �����λֵ���ȱ�ʾ
           int yushu = num % (it->first);
           int high  = num / (it->first);  //�ȰѸ�λת�����ַ� , high �Ǽ���Ҫ���뼸����Ӧ�ַ�
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
