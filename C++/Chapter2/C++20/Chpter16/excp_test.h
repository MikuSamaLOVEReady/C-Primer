//
// Created by ÂÞÈðµÑ on 2024/5/20.
//

#ifndef CHAPTER7_EXCP_TEST_H
#define CHAPTER7_EXCP_TEST_H


namespace morden_20 {

    void exptest1(int test ){


        try {
            if(test >5 )
                throw "woc! EXCPPP";
        }
        catch ( const char* message ) {

            std::cout << message << std::endl;
        }

    }



}


#endif //CHAPTER7_EXCP_TEST_H
