#include <test.h>

int main(void){

    #ifdef NAX_DEBUG
        test_print_real(42.0);
    #endif

    return 0;
}