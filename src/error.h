#pragma once

#ifndef ERROR_H_
#define ERROR_H_

#define ERR_VEC_ABT(vec, message) if (vec.size() < 2) { std::cout << message << std::endl; exit(-1); }
#define ERR_IDX_ABT(arr, idx, message) if (idx > arr.size()) { std::cout << message << std::endl; exit(-1); }

#endif // ERROR_H_