#include "common.h"

void test_3(void *arg)
{
    printf("test_3\n");
}

TestCaseDummy test3(3, test_3);
