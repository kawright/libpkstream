/*
This file contains a test for ensuring that streams can be advanced through
until the end of the stream is properly detected.
*/

#include <assert.h>
#include <stddef.h>

#include "../src/pkstream.h"

int main(int argc, char *argv[]) {

    char teststr[6] = "Howdy";
    ps_PeekStream teststream = NULL;

    assert(ps_new(teststr, &teststream) == ps_ERROK);

    // `ps_iseos` should yield `false`, since we aren't at the end yet.
    int iseos;
    assert(ps_iseos(teststream, &iseos) == ps_ERROK);
    assert(iseos == 0);

    // Advance through the stream 4 times. No errors should be detected.
    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_adv(teststream) == ps_ERROK);
    assert(ps_adv(teststream) == ps_ERROK);

    // `ps_iseos` should now yield `true`, since we reached the end.
    assert(ps_iseos(teststream, &iseos) == ps_ERROK);
    assert(iseos == 1);

    // Trying to advance should now return ps_ERREOS:
    assert(ps_adv(teststream) == ps_ERREOS);

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}