//
// Created by 罗瑞笛 on 2023/4/1.
//

//#include "string_chapter3.h"
//我总算知道 为啥这里不能用#include了，
/*
 * #ifndef 和 #define 的作用是在头文件被多次包含时，保证其只被编译一次。也就是说，
 * 它只能保证同一个目标文件中不会有重复定义，而不能保证在多个目标文件中不会有重复定义。
 * 由于在两个不同的目标文件(main.cpp.o 和 multi_array.cpp.o)中都包含了头文件multi_array.h，
 * 所以其中的函数multi_array::multi_dim_array()在两个目标文件中都被定义了一次，导致了重复定义的错误。
 * 为了避免这个错误，你需要将函数的实现放到一个单独的.cpp文件中，并且只在该文件中包含头文件multi_array.h。
 * 或者，你可以将函数声明为inline，这样可以在多个目标文件中使用该函数的实现而不会报重复定义的错误。
 */
