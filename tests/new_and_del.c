/*
This file contains a test for ensuring that streams can be created and
destroyed successfully.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Howdy";
    ps_PeekStream teststream = NULL;
    ps_ErrCode errcode;

    assert(ps_new(teststr, &teststream) == ps_ERROK);
    assert(ps_del(teststream) == ps_ERROK);

    return 0;

}