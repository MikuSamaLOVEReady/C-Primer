//
// Created by 罗瑞笛 on 2024/5/24.
//

#ifndef OFFER_FULL_BINARY_SERACH_TREE_H
#define OFFER_FULL_BINARY_SERACH_TREE_H

///  第一行包含若干个用空格分隔的正整数,表示给定的数列。
///  第二行包含一个正整数,表示待查找的数。

/// 输出格式
/// 输出查找的路径和结果。
/// 路径从根节点开始,用 S 表示。查找左子树用 L 表示,查找右子树用 R 表示。
/// 查找到结果用 Y 表示,未找到结果用 N 表示。

#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;
/// dfs
void bin_search_paht( int left , int right , std::vector<char>& path , std::vector<int>& data , int target) {

    /// 超级重要
    if(left > right){
        path.push_back('N');
    }

    int mid = ( left + right ) / 2;

    if( data[mid] == target){
        path.push_back('Y');
        return;
    }
    else if ( data[mid] > target ){
        right = mid - 1;
        path.push_back('L');
        bin_search_paht(left,right,path,data,target);
    }else{
        left  = mid + 1;
        path.push_back('R');
        bin_search_paht(left,right,path,data,target);
    }

}

int istringstream_learn () {

    /// 插入排序
    std::vector<int> data;
    std::vector<char> Path;
    std::string str;
//    while( getline(std::cin , str) ){
//
//        std::string s;
//        istringstream iss_2(str);
//        while( getline(iss_2 , s , ','))
//        {
//            std::cout << s  << std::endl;
//        }
//    }

    int va = 0;
    while ( getline( std::cin , str) )
    {
        int target  = 0;
        cin >> target;

        std::istringstream  iss(str);
        int dat;
        while( iss >> dat ){
            data.push_back(dat);
        }
        std::sort(data.begin() , data.end());
        std::cout << "" << std::endl;

        /// binary_search
        bin_search_paht(0 , data.size()-1 ,Path , data , target);
        Path.insert(Path.begin(), 'S');

        for( char ch : Path)
        {
            std::cout<< ch;
        }
        std::cout << endl;
    }

    return 1;
}



#endif //OFFER_FULL_BINARY_SERACH_TREE_H
