pause mouse any "\n      Start point  (Button-1) ? "
if ( MOUSE_BUTTON == 1 ) my_x = MOUSE_X; my_y = MOUSE_Y;\
    print "From ", my_x, my_y; call 'arrow2.plt';\
    else print "Never mind...";
