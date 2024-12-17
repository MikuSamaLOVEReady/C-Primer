//
// Created by ÂÞÈðµÑ on 2024/5/9.
//

#ifndef CHAPTER7_RULES_09_H
#define CHAPTER7_RULES_09_H

namespace effective_09 {

    class  base {
    public:

        virtual void prit(){
            std::cout << "base woc!" << std::endl;
        }

        virtual ~base(){
            prit();
        }

    };


    class derive : public base{
    public:
        void prit() override{
            std::cout << "child woc!" << std::endl;
        }

        ~derive(){
            prit();
        }

    };

}


#endif //CHAPTER7_RULES_09_H
