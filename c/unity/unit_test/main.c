#include "unity.h"
#include "use.h"

extern void setUp(void);
extern void tearDown(void);

void test_addFunc(void)
{
    TEST_ASSERT_EQUAL(7, add(3, 4));
}
int main(int argc, char const *argv[])
{
    UNITY_BEGIN();
    RUN_TEST(test_addFunc);
    return UNITY_END();
}
