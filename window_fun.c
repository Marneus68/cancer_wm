#include "window_fun.h"

#include "constants.h"

int CMoveWindowTo(Display * e_dpy, Window * e_w, unsigned int e_rw_w,
        unsigned int e_rw_h, ca_final_direction e_dir, ca_final_direction
        e_dock_pos)
{
    int ret = 0;
    switch (e_dir)
    {
        case FULLSCREEN:
            XMoveResizeWindow(e_dpy, *e_w, 0, 0,
                    e_rw_w, e_rw_h);
            break;
        case UP:
            XMoveResizeWindow(e_dpy, *e_w, 0 + PADDING, 0 +
                    PADDING, e_rw_w - PADDING * 2, e_rw_h/2 - PADDING );
            break;
        case DOWN:
            XMoveResizeWindow(e_dpy, *e_w, 0 + PADDING, e_rw_h/2
                    + PADDING, e_rw_w - PADDING * 2, e_rw_h/2 - PADDING * 2);
            break;
        case RIGHT:
            XMoveResizeWindow(e_dpy, *e_w, e_rw_w/2 +
                    PADDING, 0 + PADDING, e_rw_w/2 - PADDING * 2
                    , e_rw_h - PADDING * 2);
            break;
        case LEFT:
            XMoveResizeWindow(e_dpy, *e_w, 0 + PADDING, 0 +
                    PADDING, e_rw_w/2 - PADDING, e_rw_h - PADDING * 2);
            break;
        case UP_RIGHT:
            XMoveResizeWindow(e_dpy, *e_w, e_rw_w/2 + PADDING, 0
                    + PADDING, e_rw_w/2 - PADDING * 2, e_rw_h/2 - PADDING);
            break;
        case UP_LEFT:
            XMoveResizeWindow(e_dpy, *e_w, 0 + PADDING, 0 +
                    PADDING, e_rw_w/2 - PADDING, e_rw_h/2 - PADDING);
            break;
        case DOWN_LEFT:
            XMoveResizeWindow(e_dpy, *e_w, 0 + PADDING, e_rw_h/2
                    + PADDING, e_rw_w/2 - PADDING, e_rw_h/2 - PADDING * 2);
            break;
        case DOWN_RIGHT:
            XMoveResizeWindow(e_dpy, *e_w, e_rw_w/2 + PADDING,
                    e_rw_h/2 + PADDING, e_rw_w/2 - PADDING * 2, e_rw_h/2 -
            PADDING * 2);
            break;
        default:
            /* just to get rid of the "not handled value in switch" warning */
            break;
    }
    return ret;
}

