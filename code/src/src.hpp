



#ifndef SRC_HPP
#define SRC_HPP

#include <iostream>
#include <vector>


template <class T> std::vector<T> RICE_encode(const T value, const int k) {
	std::vector<T> result;
    quotient = value / k;
    remainder = value % k;
    for(int i = 0; i < quotient; ++i) {
        result.push_back(1);
    }
    result.push_back(0);
 
	return result;
}


#endif // SRC_HPP


