pause mouse any "     End point  (Button-1) ?    "
if ( MOUSE_BUTTON == 1 ) print "To   ", MOUSE_X, MOUSE_Y;\
    set arrow from my_x, my_y to MOUSE_X, MOUSE_Y;\
    replot;\
else print "Never mind..."; 
