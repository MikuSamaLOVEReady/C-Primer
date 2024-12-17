//
// Created by ÂÞÈðµÑ on 2024/5/2.
//

#ifndef CHAPTER7_CALL_BACK_LEARN_H
#define CHAPTER7_CALL_BACK_LEARN_H

#include <string>

/// bool (*)(const std::string& s , const std::string& s2); -> function_ptr type

using Comp = bool (*)(const std::string& s , const std::string& s2);

template <typename T>
using Comparison_ptr = bool (*)(const T& , const T&);



#endif //CHAPTER7_CALL_BACK_LEARN_H
