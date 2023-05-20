//
// Created by 罗瑞笛 on 2023/5/13.
//

#ifndef OFFER_OFFER_16_H
#define OFFER_OFFER_16_H

double myPow(double x, int n) {

    long long int positive_n = n;
    bool divide = false;
    if(n<0){
        divide = true;
        positive_n = -static_cast<long long int>(n);
    }
    else if( n == 0)
        return 1;

     //有一点浪费 存放x^(2^index) 次方的结果
     // buffer[0] = x^1
     // buffer[1] = x^2
     // buffer[2] = x^4
     // buffer[3] = x^8
     // buffer[4] = x^16
     // buffer[5] = x^32

    // int power_arr[32] = {1,2,4,8,16,32,64,128,256,512 ,1024, 2048}; 记录次方数
    long long int power_arr[32] = {0};
    long long int  val = 1;
    power_arr[0] = 1;
    for (int i = 1 ; i <32 ;++i){
        val *= 2;
        power_arr[i] = val;
    }

    //max_xn_index 表示需要算到最多哪个x^index就可以停止
    int max_xn_index = 0;
    while(max_xn_index <= 32 && power_arr[max_xn_index]<= positive_n){
        max_xn_index++;
    }

     double buffer[32] = {0};
     buffer[0] = x;
     for(int i = 1 ; i< max_xn_index ; i++){
         buffer[i] = buffer[i-1] * buffer[i-1];
     }

     double result = 1;
     int neast_index = max_xn_index-1;

     if(power_arr[neast_index] == positive_n){
         if(divide){
             return  1.0/ buffer[neast_index];
         }
         return buffer[neast_index];
     }

     int i = 0;
     int cur_n = positive_n;
     while(neast_index != 0){
         //减去最近（大）的指数项后剩下的指数,但需要先更新这个最近的值
         result *= buffer[neast_index];
         cur_n = cur_n-power_arr[neast_index];
         //从power_arr中找到 离剩下的指数最近的index
         i = 0;
         while(power_arr[i] < cur_n){
             i++;
         }
         if(power_arr[i] == cur_n)
         {
             //此时刚好是i ，结束运算
             neast_index = i;
             result *= buffer[neast_index];
             break;
         }
         //更新neast_index,把最近的X^n 乘上去
         neast_index = i-1;
         //result *= buffer[neast_index];
     }

     if(divide){
         return  1.0/ result;
     }

    return  result;
}


#endif //OFFER_OFFER_16_H
