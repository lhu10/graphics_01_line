#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int x = x0, y = y0;
    int dy = y1 - y0; //delta y
    int dx = x1 - x0; //delta x
    int d, A, B;
    //swap the coords
    if (x1 < x0){
	x = x1;
        y = y1;
        x1 = x0;
        y1 = y0;
        dx *= -1;
        dy *= -1;
    }
    //m = 0
    if(dy == 0){
        while(x < x1){
            plot(s, c, x, y);
            x++;
        }
    }
    //m = undefined
    else if(dx == 0){
        while(y < y1){
            plot(s, c, x, y);
            y++;
        }
    }
    //octants 1 and 5
    else if(dy <= dx && dy > 0){
        A = dy; 
        B = -dx;
        d = 2*A + B;
        while(x <= x1){
            plot(s, c, x, y);
            if(d > 0){
                y++;
                d += 2*B;
            }
            x++;
            d += 2*A;
        }
    }
    //octants 2 and 6
    else if(dy > dx){
        A = dx;
        B = -dy;
        d = 2*A + B;
        while(y <= y1){
            plot(s, c, x, y);
            if(d > 0){
                x++;
                d += 2*B;
            }
            y++; 
            d += 2*A;
        }
    }
    //octants 7 and 3
    else if(-dy > dx){
        A = dx;
        B = -dy;
        d = 2*A - B;
        while(y >= y1){
            plot(s, c, x, y);
            if(d > 0){
                x++;
                d -= 2*B;
            }
            y--; 
            d += 2*A;
        }
    }
    //octants 8 and 4
    else{
        A = dy;
        B = -dx;
        d = 2*A - B; 
        while(x <= x1){
            plot(s, c, x, y);
            if(d < 0){
                y--;
                d -= 2*B;
            }
            x++; 
            d += 2*A;
        }
    }

}
