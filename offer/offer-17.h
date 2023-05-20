//
// Created by 罗瑞笛 on 2023/5/14.
//

#ifndef OFFER_OFFER_17_H
#define OFFER_OFFER_17_H

#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

vector<int> printNumbers(int n) {
    vector<int> result = {};
    int max = 1;

    while( n--){
            max *= 10;
    }

    // 获取程序开始执行的时间点
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < max; i++)
    {
        std::cout << i << std::endl;
        result.push_back(i);
    }
    // 获取程序结束执行的时间点
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "程序运行消耗的时间: " << duration.count() / 1000.0 << " 毫秒" << std::endl;

    string ss;
    for (int i = 1; i < max; i++)
    {
        ss = i + '0';
        std::cout << ss << std::endl;
    }

    return result;
}


vector<int> nums;
string s;
// eg: 1000 千 百 十 个
// end基本不变， index表示 s[0]->表示高位（千） s[1]->表示高位（百）
// 每次递归结束有两种可能-> 但都表示填写完了以index位为标准，比它更低位的所有0-9的排列可能
//
void dfs(int end, int index) {

    if (index == end) {
        nums.push_back(stoi(s));
        return;
    }

    for (int i = 0; i <= 9; ++i) {
        s[index] = i + '0';
        dfs(end, index + 1);
    }

}

vector<int> printNumbers2(int n) {
    s.resize(n, '0');
    dfs(n, 0);
    return nums;
}

#endif //OFFER_OFFER_17_H
