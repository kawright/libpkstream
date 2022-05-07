/*
This file contains a test for ensuring that `ps_pop` properly reads the current
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
    assert(ps_pop(teststream, &curr) == ps_ERROK);
    assert(curr == 'H');

    assert(ps_pop(teststream, &curr) == ps_ERROK);
    assert(curr == 'e');

    assert(ps_pop(teststream, &curr) == ps_ERROK);
    assert(curr == 'y');

    assert(ps_pop(teststream, &curr) == ps_ERROK);
    assert(curr == '\n');

    assert(ps_pop(teststream, &curr) == ps_ERROK);
    assert(curr == 'y');

    // You can't read the last character of the stream using `ps_pop`, because
    // it will error out with `ps_ERREOS`. We can use `ps_read` at this point
    // if we want to get the lastchar.
    assert(ps_pop(teststream, &curr) == ps_ERREOS);
    assert(curr == 'y');
    assert(ps_read(teststream, &curr) == ps_ERROK);
    assert(curr == 'o');

    // Cleanup
    assert(ps_del(teststream) == ps_ERROK);

    return 0;
}