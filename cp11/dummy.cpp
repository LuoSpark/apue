#include "dummy.h"

void registerTestCase(int no, Test_Case_Fun fun)
{
    map<int, Test_Case_Fun>::iterator iter = g_map_fun.find(no);
    if (iter == g_map_fun.end())
    {
        g_map_fun.insert(std::pair<int, Test_Case_Fun>(no, fun));
    }
    else
    {
        g_map_fun[no] = fun;
    }
}

TestCaseDummy::TestCaseDummy(int no, Test_Case_Fun fun)
{
    registerTestCase(no, fun);
}
