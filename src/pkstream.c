/*
This file contains the implementation of the entire `pkstream` library.
*/

#include "pkstream.h"

#include <string.h>

struct ps_PeekStream {
    char    *str;
    int     curs;
    int     len;
    int     ln;
    int     col;
};

ps_ErrCode ps_del(ps_PeekStream stream) {

    free(stream->str);
    free(stream);

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
   out->col = 0;

   *ret = out;
   return ps_ERROK;
}
