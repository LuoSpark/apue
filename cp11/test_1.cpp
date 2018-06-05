
#include "common.h"
pthread_t ntid;

void printtids(const char *s)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
    printtids("new threads");
    return ((void *)0);
}

void test_1(void*arg)
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
    {
        printf("can't craete thread: %s\n", strerror(err));
        return;
    }

    printtids("main thread");
    sleep(1);
    printf("ntid:%u\n", (unsigned int)ntid);
    exit(0);
}

TestCaseDummy test1(1, test_1);
