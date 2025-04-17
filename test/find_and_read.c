#include "kvstore.h"
main()
{
    int total=8, ctr;
    for(ctr=1; ctr<=total; ++ctr){
        char value[4096];
        char key[32];
        sprintf(key, "CSO-221###%d", ctr);
        if(get_key(key, value) < 0)
             printf("Get error\n");
        printf("For key = %s value=%s\n", key, value);
    }
}
