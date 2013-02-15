cancer wm - The Missing link of window managers
===============================================

What is cancer wm ?
-------------------
Cancer wm is a minimalistic window manager.

Compiling
---------
Compiling cancer wm requires Xlib.
    make

Installing
----------
Installing requires root privileges.
    make install

Usage
-----
Installing cancer wm will put the executable in /usr/bin/cancer_wm with a startup script /usr/bin/cancer_wm-session. A cancer_wm-session.desktop will be created.
Depending on the display manager you use, the cancer_wm session will be dirrectly available, or will need to be added to the list of available sessiosn for you display manager.

Remember that, at the moment the cancer_wm session doesn't provide any kind of shell to lauch applications.

To test the behaviour of cancer_wm, you can open up an existing tty (ctrl + alt + F1, for exeample), log in and type in the following line :
    export DISPLAY=:0
After that, you can invoke graphical programes such as xterm :
    xterm &
You can then switch back to the graphical window (ctrl + alt + F7) to try out cancer_wm.

Key Bidings
-----------

The Alt key is the defaut Mod1 on most X11 systems, this might vary.

Mod1 + F : Close the foccused window



Uninstalling
------------
Uninstalling requires root privileges.
    make uninstall

    The goal of cancer wm is to create a window manager that is some sort of hybrid
    between a floating wm and tilling wm.
    The tiling kinda works like the snapping we had in that old compiz plugin, or
    the one that you can find on windows, unity and gnome shell (except it allows
    for more positions than just right, left and maximize).
    I'm trying to keep it simple to use and learn. I plan to have several key
    bindings, one for the keypad, one for the arrow keys, and one for hjkl so
    that I can use it on every computer I own. I'm actively working on mouse
    support too, even for tilling actions.
