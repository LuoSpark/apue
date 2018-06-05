
#pragma once
#include "common.h"

typedef void(*Test_Case_Fun)(void *);

extern map<int, Test_Case_Fun> g_map_fun;

void registerTestCase(int no, Test_Case_Fun fun);

struct TestCaseDummy
{
    TestCaseDummy(int no, Test_Case_Fun fun);
};
