//
// Created by ����� on 2023/11/1.
//

#ifndef CHAPTER7_VARIADIC_CLASS_H
#define CHAPTER7_VARIADIC_CLASS_H

/// Ŀ�ģ�����ģ��󣬲ſ������ػ��Ĳ���
/// \tparam Values
template< typename... Values>
class mytuple;


/// Ŀ�ģ��ݹ�̳г���

template<>
class mytuple<> {
public:
    mytuple(){
        std::cout << "EMPTY" << std::endl;
    }
};



/// Ŀ�ģ��ݹ�̳е���
/// \tparam Head
/// \tparam Tail
template <typename Head , typename... Tail>
// ���ݹ�̳�
class mytuple<Head ,Tail...> : private mytuple<Tail...>
{

public:
    mytuple() {}
    mytuple(Head v , Tail... vtail)
    : m_head(v) , mytuple<Tail...>(vtail...) // ��� vtail��û�в����ˣ�
    {}
protected:
    Head m_head;
};



/// --- ͨ�õ�ģ�� ---
template <int IDX , int MAX , typename... Args>
struct PRINT_TUPLE{

    static void print(ostream& os, const tuple<Args...>& t){
        os << get<IDX>(t) << (IDX+1 == MAX ? "" :",") ; /// ---- get<inex>(tuple) ��ȡԪ���е�һ������
        PRINT_TUPLE<IDX+1 , MAX , Args...>::print(os, t);   // FIXME�����û�ж�IDX �� MAX �Ƿ���ȣ�����Ҫ
     }
};



/// --- ƫ�ػ���ģ�� ---
template <int MAX , typename... Args>
struct PRINT_TUPLE <MAX , MAX , Args...>{
    static void print(ostream& os , const tuple<Args...> &t){
        //std:: cout << "END" << std::endl;
    }
};


template<typename... Args>
ostream& operator << (ostream &os , const tuple<Args...> &t){

    os << "[";
    /// --- index �� size --- ������ --- �ݹ���� ---
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
    /// --- ����ʾ�� ---
    // error: no type named 'type' in 'std::string' Head���type ��һ����һ��class �ܹ��ṩtype�ӿ�
    // typename Head::type head() { return m_head; }
    //auto head() -> decltype(m_head) { return m_head;}

    //decltype(m_head) head() {return m_head; }
    Head head() { return m_head;}

    //decltype(expression)
    tup2<Args...>& tail() {return *this;}  //����ת����һ��-

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
    :m_tail(args...), m_head(v)  {} // �������� class ��Ȼû��<>??

    Head head() {return m_head;}
    compisited& tail() { return m_tail;}
};








#endif //CHAPTER7_VARIADIC_CLASS_H
