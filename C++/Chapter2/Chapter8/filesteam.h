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


void file_read_double(){
    std::ifstream  input("info.txt");
    double doubleValue;
    if( !(input >> doubleValue)){
        std::cout << "emd;";
    } // Reads a double f
}

void add_space(){
    std::ifstream inf("data2.txt");
    std::ofstream otf("revise2.txt");
    if( (!inf.is_open() ) || (!otf.is_open())){
        std::cout <<  "can not open " << std::endl;
    }
    string s_line;
    while(getline(inf,s_line)){

        s_line.insert(185 ,"   ");
        s_line.insert( 200 , "   ");

        otf << s_line << std::endl;
        std::cout << s_line << std::endl;
    }

}




#endif //CHAPTER7_FILESTEAM_H
