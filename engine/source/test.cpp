#include "test.h"

#include <stdio.h>
#include <vector>

void test_print_real(CAL_real r){
    std::vector<float> vec = {};
    vec.reserve(32);
    // Fill the vector
    for(size_t i = 0; i < 32; i++)
        vec.push_back(i++);
    // Print content of the vector
    for(const auto& e : vec)
        printf("%f\n", e);
}