//
// Created by ����� on 2023/11/10.
//

#ifndef CHAPTER7_RVALUE_REF_H
#define CHAPTER7_RVALUE_REF_H


class myMoveStr{

public:
    static ::size_t Ctor;
    static ::size_t MCtor;
    static ::size_t CAsgn;
    static ::size_t MAsgn;
    static inline ::size_t Dtor  = 0 ; //���ڳ�ʼ��

    constexpr static const double myvalue = 10.5f;
    /// ����������һ�µ�
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
        _init_data(str._data); //���
    };

    /// move Ctr  &&{ rvalue ref }
    myMoveStr(myMoveStr&& str) noexcept
    : _data(str._data) , _len(str._len) //����ԭdata �� ����
    {
        ++MCtor;
        //�ж�֮ǰ��ָ������
        str._len = 0;
        str._data = NULL;   // FIXME��Ϊʲô��Ҫ����ΪNULL
    }


    // copy assignment
    myMoveStr& operator = (const myMoveStr& str) noexcept {
        ++CAsgn;
        //ֱ���ж����������Ƿ���ȣ�ͨ����ֱַ���ж����� �������ж�����
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

// ������ֵ
void process(int& i){

    std::cout << "process" << i << std::endl;
}

// ������ֵ
void process(int&& i){

    std::cout << "process rvalue " << i << std::endl;
}

// ���ﰴ����˵�Ѿ������ֵ��
void forward(int&& i){
    std::cout << "FORWARD: int&& i " << i << std::endl;
    process(i); // FIXME�� ���ﻹ�ǻ��Զ�����ֵ����.....

}




#endif //CHAPTER7_RVALUE_REF_H
