//
// Created by ����� on 2023/8/3.
//

#ifndef CHAPTER7_FILESTEAM_H
#define CHAPTER7_FILESTEAM_H

#include <fstream>

void fun_fstream(){
    std::vector<string> result;
    std::ifstream  input("info.txt");
    std::ofstream  output("output.txt");
    int buffersize = 10;
    char buffer[buffersize];
    //��������ת�͵� iostream
    if(input.is_open()){
        // ��ȡָ����С
        input.read(buffer,buffersize);
        //std::cout.write(buffer, input.gcount()); // ���ʵ�ʶ�ȡ���ַ�����
        for(char c : buffer){
            std::cout << c << "��Ӧ������"<<  (int)c << std::endl;
        }
        //��input �� ��ȡһ��
        string buf;
        while (std::getline(input,buf)){
            result.push_back(buf);
         }

        //
        string word;
        while(input >> word){
            result.push_back(word);
        }

        std::cout << "output" << std::endl;
    }
    std::cout << 'woc' << std::endl;
}


void fun_inout_test(){
    std::ofstream out("data_out.txt"); // ���� ������open std::ofstream out2("data_out.txt",ofstream::out|ofstream::trunc);



}




#endif //CHAPTER7_FILESTEAM_H
