/*
This file contains a test for ensuring that `ps_peek` properly reads the next
character.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Hey\nyo";
    ps_PeekStream teststream = NULL;

    assert(ps_new(teststr, &teststream) == ps_ERROK);

    char next;
    assert(ps_peek(teststream, &next) == ps_ERROK);
    assert(next == 'e');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_peek(teststream, &next) == ps_ERROK);
    assert(next == 'y');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_peek(teststream, &next) == ps_ERROK);
    assert(next == '\n');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_peek(teststream, &next) == ps_ERROK);
    assert(next == 'y');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_peek(teststream, &next) == ps_ERROK);
    assert(next == 'o');

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_peek(teststream, &next) == ps_ERROK);
    assert(next == 0);

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}