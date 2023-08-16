//
// Created by ����� on 2023/8/11.
//

#ifndef CHAPTER7_EXCEPTION_TEST_H
#define CHAPTER7_EXCEPTION_TEST_H

void riskyFunction() {
    // ��������������׳�һ���쳣
    throw std::runtime_error("Something went wrong!");
}

//���ڲ����쳣ʱ�������ܹ�����ִ��
void continue_run(){
    try {
        std::cout << "Executing risky function..." << std::endl;
        riskyFunction();
        std::cout << "Risky function executed successfully." << std::endl;
    } catch (const std::exception& e) {
        // �����쳣������
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    // �������ִ��
    std::cout << "Continuing with the rest of the program." << std::endl;
    return ;
}

void continue_without_run(){
    std::cout << "Executing risky function..." << std::endl;
    riskyFunction();
    std::cout << "Continuing with the rest of the program." << std::endl;
    return;
}

#endif //CHAPTER7_EXCEPTION_TEST_H
