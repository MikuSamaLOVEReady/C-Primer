cmake_minimum_required(VERSION 3.24)
project(Chapter7)

set(CMAKE_CXX_STANDARD 17)
include_directories(/usr/local/include/eigen3)


add_executable(Chapter7 main.cpp file_1.cpp file_1.h chapter2.6.cpp chapter2.6.h string_chapter3.cpp string_chapter3.h
        multi_array.cpp multi_array.h function.cpp function.h arrays.cpp arrays.h Chapter7/Sales_data.cpp Chapter7/Sales_data.h
        Chapter7/Screen.cpp Chapter7/Screen.h effective/chapter-0.h Unordered/unordered_map.h Unordered/unordered_set.h Chapter7/firend_class.h
        Chapter11/associative-container.h Chapter11/pair.h Chapter7/defaule_vale.h Chapter7/Data.h Chapter7/Data.cpp Chapter8/iostream_test.h
        Chapter9/sequence_contain.h Chapter9/empalce_vs_push.h Houjie/iterator_detail.h Chapter9/forward_list.h Chapter9/resize_fun.h  Chapter9/Adapter.h
        Chapter15/base_and_derive.h Chapter15/inherit.h inherit.cpp Chapter15/virtual_fun.h Chapter15/protected_inherit.h Chapter10/Coursework10_1.h Chapter10/read_only.h Chapter10/send_func_to_Algorithm.h
        Chapter10/Lambda_expression.h Chapter10/bind_parameter.h Chapter12/smart_ptr.h Chapter12/smart_ptr.cpp Chapter15/deCons.h Chapter8/filesteam.h Chapter8/sstream.h Chapter12/dyna_const.h
        Chapter5/exception_test.h Chapter12/deltetor.h
        Chapter12/trickofSp.h Chapter12/unique.h EgienLearn/Eigen_test.h Tree-Algorithm/KD-Tree.h edabit/QuadraticEquation.h C++11/Variadic_test.h C++11/Variadic_class.h C++11/Extra_nullptr_t.h C++11/InitializeList.h C++11/explicit_more_than_1.h C++11/default+delete.h C++11/Aliastemp.h C++11/Type_Alias.h C++11/decltype_test.h C++11/variadic_printf.h C++11/STLNew/RValue_Ref.h C++11/STLNew/STLhash.h)


