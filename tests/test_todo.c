#include <stdlib.h>
#include <check.h>

#include "todo.h"


START_TEST(test_todo_1)
{
    ck_assert_str_eq(todo(), "do stuff!");
}
END_TEST

START_TEST(test_todo_2)
{
    ck_assert_str_eq(todo(), "do stuff");
}
END_TEST

Suite* todo_suite(void) {
    /* test cases */
    TCase *tcase_1, *tcase_2;

    Suite *suite = suite_create("todo_test");

    /* first test case */
    tcase_1 = tcase_create("test case 1");
    tcase_add_test(tcase_1, test_todo_1);
    suite_add_tcase(suite, tcase_1);

    /* second test case */
    tcase_2 = tcase_create("test case 2");
    tcase_add_test(tcase_2, test_todo_2);
    suite_add_tcase(suite, tcase_2);

    return suite;
}

int
main(int argc, char *argv[])
{
    int number_failed;
    Suite *suite = todo_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
