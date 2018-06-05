#include "common.h"

void *trd_fn1(void *arg)
{
    int *parg = (int *)arg;
    printf("thread 1 returning \n");
    if (parg != NULL)
    {
        *parg = 1;
    }
    return ((void *)parg);
}

void *trd_fn2(void *arg)
{
    int *parg = (int *)arg;
    printf("thread 2 returning \n");
    if (parg != NULL)
    {
        *parg = 2;
    }
    pthread_exit((void *)parg);
}

void test_2(void*)
{
    int err = 0;
    pthread_t tid1;
    pthread_t tid2;
    void *tret;

    int tparam1 = 0;
    int tparam2 = 0;
    err = pthread_create(&tid1, NULL, trd_fn1, &tparam1);
    if (err != 0)
    {
        printf("can't craete thread 1: %s\n", strerror(err));
        return ;
    }

    err = pthread_create(&tid2, NULL, trd_fn2, &tparam2);
    if (err != 0)
    {
        printf("can't craete thread 2: %s\n", strerror(err));
        return ;
    }

    err = pthread_join(tid1, &tret);
    if (err != 0)
    {
        printf("can't join thread 1 :%s\n", strerror(err));
        return ;
    }
    printf("thread 1 exit code %d\n", int(*(int *)tret));

    err = pthread_join(tid2, &tret);
    if (err != 0)
    {
        printf("can't join thread 2 :%s\n", strerror(err));
        return ;
    }
    printf("thread 2 exit code %d\n", int(*(int *)tret));

    return ;
}

TestCaseDummy test2(2, test_2);
