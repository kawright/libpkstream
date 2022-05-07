/*
This file contains a test for ensuring that `ps_getline` properly reads the 
current line.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Hey\nyo";
    ps_PeekStream teststream = NULL;

    assert(ps_new(teststr, &teststream) == ps_ERROK);

    int ln;
    assert(ps_getline(teststream, &ln) == ps_ERROK);
    assert(ln == 0);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getline(teststream, &ln) == ps_ERROK);
    assert(ln == 0);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getline(teststream, &ln) == ps_ERROK);
    assert(ln == 0);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getline(teststream, &ln) == ps_ERROK);
    assert(ln == 1);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getline(teststream, &ln) == ps_ERROK);
    assert(ln == 1);

    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_getline(teststream, &ln) == ps_ERROK);
    assert(ln == 1);

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}