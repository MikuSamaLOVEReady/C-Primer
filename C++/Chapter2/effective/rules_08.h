//
// Created by 罗瑞笛 on 2024/5/20.
//

#ifndef CHAPTER7_RULES_08_H
#define CHAPTER7_RULES_08_H


namespace effective_08 {

    class  object {
    public:


        virtual ~object(){
            /// 可能抛出异常 、如果是
            ///
            ///     {
            ///         vector<object> obj 情况、
            ///     }
            ///
            ///
        }

    };


    class derive : public object{
    public:


        ~derive(){

        }

    };

}

#endif //CHAPTER7_RULES_08_H
