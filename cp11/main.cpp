// #include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

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
pthread_t ntid;

void printtids(const char *s)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n",s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
    printtids("new threads");
    return ((void*)0);
}

int main(void)
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
    {
        printf("can't craete thread: %s\n", strerror(err));
        return err;
    }

    printtids("main thread");
    sleep(1);
    printf("ntid:%u\n", (unsigned int)ntid);
    exit(0);
}
#endif

#ifdef TEST_2

void *trd_fn1(void *arg)
{
    int *parg = (int *)arg;
    printf("thread 1 returning \n");
    if (parg != NULL)
    {
        *parg = 1;
    }
    return((void*)parg);
}

void *trd_fn2(void *arg)
{
    int *parg = (int *)arg;
    printf("thread 2 returning \n");
    if (parg != NULL)
    {
        *parg = 2;
    }
    pthread_exit((void*)parg);
}

int main(void)
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
        return err;
    }

    err = pthread_create(&tid2, NULL, trd_fn2, &tparam2);
    if (err != 0)
    {
        printf("can't craete thread 2: %s\n", strerror(err));
        return err;
    }

    err = pthread_join(tid1, &tret);
    if (err != 0)
    {
        printf("can't join thread 1 :%s\n", strerror(err));
        return err;
    }
    printf("thread 1 exit code %d\n", int(*(int*)tret) );

    err = pthread_join(tid2, &tret);
    if (err != 0)
    {
        printf("can't join thread 2 :%s\n", strerror(err));
        return err;
    }
    printf("thread 2 exit code %d\n", int(*(int*)tret) ) ;

    return 0;
}

#endif
