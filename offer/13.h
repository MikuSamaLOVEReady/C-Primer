//
// Created by ����� on 2023/7/14.
//

#ifndef OFFER_13_H
#define OFFER_13_H

int RomaToint(string s) {
    //����һ��ӳ���
    map< char , int> roma{
            {'I', 1} ,{'V',5},{'X',10},{'L',50},{'C',100},
            {'D',500} ,{'M',1000}
    };


    int sum = 0;
    for(int i = 0 ; i < s.size() ; ++i){
        //��Ҫ���̽��һλ
        int after_i = i+1;
        if( after_i != s.size() ){
            if( s[i] =='I' && s[after_i]=='V'){
                sum += 4;
                i += 1;
                continue;
            } else if( s[i] == 'I' && s[after_i] == 'X'){
                sum += 9;
                i += 1;
                continue;
            }else if(s[i] == 'X' && s[after_i] == 'L'){
                sum += 40;
                i += 1;
                continue;
            }else if(s[i] == 'X' && s[after_i] == 'C'){
                sum += 90;
                i += 1;
                continue;
            }else if(s[i] == 'C' && s[after_i] == 'D'){
                sum += 400;
                i += 1;
                continue; // continue��Ȼ�����+1�Ĳ���
            }else if(s[i] == 'C' && s[after_i] == 'M'){
                sum += 900;
                i += 1;
                continue;
            }else{
                sum += roma[s[i]];
            }
        }
        else{
            sum += roma[s[i]];
        }
    }

    return sum;
}
#endif //OFFER_13_H
