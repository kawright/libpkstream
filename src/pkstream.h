/*
This file contains the definitions of all public members of the `pkstream`
library. Please refer to the README for detailed documentation on each member
defined here.
*/

#ifndef PKSTREAM_H_
#define PKSTREAM_H_

/*
Contains error codes used for return statements by public functions in this
library.
*/
typedef enum {
    ps_ERROK = 0,
    ps_ERRMEM = 1,
    ps_ERREOS = 2,
    ps_ERRSOS = 3,
    ps_ERROOB = 4
} ps_ErrCode;

/*
A character stream object which supports look-ahead operations.
*/
typedef struct PeekStream *PeekStream;

/*
Advance the cursor.
*/
ps_ErrCode ps_adv(PeekStream stream);

/*
Delete an instance.
*/
ps_ErrCode ps_del(PeekStream stream);

/*
Get the current column number.
*/
ps_ErrCode ps_getcol(PeekStream stream, int *ret);

/*
Get the length of the stream.
*/
ps_ErrCode ps_getlen(PeekStream stream, int *ret);

/*
Get the current line of the stream.
*/
ps_ErrCode ps_getline(PeekStream stream, int *ret);

/*
Get the position of the cursor.
*/
ps_ErrCode ps_getpos(PeekStream stream, int *ret);

/*
Is the stream at the end?
*/
ps_ErrCode ps_iseos(PeekStream stream, int *ret);

/*
Create a new instance.
*/
ps_ErrCode ps_new(char *str, PeekStream *ret);

/*
Get the character ahead of the cursor.
*/
ps_ErrCode ps_peek(PeekStream stream, char *ret);

/*
Get the character at the cursor and advance it.
*/
ps_ErrCode ps_pop(PeekStream stream, char *ret);

/*
Get the character at the cursor.
*/
ps_ErrCode ps_read(PeekStream stream, char *ret);

#endif