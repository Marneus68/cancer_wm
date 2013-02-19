#ifndef __CANCER_WM_H__
#define __CANCER_WM_H__

#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include "keys.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef enum
{
    NONE = 0,
    RAISE,
    LOWER,
    DESTROY,
    REFRESH,
    SNAP, 
    FREE,
    DEF_TERM,
    DEF_WWW
} ca_action;

typedef enum 
{
    _ = 0,
    UP,
    UP_RIGHT,
    UP_LEFT,
    DOWN,
    DOWN_RIGHT,
    DOWN_LEFT,
    LEFT,
    RIGHT,
    FULLSCREEN
} ca_final_direction;

typedef enum
{
    __ = 0,
    TERMINAL,
    LOCK,
    SHUTDOWN
} ca_argument;

typedef struct
{
    ca_action act;
    ca_final_direction direct;
    ca_argument arg;
    Window window;
} ca_order;

#endif /* __CANCER_WM_H__ */
