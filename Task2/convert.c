#include <ctype.h>
#include "include/convert.h"

void to_upper_str(char *s){
    for(; *s; ++s) *s = (char)toupper((unsigned char)*s);
}
void to_lower_str(char *s){
    for(; *s; ++s) *s = (char)tolower((unsigned char)*s);
}
