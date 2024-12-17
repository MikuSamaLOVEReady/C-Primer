//
// Created by 罗瑞笛 on 2024/8/22.
//

#ifndef CHAPTER7_RULES_30_INLINE_H
#define CHAPTER7_RULES_30_INLINE_H

#define MIKU_SAMA 520

struct mystruct_it{
    int va;
};


/// class的定义式
class Person{
public:
    typedef mystruct_it iterator_category;
//    using
//    int age() const { return MIKU_SAMA; } /// 直接在class内申请

private:
    int theAge;
};

#endif //CHAPTER7_RULES_30_INLINE_H
