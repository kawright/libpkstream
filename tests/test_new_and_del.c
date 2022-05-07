/*
This file contains a test for ensuring that streams can be created and
destroyed successfully.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Howdy";
    char emptystr[6] = "";
    ps_PeekStream teststream = NULL;

    /* Try first with an empty string; should fail with ps_ERREOS */
    assert(ps_new(emptystr, &teststream) == ps_ERREOS);

    assert(ps_new(teststr, &teststream) == ps_ERROK);
    assert(ps_del(teststream) == ps_ERROK);

    return 0;

}