/*
** Created by doom on 08/09/18.
*/

void run_x86_64_tests(void);
void run_limits_tests(void);

int main(void)
{
    run_x86_64_tests();

    run_limits_tests();

    return 0;
}
