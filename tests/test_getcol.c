/*
This file contains a test for ensuring that `ps_getcol` properly reads the 
current character.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Hey\nyo";
    ps_PeekStream teststream = NULL;

    assert(ps_new(teststr, &teststream) == ps_ERROK);

    int col;
    assert(ps_getcol(teststream, &col) == ps_ERROK);
    assert(col == 1);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getcol(teststream, &col) == ps_ERROK);
    assert(col == 2);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getcol(teststream, &col) == ps_ERROK);
    assert(col == 3);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getcol(teststream, &col) == ps_ERROK);
    assert(col == 0);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getcol(teststream, &col) == ps_ERROK);
    assert(col == 1);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getcol(teststream, &col) == ps_ERROK);
    assert(col == 2);

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}