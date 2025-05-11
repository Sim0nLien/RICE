#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "src/src.hpp"
#include "utils/utils.hpp"


int main() {
    printf("Begin \n");
    
    int k = 3;
    std::vector<int> in = {5, 7, 8, 9, 10};
    
    std::vector<int> result = RICE(in, k);

    printf("RICE encoded: ");
    print_vector(result);
    
    
    printf("\n");
    printf("End \n");
    
    return 0;
}