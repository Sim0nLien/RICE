#ifndef SRC_HPP
#define SRC_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../utils/utils.hpp"



template <class T> std::vector<T> int2bin(const T in, const T k){
    T val = in;

    std::vector<T> result(k, 0);
    

    for (int i = k - 1; i >= 0; i--) {
        result[i] = val & 1;
        val >>= 1;
    }

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
    printf("in: %d, param: %d, quotient: %d, remainder: %d\n", in, param, quotient, remainder);
    
    for(int i = 0; i < quotient; ++i) {
        result.push_back(1);
    }
    result.push_back(0);

    
    param_vec = int2bin(remainder, k);

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


template <class T> std::vector<T> RICE_decode(const std::vector<T>& in, const T k) {
    std::vector<T> result;
    T param = pow(2, k);
    T quotient = 0;
    T remainder = 0;

    for (int i = 0; i < in.size(); ++i) {
        if (in[i] == 1) {
            quotient++;
        } else {
            remainder = 0;
            for (int j = 0; j < k; ++j) {
                if (i + j + 1 < in.size()) {
                    remainder = (remainder << 1) | in[i + j + 1];
                }
            }
            result.push_back(quotient * param + remainder);
            quotient = 0;
            i += k;
        }
    }

    return result;
}
#endif // SRC_HPP


