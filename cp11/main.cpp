#include "common.h"

#ifdef _POSIX_THREADS
#include <pthread.h>
#else
#pragma message("can't support pthread")
#endif

// pthread_t pthread_self(void);
// int pthread_equal(pthread_t tid1, phtread_t tid2);
// int pthread_create(pthread_t *restrict tidp, const pthread_attr_t * restrict attr, void *(*satrt_rtn)(void),void *restrict arg);
// int pthread_exit(void *rval_ptr);
// int pthread_join(pthread_t thread, void **rval_ptr);

#ifdef TEST_1

#endif

#ifdef TEST_2

#endif

map<int, Test_Case_Fun> g_map_fun;

int main(int argc, char *argv[])
{
    int testcase = 0;
    if (argc >= 2)
    {
        try
        {
            testcase = atoi(argv[1]);
        }
        catch (...)
        {
            printf("./test case \n");
            printf(" case is a number. example 1,2,3 ...\n");
            return -1;
        }
    }
    else
    {
        printf("./test case \n");
        printf(" case is a number. example 1,2,3 ...\n");
    }

    map<int, Test_Case_Fun>::iterator iter = g_map_fun.find(testcase);
    if (iter == g_map_fun.end())
    {
        printf("can't support case:%d\n", testcase);
    }
    else
    {
        iter->second(NULL);
    }
}
