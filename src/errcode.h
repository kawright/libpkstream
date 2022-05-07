/*
FILE:
    errcode.h

DESCRIPTION:
    This file contains the definition of the `ps_ErrCode` enum.

AUTHOR:
    Kristoffer A. Wright <kris.al.wright@gmail.com>
*/

/*
ENUM:
    ps_ErrCode

DESCRIPTION:
    Contains all error code values which may be returned by a `libpkstream`
    function.

MEMBERS:
    ps_ERROK = 0
        Indicates that the function completed successfully with no errors to
        report.

    ps_ERRMEM = 1
        Indicates that an attempt to allocate memory failed.
        
    ps_ERREOS = 2
        Indicates that the requested operation could not be performed because
        the end of the stream has been reached.
*/
typedef enum {
    ps_ERROK = 0,
    ps_ERRMEM = 1,
    ps_ERREOS = 2
} ps_ErrCode;