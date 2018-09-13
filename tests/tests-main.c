/*
** Created by doom on 08/09/18.
*/

void run_x86_64_tests(void);
void run_limits_tests(void);
void run_stddef_tests(void);
void run_stdint_tests(void);
void run_string_tests(void);

int main(void)
{
    run_x86_64_tests();

    run_limits_tests();

    run_stddef_tests();

    run_stdint_tests();

    run_string_tests();

    return 0;
}
