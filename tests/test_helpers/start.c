/*
** Created by doom on 08/09/18.
*/

#include "ut_utils.h"

int main(void);

__attribute__((force_align_arg_pointer)) void _start(void)
{
    int ret = main();

    ut_exit(ret);
}
