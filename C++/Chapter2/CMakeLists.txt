cmake_minimum_required(VERSION 3.24)
project(Chapter7)



set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_PREFIX_PATH "C:/Users/YX/Desktop/package/eigen-3.4.0")
#find_package(Eigen3 REQUIRED)
#target_include_directories(Chapter7 PUBLIC ${EIGEN3_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(EIGEN_DIR "C:/Users/YX/Desktop/package/eigen-3.4.0")
include_directories(${EIGEN_DIR})
include_directories(/usr/local/include/eigen3)

file(  GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/*.cpp" "${PROJECT_SOURCE_DIR}/*.h"
        )

message( ${SRC_FILES} )

add_executable(Chapter7 main.cpp file_1.cpp file_1.h chapter2.6.cpp chapter2.6.h string_chapter3.cpp string_chapter3.h
        multi_array.cpp multi_array.h function.cpp function.h arrays.cpp arrays.h Chapter7/Sales_data.cpp Chapter7/Sales_data.h
        Chapter7/Screen.cpp Chapter7/Screen.h effective/chapter-0.h Unordered/unordered_map.h Unordered/unordered_set.h Chapter7/firend_class.h
        Chapter11/associative-container.h Chapter11/pair.h Chapter7/defaule_vale.h Chapter7/Data.h Chapter7/Data.cpp Chapter8/iostream_test.h
        Chapter9/sequence_contain.h Chapter9/empalce_vs_push.h Houjie/iterator_detail.h Chapter9/forward_list.h Chapter9/resize_fun.h  Chapter9/Adapter.h
        Chapter15/base_and_derive.h Chapter15/inherit.h inherit.cpp Chapter15/virtual_fun.h Chapter15/protected_inherit.h Chapter10/Coursework10_1.h Chapter10/read_only.h Chapter10/send_func_to_Algorithm.h
        Chapter10/Lambda_expression.h Chapter10/bind_parameter.h Chapter12/smart_ptr.h Chapter12/smart_ptr.cpp Chapter15/deCons.h Chapter8/filesteam.h Chapter8/sstream.h Chapter12/dyna_const.h
        Chapter5/exception_test.h Chapter12/deltetor.h
        Chapter12/trickofSp.h Chapter12/unique.h EgienLearn/Eigen_test.h Tree-Algorithm/KD-Tree.h edabit/QuadraticEquation.h C++11/Variadic_test.h C++11/Variadic_class.h C++11/Extra_nullptr_t.h C++11/InitializeList.h
        C++11/explicit_more_than_1.h C++11/default+delete.h C++11/Aliastemp.h C++11/Type_Alias.h C++11/decltype_test.h C++11/variadic_printf.h C++11/STLNew/RValue_Ref.h C++11/STLNew/STLhash.h C++11/Suggest55/DefiniVSDeclar.cpp C++11/Suggest55/Pure_virDef.h
        C++11/Suggest55/Pure_virDef.cpp C++11/Suggest55/suggTemlateMeth.h C++11/Suggest55/suggTemlateMeth.cpp C++11/Suggest55/CopyCtr_Sp.cpp Chapter13/swap_opera13_3.h Chapter13/swap_opera13_3.cpp Chapter12/allocator_learn.cpp Chapter12/allocator_learn.h STL_Learn/Priority_learn.h STL_Learn/Priority_learn.cpp
        C++11/functional_std/functional_test.h C++11/Suggest55/Pointer_implment.cpp
        init_test.h after_global.h after_global.cpp   Chapter13/move_test.h  Chapter13/move_test.cpp STL_Learn/std_functionLearn.h C++11/smart_ptr/recursive_shared_ptr.h Chapter12/My_Sp.h C++20/Chpter19/func_ptr.h C++20/Chpter19/call_back_learn.h C++20/Chpter19/functor_learn.h effective/rules_09.h effective/rules_08.h C++20/Chpter16/excp_test.h DeepCppObj/Chapter1/int_template.h effective/rules_41_template.h effective/rules_43_base_temp_typename.h Deep_OO/chapter_0.h Memory_leak/case1_notvirtual_dectr.h effective/rules_30_inline.h "Chapter11/unordered_(multi)map.h" YuanRon/M1.h STL_Learn/Two_queue_stack.h)


