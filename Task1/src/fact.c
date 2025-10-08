#include "calc.h"

/* safe only up to 20 (fits in 64bit) */
int factorial(unsigned int n, unsigned long long *out){
    if(n > 20) return -1;            
    unsigned long long r = 1;
    for(unsigned int i = 2;i <= n; i++) r *= i;
    *out = r;
    return 0;
}
