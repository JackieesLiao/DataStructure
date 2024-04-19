#ifndef PUBLIC_H
#define PUBLIC_H
#include <memory>
#include <iostream>
using Status = int;
using ElemType = int;
constexpr int kMaxSize = 20;
constexpr int OK = 1;
constexpr int ERROR = -1;
constexpr int TRUE = 1;
constexpr int FALSE = -1;
static Status Visit(ElemType&e) {
	std::cout << "elements: " << e << " ";
	return OK;
}

#endif // ! PUBLIC_H