/*
This file contains a test for ensuring that `ps_getpos` properly reads the 
current cursor position.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Hey\nyo";
    ps_PeekStream teststream = NULL;

    assert(ps_new(teststr, &teststream) == ps_ERROK);

    int pos;
    assert(ps_getpos(teststream, &pos) == ps_ERROK);
    assert(pos == 0);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getpos(teststream, &pos) == ps_ERROK);
    assert(pos == 0);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getpos(teststream, &pos) == ps_ERROK);
    assert(pos == 0);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getpos(teststream, &pos) == ps_ERROK);
    assert(pos == 1);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getpos(teststream, &pos) == ps_ERROK);
    assert(pos == 1);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getpos(teststream, &pos) == ps_ERROK);
    assert(pos == 1);

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}