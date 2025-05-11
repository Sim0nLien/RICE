#ifndef SRC_HPP
#define SRC_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../utils/utils.hpp"



template <class T> std::vector<T> int2bin(const T in, const T k){
    T val = in;
    
    std::vector<T> result;
    

    if(val == 0) {
        result.push_back(0);
        return result;
    }
    
    while(val > 0) {
        result.push_back(val % 2);
        val = val / 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
}


template <class T> std::vector<T> RICE_encode(const T in, const T k) {

    T param; T quotient;
    T remainder;

    std::vector<T> result;
    std::vector<T> param_vec;

    param = pow(2, k);


    quotient = in / param;
    remainder = in % param;
    
    for(int i = 0; i < quotient; ++i) {
        result.push_back(1);
    }
    result.push_back(0);

    
    param_vec = int2bin(remainder, param);

    for(int i = 0; i < param_vec.size(); ++i) {
        result.push_back(param_vec[i]);
    }
    
	return result;
}

template <class T> std::vector<T> RICE(std::vector<T> in, const T k) {
    std::vector<T> result;
    for(int i = 0; i < in.size(); ++i) {
        std::vector<T> temp = RICE_encode(in[i], k);
        result.insert(result.end(), temp.begin(), temp.end());
    }
    return result;
}



#endif // SRC_HPP


