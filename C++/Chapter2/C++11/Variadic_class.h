//
// Created by 罗瑞笛 on 2023/11/1.
//

#ifndef CHAPTER7_VARIADIC_CLASS_H
#define CHAPTER7_VARIADIC_CLASS_H

/// 目的：声明模版后，才可以做特化的操作
/// \tparam Values
template< typename... Values>
class mytuple;


/// 目的：递归继承出口

template<>
class mytuple<> {
public:
    mytuple(){
        std::cout << "EMPTY" << std::endl;
    }
};



/// 目的：递归继承调用
/// \tparam Head
/// \tparam Tail
template <typename Head , typename... Tail>
// ，递归继承
class mytuple<Head ,Tail...> : private mytuple<Tail...>
{

public:
    mytuple() {}
    mytuple(Head v , Tail... vtail)
    : m_head(v) , mytuple<Tail...>(vtail...) // 最后 vtail中没有参数了，
    {}
protected:
    Head m_head;
};



/// --- 通用的模版 ---
template <int IDX , int MAX , typename... Args>
struct PRINT_TUPLE{

    static void print(ostream& os, const tuple<Args...>& t){
        os << get<IDX>(t) << (IDX+1 == MAX ? "" :",") ; /// ---- get<inex>(tuple) 获取元组中的一块内容
        PRINT_TUPLE<IDX+1 , MAX , Args...>::print(os, t);   // FIXME：如果没判定IDX 和 MAX 是否相等，则需要
     }
};



/// --- 偏特化的模版 ---
template <int MAX , typename... Args>
struct PRINT_TUPLE <MAX , MAX , Args...>{
    static void print(ostream& os , const tuple<Args...> &t){
        //std:: cout << "END" << std::endl;
    }
};


template<typename... Args>
ostream& operator << (ostream &os , const tuple<Args...> &t){

    os << "[";
    /// --- index 与 size --- 的区别 --- 递归入口 ---
    PRINT_TUPLE< 0, sizeof...(Args) , Args...>::print(os, t);
    return os << "]";
}




/// review  -- Template Specialization --
template<typename... Args>
class tup2{

};

template<>
class tup2<>{

};

template <typename Head , typename... Args>
class tup2<Head , Args...> : private tup2<Args...>
{
    typedef tup2<Args...> inherited;

public:
    tup2() {}
    tup2(Head v , Args... vTail): m_head(v),
    tup2<Args...>(vTail...){
        std::cout << "woc!" << std::endl;
    }

protected:
    Head m_head;

public:
    /// --- 错误示范 ---
    // error: no type named 'type' in 'std::string' Head这个type 不一定是一个class 能够提供type接口
    // typename Head::type head() { return m_head; }
    //auto head() -> decltype(m_head) { return m_head;}

    //decltype(m_head) head() {return m_head; }
    Head head() { return m_head;}

    //decltype(expression)
    tup2<Args...>& tail() {return *this;}  //向上转型了一下-

};


template<typename... Values> class compositetup;
template<> class compositetup<>{};

template<typename Head, typename... Args>
class compositetup <Head , Args...> {

    typedef compositetup<Args...> compisited;

protected:
    Head m_head;
    compisited m_tail;

public:
    compositetup(){};
    compositetup(Head v , Args... args)
    :m_tail(args...), m_head(v)  {} // 这里很奇怪 class 居然没有<>??

    Head head() {return m_head;}
    compisited& tail() { return m_tail;}
};








#endif //CHAPTER7_VARIADIC_CLASS_H
