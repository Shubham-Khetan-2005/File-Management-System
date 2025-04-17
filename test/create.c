#include "kvstore.h"
main()
{
    int total=8, ctr;
    for(ctr=1; ctr<=total; ++ctr){
        char value[32];
        char key[32];
        sprintf(key, "CSO-221###%d", ctr);
        sprintf(value, "I am %d. Registered to CSO-221.", ctr);
        if(put_key(key, value, 32) < 0)
             printf("Create error\n");
    }
}
