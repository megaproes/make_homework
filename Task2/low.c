#include <stdio.h>
#include "include/convert.h"

int main(void){
    char buf[512];
    printf("enter text: ");
    if(!fgets(buf,sizeof(buf),stdin)) return 1;
    to_lower_str(buf);
    printf("%s", buf);
    return 0;
}
