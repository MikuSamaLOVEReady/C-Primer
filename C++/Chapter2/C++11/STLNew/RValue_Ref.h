//
// Created by 罗瑞笛 on 2023/11/10.
//

#ifndef CHAPTER7_RVALUE_REF_H
#define CHAPTER7_RVALUE_REF_H


class myMoveStr{

public:
    static ::size_t Ctor;
    static ::size_t MCtor;
    static ::size_t CAsgn;
    static ::size_t MAsgn;
    static inline ::size_t Dtor  = 0 ; //类内初始化

    constexpr static const double myvalue = 10.5f;
    /// 这俩操作是一致的
    static const int _datai = 5;
    const static int _datal = 151;


private:
    char* _data;
    ::size_t  _len;

    void _init_data(const char* s){
        _data = new char[_len+1];
        ::memcpy(_data , s , _len);
        _data[_len] = '\0';
    }

public:
    myMoveStr() = default;

    //Ctr
    myMoveStr(const char* p): _len(::strlen(p)){
        ++Ctor;
        _init_data(p);
    }

    //copy Ctr
    myMoveStr(const myMoveStr& str): _len(str._len){
        ++Ctor;
        _init_data(str._data); //深拷贝
    };

    /// move Ctr  &&{ rvalue ref }
    myMoveStr(myMoveStr&& str) noexcept
    : _data(str._data) , _len(str._len) //复制原data 和 长度
    {
        ++MCtor;
        //切断之前的指针连接
        str._len = 0;
        str._data = NULL;   // FIXME：为什么非要设置为NULL
    }


    // copy assignment
    myMoveStr& operator = (const myMoveStr& str) noexcept {
        ++CAsgn;
        //直接判定两个对象是否相等（通过地址直接判定）， 而不是判定内容
        if( this != &str){
            if(_data != nullptr){ delete _data; }
            _len = str._len;
            _init_data(str._data);
        }
        return *this;
    }

    /// move assignment
    myMoveStr& operator = (myMoveStr&& str) noexcept{
        ++MAsgn;
        if(this != &str){
            if(_data) delete _data;
            _len = str._len;
            _data = str._data;
            str._len = 0;
            str._data = NULL;
        }
        return *this;
    }

    // de-Ctr
    virtual ~myMoveStr(){
        ++Dtor;
        if(_data){
            delete _data;
        }
    }



};

// 接受左值
void process(int& i){

    std::cout << "process" << i << std::endl;
}

// 接受右值
void process(int&& i){

    std::cout << "process rvalue " << i << std::endl;
}

// 这里按理来说已经变成右值了
void forward(int&& i){
    std::cout << "FORWARD: int&& i " << i << std::endl;
    process(i); // FIXME： 这里还是会自动按左值传递.....

}




#endif //CHAPTER7_RVALUE_REF_H
