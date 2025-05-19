#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "src/src.hpp"
#include "utils/utils.hpp"


int main() {
    printf("Begin \n");
    
    int k = 2;
    std::vector<int> in = {5, 7, 8, 9, 10};
    
    std::vector<int> result = RICE(in, k);

    printf("RICE encoded: ");
    print_vector(result);
    
    std::vector<int> decoded;

    decoded = RICE_decode(result, k);
    printf("RICE decoded: ");
        
    print_vector(decoded);


    printf("\n");
    printf("End \n");
    
    return 0;

    //PROBLEME DANS L'ORDRE JE PENSE
}