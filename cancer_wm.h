#ifndef __CANCER_WM_H__
#define __CANCER_WM_H__

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include "keys.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef enum
{
    RAISE,
    LOWER,
    DESTROY,
    REFRESH,
    SNAP, /* aw snap ! */
    FREE
} ca_action;

typedef enum 
{
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