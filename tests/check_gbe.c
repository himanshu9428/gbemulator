/*
 * Project : <Project Name>
 * Author  : Himanshu Joshi
 * License : MIT License
 *
 * Copyright (c) 2026 himanshu9428
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <emu.h>

#include <cpu.h>

START_TEST(test_nothing) {
    bool b = cpu_step();
    ck_assert_uint_eq(b, false);
} END_TEST

Suite *stack_suite() {
    Suite *s = suite_create("emu");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_nothing);
    suite_add_tcase(s, tc);

    return s;
}

int main() {
    Suite *s = stack_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int nf = srunner_ntests_failed(sr);

    srunner_free(sr);

    return nf == 0 ? 0 : -1;
}

