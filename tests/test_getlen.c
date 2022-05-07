/*
This file contains a test for ensuring that `ps_getlen` properly reads the 
current character.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Hey\nyo";
    ps_PeekStream teststream = NULL;

    assert(ps_new(teststr, &teststream) == ps_ERROK);

    int len;
    assert(ps_getlen(teststream, &len) == ps_ERROK);
    assert(len == 6);

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}