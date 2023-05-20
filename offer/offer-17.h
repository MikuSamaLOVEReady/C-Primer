//
// Created by ����� on 2023/5/14.
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

    // ��ȡ����ʼִ�е�ʱ���
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < max; i++)
    {
        std::cout << i << std::endl;
        result.push_back(i);
    }
    // ��ȡ�������ִ�е�ʱ���
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "�����������ĵ�ʱ��: " << duration.count() / 1000.0 << " ����" << std::endl;

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
// eg: 1000 ǧ �� ʮ ��
// end�������䣬 index��ʾ s[0]->��ʾ��λ��ǧ�� s[1]->��ʾ��λ���٣�
// ÿ�εݹ���������ֿ���-> ������ʾ��д������indexλΪ��׼����������λ������0-9�����п���
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
