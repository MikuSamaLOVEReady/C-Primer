//
// Created by ����� on 2024/5/20.
//

#ifndef CHAPTER7_RULES_08_H
#define CHAPTER7_RULES_08_H


namespace effective_08 {

    class  object {
    public:


        virtual ~object(){
            /// �����׳��쳣 �������
            ///
            ///     {
            ///         vector<object> obj �����
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
