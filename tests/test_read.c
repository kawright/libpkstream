/*
This file contains a test for ensuring that `ps_read` properly reads the current
character.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Hey\nyo";
    ps_PeekStream teststream = NULL;

    assert(ps_new(teststr, &teststream) == ps_ERROK);

    char curr;
    assert(ps_read(teststream, &curr) == ps_ERROK);
    assert(curr == 'H');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_read(teststream, &curr) == ps_ERROK);
    assert(curr == 'e');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_read(teststream, &curr) == ps_ERROK);
    assert(curr == 'y');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_read(teststream, &curr) == ps_ERROK);
    assert(curr == '\n');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_read(teststream, &curr) == ps_ERROK);
    assert(curr == 'y');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_read(teststream, &curr) == ps_ERROK);
    assert(curr == 'o');

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}