//
// Created by 罗瑞笛 on 2023/8/11.
//

#ifndef CHAPTER7_EXCEPTION_TEST_H
#define CHAPTER7_EXCEPTION_TEST_H

void riskyFunction() {
    // 假设这个函数会抛出一个异常
    throw std::runtime_error("Something went wrong!");
}

//存在捕获异常时，程序能够继续执行
void continue_run(){
    try {
        std::cout << "Executing risky function..." << std::endl;
        riskyFunction();
        std::cout << "Risky function executed successfully." << std::endl;
    } catch (const std::exception& e) {
        // 捕获异常并处理
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    // 程序继续执行
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
