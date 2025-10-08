#include <math.h>
#include "calc.h"
int square_root(double x, double *out){
    if(x < 0.0) return -1;         
    *out = sqrt(x);
    return 0;
}
