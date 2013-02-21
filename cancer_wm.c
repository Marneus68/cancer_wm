/* cancer_wm is written by Duane Bekaert, 2013.
 * this work is based on :
 * TinyWM is written by Nick Welch <mack@incise.org>, 2005.
 */

#include "constants.h"
#include "cancer_wm.h"

int main()
{
    Display * dpy;
    Window root;
    XWindowAttributes attr;

    /* we use this to save the pointer's state at the beginning of the
     * move/resize.
     */
    XButtonEvent start;

    XEvent ev;

    /* return failure status if we can't connect */
    if(!(dpy = XOpenDisplay(0x0))) return 1;

    root = DefaultRootWindow(dpy);

    XGetWindowAttributes(dpy, root, &attr);
    
    /* root window size */
    unsigned int    rw_w = attr.width,
                    rw_h = attr.height;
    
    ca_order    order;
    order.window = NULL;

    /* put the window on the top */
    GRAB_KEYS(XK_F1, ALT)

    /* put the window at the bottom */
    GRAB_KEYS(XK_F2, ALT)

    /* window destruction */
    GRAB_KEYS(XK_F4, ALT)
    GRAB_KEYS(XK_q, CONTROL)

    /* window refreshing (mapping/unmapping) */
    GRAB_KEYS(XK_F5, ALT)

    /* right slot */
    GRAB_KEYS(XK_KP_6, CANCER_MOD)
    GRAB_KEYS(XK_h, CANCER_MOD)
    GRAB_KEYS(XK_Right, CANCER_MOD)
    /* left slot */
    GRAB_KEYS(XK_KP_4, CANCER_MOD)
    GRAB_KEYS(XK_l, CANCER_MOD)
    GRAB_KEYS(XK_Left, CANCER_MOD)
    /* top slot */
    GRAB_KEYS(XK_KP_8, CANCER_MOD)
    GRAB_KEYS(XK_k, CANCER_MOD)
    GRAB_KEYS(XK_Up, CANCER_MOD)
    /* bottom slot */
    GRAB_KEYS(XK_KP_2, CANCER_MOD)
    GRAB_KEYS(XK_j, CANCER_MOD)
    GRAB_KEYS(XK_Down, CANCER_MOD)
    /* top right slot */
    GRAB_KEYS(XK_KP_9, CANCER_MOD)
    GRAB_KEYS(XK_Up | XK_Right, CANCER_MOD)
    /* bottom right slot */
    GRAB_KEYS(XK_KP_3, CANCER_MOD)
    /* top left slot */
    GRAB_KEYS(XK_KP_7, CANCER_MOD)
    /* bottom left slot */
    GRAB_KEYS(XK_KP_1, CANCER_MOD)
    /* toggle fullscreen */
    GRAB_KEYS(XK_KP_5, CANCER_MOD)
    GRAB_KEYS(XK_i, CANCER_MOD)
    /* free (unsnap) window */
    GRAB_KEYS(XK_KP_0, CANCER_MOD)
    GRAB_KEYS(XK_m, CANCER_MOD)

    /* launch the defautl applications */
    GRAB_KEYS(XK_t, CANCER_MOD)

    /* move the window arround */
    XGrabButton(dpy, 1, CANCER_MOD, root, True, ButtonPressMask, GrabModeAsync,
            GrabModeAsync, None, None);

    /* resize the window */
    XGrabButton(dpy, 3, CANCER_MOD, root, True, ButtonPressMask, GrabModeAsync,
            GrabModeAsync, None, None);

    /* destroy the window */
    XGrabButton(dpy, 2, CANCER_MOD, root, True, ButtonPressMask, GrabModeAsync,
            GrabModeAsync, None, None);

    for(;;)
    {
        XNextEvent(dpy, &ev);
        
        /*** Keypresses on a window ***/
        if(ev.type == KeyPress)
        {
            if (ev.xkey.subwindow == None)
            {
                if MODIFIER_IS(CANCER_MOD)
                {
                    if (KEY_IS(XK_t))
                        order.act = DEF_TERM;
                }
            }
            else if (ev.xkey.subwindow != None)
            {
                order.window = ev.xkey.subwindow;
                if MODIFIER_IS(ALT)
                {
                    if KEY_IS(XK_F1)
                        order.act = RAISE;
                    else if KEY_IS(XK_F2)
                        order.act = LOWER;
                    else if KEY_IS(XK_F4)
                        order.act = DESTROY;
                    else if KEY_IS(XK_F5)
                        order.act = REFRESH;
                }
                else if MODIFIER_IS(CONTROL)
                {
                    if KEY_IS(XK_q) order.act = DESTROY;
                }
                else if MODIFIER_IS(CANCER_MOD)
                {
                    if (KEY_IS(XK_t))
                        order.act = DEF_TERM;
                    /* right slot */
                    else if (KEY_IS(XK_KP_6) || KEY_IS(XK_l) || KEY_IS(XK_Right))
                    {
                        order.act = SNAP;
                        if (order.direct == UP)
                            order.direct = UP_RIGHT;
                        else if (order.direct == DOWN)
                            order.direct = DOWN_RIGHT;
                        else order.direct = RIGHT;
                    }
                    /* left slot */
                    else if (KEY_IS(XK_KP_4) || KEY_IS(XK_h) || KEY_IS(XK_Left))
                    {
                        order.act = SNAP;
                        if (order.direct == UP)
                            order.direct = UP_LEFT;
                        else if (order.direct == DOWN)
                            order.direct = DOWN_LEFT;
                        else order.direct = LEFT;
                    }
                    /* bottom slot */
                    else if (KEY_IS(XK_KP_2) || KEY_IS(XK_j) || KEY_IS(XK_Down))
                    {
                        order.act = SNAP;
                        if (order.direct == RIGHT)
                            order.direct = DOWN_RIGHT;
                        else if (order.direct == LEFT)
                            order.direct = DOWN_LEFT;
                        else order.direct = DOWN;
                    }
                    /* top slot */
                    else if (KEY_IS(XK_KP_8) || KEY_IS(XK_k) || KEY_IS(XK_Up))
                    {
                        order.act = SNAP;
                        if (order.direct == RIGHT)
                            order.direct = DOWN_RIGHT;
                        else if (order.direct == LEFT)
                            order.direct = DOWN_LEFT;
                        else order.direct = UP;
                    }
                    /* keypad 9 */
                    else if KEY_IS(XK_KP_9)
                    {
                        order.act = SNAP;
                        order.direct = UP_RIGHT;
                    }
                    /* keypad 7 */
                    else if KEY_IS(XK_KP_7)
                    {
                        order.act = SNAP;
                        order.direct = UP_LEFT;
                    }
                    /* keypad 1 */
                    else if KEY_IS(XK_KP_1)
                    {
                        order.act = SNAP;
                        order.direct = DOWN_LEFT;
                    }
                    /* keypad 3 */
                    else if KEY_IS(XK_KP_3)
                    {
                        order.act = SNAP;
                        order.direct = DOWN_RIGHT;
                    }
                    /* fullscreen */
                    else if (KEY_IS(XK_KP_5) || KEY_IS(XK_i))
                    {
                        order.act = SNAP;
                        order.direct = FULLSCREEN;
                    }
                    /* free window */
                    else if (KEY_IS(XK_KP_0) || KEY_IS(XK_m));
                }
            }
        }
        else if (ev.type == KeyRelease)
        {
            int toclean = 1;

            if (order.act == 0) toclean = 0;
            else if (order.act == DESTROY)
            {
                XUnmapWindow(dpy, order.window);
                XDestroyWindow(dpy, order.window);
            }
            else if (order.act == LOWER)
                XLowerWindow(dpy, order.window);
            else if (order.act == RAISE)
                XRaiseWindow(dpy, order.window); 
            else if (order.act == REFRESH)
            {
                XUnmapWindow(dpy, order.window);
                XMapWindow(dpy, order.window);
            }
            else if (order.act == DEF_TERM)
                system("x-terminal-emulator &");
            else if (order.act == DEF_WWW)
                system("x-www-browser");
            else if (order.act == SNAP)
            {
                XRaiseWindow(dpy, ev.xbutton.subwindow);
                switch (order.direct)
                {
                    case FULLSCREEN:
                        XMoveResizeWindow(dpy, order.window, 0, 0,
                            rw_w, rw_h);
                        break;
                    case UP:
                        XMoveResizeWindow(dpy, order.window, 0 + PADDING, 0 +
                        PADDING, rw_w - PADDING * 2, rw_h/2 - PADDING * 2);
                        break;
                    case DOWN:
                        XMoveResizeWindow(dpy, order.window, 0 + PADDING, rw_h/2
                        + PADDING, rw_w - PADDING * 2, rw_h/2 - PADDING * 2);
                        break;
                    case RIGHT:
                        XMoveResizeWindow(dpy, order.window, rw_w/2 + PADDING, 0
                        + PADDING, rw_w/2 - PADDING  * 2, rw_h - PADDING * 2);
                        break;
                    case LEFT:
                        XMoveResizeWindow(dpy, order.window, 0 + PADDING, 0 +
                        PADDING, rw_w/2 - PADDING * 2, rw_h - PADDING * 2);
                        break;
                    case UP_RIGHT:
                        XMoveResizeWindow(dpy, order.window, rw_w/2 + PADDING, 0
                        + PADDING, rw_w/2 - PADDING * 2, rw_h/2 - PADDING * 2);
                        break;
                    case UP_LEFT:
                        XMoveResizeWindow(dpy, order.window, 0 + PADDING, 0 +
                        PADDING, rw_w/2 - PADDING * 2, rw_h/2 - PADDING * 2);
                        break;
                    case DOWN_LEFT:
                        XMoveResizeWindow(dpy, order.window, 0 + PADDING, rw_h/2
                        + PADDING, rw_w/2 - PADDING * 2, rw_h/2 - PADDING * 2);
                        break;
                    case DOWN_RIGHT:
                        XMoveResizeWindow(dpy, order.window, rw_w/2 + PADDING,
                        rw_h/2 + PADDING, rw_w/2 - PADDING * 2, rw_h/2 -
                        PADDING * 2);
                        break;
                }
            }
            
            if (toclean)
            {
                order.act = 0;
                order.direct = 0;
                order.arg = 0;
                order.window = NULL;
            }
        }
        else if (ev.type == ButtonPress && ev.xbutton.subwindow != None) 
        {
            if (ev.xbutton.state == CANCER_MOD)
            {
                XRaiseWindow(dpy, ev.xkey.subwindow);

                XGrabPointer(dpy, ev.xbutton.subwindow, True,
                        PointerMotionMask|ButtonReleaseMask, GrabModeAsync,
                        GrabModeAsync, None, None, CurrentTime);

                XGetWindowAttributes(dpy, ev.xbutton.subwindow, &attr);
                start = ev.xbutton;
            }
        }
        else if(ev.type == MotionNotify) {
            int xdiff, ydiff;
            
            while(XCheckTypedEvent(dpy, MotionNotify, &ev));

            xdiff = ev.xbutton.x_root - start.x_root;
            ydiff = ev.xbutton.y_root - start.y_root;
            XMoveResizeWindow(dpy, ev.xmotion.window,
                    attr.x + (start.button==1 ? xdiff : 0),
                    attr.y + (start.button==1 ? ydiff : 0),
                    MAX(1, attr.width + (start.button==3 ? xdiff : 0)),
                    MAX(1, attr.height + (start.button==3 ? ydiff : 0)));
        }
        else if(ev.type == ButtonRelease)
        {
            if (ev.xbutton.state == Button1Mask || Button3Mask)
                XUngrabPointer(dpy, CurrentTime);
        }
    }
}

