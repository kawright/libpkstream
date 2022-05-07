/*
This file contains the definition of the `ps_ErrCode` enum.
*/

/*
Contains error codes used for return statements by public functions in this
library. Please see the README for details on the meanings of each member.
*/
typedef enum {
    ps_ERROK = 0,
    ps_ERRMEM = 1,
    ps_ERREOS = 2,
    ps_ERRSOS = 3,
    ps_ERROOB = 4
} ps_ErrCode;