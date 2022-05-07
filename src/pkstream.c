/*
This file contains the implementation of the entire `pkstream` library.
*/

#include "pkstream.h"

#include <string.h>
#include <stdlib.h>

struct ps_PeekStream {
    char    *str;
    int     curs;
    int     len;
    int     ln;
    int     col;
};

ps_ErrCode ps_adv(ps_PeekStream stream) {
    int iseos;
    ps_iseos(stream, &iseos);
    if (iseos) {
        return ps_ERREOS;
    }
    stream->curs++;

    /* Reset col and increment line if \n detected: */
    if (stream->str[stream->curs] == '\n') {
        stream->col = 0;
        stream->ln++;
    } else {
        stream->col++;
    }

    return ps_ERROK;
}

ps_ErrCode ps_del(ps_PeekStream stream) {

    free(stream->str);
    free(stream);

    return ps_ERROK;
}

ps_ErrCode ps_getcol(ps_PeekStream stream, int *ret) {
    *ret = stream->col;
    return ps_ERROK;
}

ps_ErrCode ps_getlen(ps_PeekStream stream, int *ret) {
    *ret = stream->len;
    return ps_ERROK;
}

ps_ErrCode ps_getline(ps_PeekStream stream, int *ret) {
    *ret = stream->ln;
    return ps_ERROK;
}

ps_ErrCode ps_getpos(ps_PeekStream stream, int *ret) {
    *ret = stream->curs;
    return ps_ERROK;
}

ps_ErrCode ps_iseos(ps_PeekStream stream, int *ret) {
    int out;
    if (stream->curs >= (stream->len - 1)) {
        out = 1;
    } else {
        out = 0;
    }

    *ret = out;
    return ps_ERROK;
}

ps_ErrCode ps_new(char *str, ps_PeekStream *ret) {

    /*
    Ensure that the new stream is not being initialized with the cursor out-of-
    bounds:
    */
   if (str[0] == 0) {
       return ps_ERREOS;
   }

   /* Allocate memory for `ret`: */
   ps_PeekStream out = malloc(sizeof(struct ps_PeekStream));
   if (out == NULL) {
       return ps_ERRMEM;
   }

   /* Initialize the return data: */
   out->str = strdup(str);
   if (out->str == NULL) {
       free(out);
       return ps_ERRMEM;
   }
   out->curs = 0;
   out->len = strlen(out->str);
   out->ln = 0;
   out->col = 1;

   *ret = out;
   return ps_ERROK;
}

ps_ErrCode ps_peek(ps_PeekStream stream, char *ret) {
    int iseos;
    char out;
    ps_iseos(stream, &iseos);
    if (iseos) {
        out = 0;
    } else {
        out = stream->str[stream->curs + 1];
    }

    *ret = out;
    return ps_ERROK;
}

ps_ErrCode ps_read(ps_PeekStream stream, char *ret) {
    *ret = stream->str[stream->curs];
    return ps_ERROK;
}