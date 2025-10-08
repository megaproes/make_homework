#include "calc.h"
int divide(double a, double b, double *out){
    if(b == 0.0) return -1;          
    *out = a / b;
    return 0;
}
