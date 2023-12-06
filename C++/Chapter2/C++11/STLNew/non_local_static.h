//
// Created by YX on 2023/12/5.
//

#ifndef CHAPTER7_NON_LOCAL_STATIC_H
#define CHAPTER7_NON_LOCAL_STATIC_H


class FileSystem{
public:
    //defual
    FileSystem() = default;

};


FileSystem& tfs(){
    static FileSystem fs; //初始化
    return fs;
}


// 取消compiler自带的 big 3
class Uncopable{

private:
    Uncopable(const Uncopable&);
    Uncopable& operator = (const Uncopable& lhs);
};

class MIKU : Uncopable{


};


#endif //CHAPTER7_NON_LOCAL_STATIC_H
