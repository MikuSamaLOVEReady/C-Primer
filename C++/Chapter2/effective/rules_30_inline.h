//
// Created by ����� on 2024/8/22.
//

#ifndef CHAPTER7_RULES_30_INLINE_H
#define CHAPTER7_RULES_30_INLINE_H

#define MIKU_SAMA 520

struct mystruct_it{
    int va;
};


/// class�Ķ���ʽ
class Person{
public:
    typedef mystruct_it iterator_category;
//    using
//    int age() const { return MIKU_SAMA; } /// ֱ����class������

private:
    int theAge;
};

#endif //CHAPTER7_RULES_30_INLINE_H
