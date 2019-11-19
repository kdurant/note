/*
 * Copyright 2008 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmockery.h"
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void test_add(void **state)
{
    assert_int_equal(add(3, 4), 6);
    assert_int_equal(add(3, -3), 0);
}

void test_sub(void **state)
{
    assert_int_equal(sub(3, 3), 0);
    assert_int_equal(sub(3, -3), 6);
}

int main(void)
{
    const UnitTest tests[] = {
        unit_test(test_add),
        unit_test(test_sub),
    };
    return run_tests(tests);
}
