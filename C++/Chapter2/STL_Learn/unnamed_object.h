//
// Created by ÂÞÈðµÑ on 2023/11/16.
//

#ifndef CHAPTER7_UNNAMED_OBJECT_H
#define CHAPTER7_UNNAMED_OBJECT_H



template<typename T>
class printt{

public:
    void operator() (const T& elem) {
            //std::cout << elem << std::endl;
    }
};





#endif //CHAPTER7_UNNAMED_OBJECT_H
