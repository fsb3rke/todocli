#pragma once

#ifndef ERROR_H_
#define ERROR_H_

#define ERR_ARR_ABT(vec, message) if (vec.size() < 2) { std::cout << message << std::endl; exit(-1); }

#endif // ERROR_H_