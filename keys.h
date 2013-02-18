#ifndef __CANCER_KEYS_H__
#define __CANCER_KEYS_H__

#include <X11/Xlib.h>
#include <X11/keysymdef.h>

/* TODO: Rename CANCER_MOD CTRL_ALT */
/* Modifiers definition */
#define CANCER_MOD (Mod1Mask | ControlMask)
#define CTRL_ALT (Mod1Mask | ControlMask)
#define ALT Mod1Mask 
#define CONTROL ControlMask

/* grabbing macros */
#define GRAB_KEYS(KEY, MOD) XGrabKey(dpy, XKeysymToKeycode(dpy, KEY), MOD,\
        root, True, GrabModeAsync, GrabModeAsync);
/* state checking */
#define MODIFIER_IS(MOD) (ev.xkey.state == MOD)
#define KEY_IS(KEY) (ev.xkey.keycode == XKeysymToKeycode(dpy, KEY)) 

#endif /* __CANCER_KEYS_H__ */
