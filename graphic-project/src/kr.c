#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"

int main(){
initgraph(720,720,"MENU");
 for (int y=0;y<720; y++) {
        double gr = (double)y / 720.0;
        double r = 0.8;
        double g = 0.5;
        double b = 0.5+gr*1.0;  
        
        setrgbcolor(r,g,b);
        line(0,y,720,y);
 }
 int text_go=1;
 int balbes=0;
int x = 360;
int y = 360;
 while(1){
    if (text_go==0 && balbes==0){
        for (int y =0; y <720; y++) {
        double r=0.0;
        double g=0.0;
        double b=0.0;  
        
        setrgbcolor(r,g,b);
        line(0,y,720,y);
        }
        flush();
        delay(50);
        setcolor(WHITE);
        outtextxy(150, 120, "КОСТИК ВОЗЬМИ СЕРДЕЧКО");
        setrgbcolor(0.4, 0.4, 0.4);
        rectangle(50,30,680,660);
        int rad=20;
        int s=10;
        setrgbcolor(0.0, 0.7, 1.0);  
        fillellipse(x,y,rad,rad);
        setrgbcolor(0.8, 0.9, 1.0);
        circle(x,y,rad);
        flush();
        if (kbhit()) {
            for (int y =0; y <720; y++) {
        double r=0.0;
        double g=0.0;
        double b=0.0;  
        
        setrgbcolor(r,g,b);
        line(0,y,720,y);
        }
        setcolor(WHITE);
        outtextxy(150, 120, "КОСТИК ВОЗЬМИ СЕРДЕЧКО");
        setrgbcolor(0.4, 0.4, 0.4);
        rectangle(50,30,680,660);
        int xx=380;
        int yy=511;
        int size=10;
        int rr = size * 3;
    setcolor(RED);
    fillellipse(xx - rr, yy - rr/2, rr, rr); 
    fillellipse(xx + rr, yy - rr/2, rr, rr);  
    int points[] = {
        xx - 2*rr, yy,    
        xx + 2*rr, yy,         
        xx, yy + 2*rr         
    };
    fillpoly(3, points);
     int dx = x - xx;
     int dy = y - yy;
     int distance = dx*dx + dy*dy;
     int touch = (rad + rr) * (rad + rr);           
     if (distance < touch) {
         balbes = 1;  
         continue;
         }   
            int key = getch();
            switch(key){
                case 65293:{
                    closegraph();
                    return 0;
                }
                case 65362:{
                    y-=s;
                break;
            }
                case 65364:{
                    y+=s;
                break;
            } 
                case 65361:{
                    x-=s;
                break;
            }
                case 65363:{
                    x+=s;
                break;
            }
        }
    }
    delay(50);   
    }else if(balbes<1){
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
        outtextxy(150, 200, "ГЛАВНОЕ МЕНЮ");

setcolor(WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
outtextxy(305,320,"НАЧАТЬ");

setcolor(WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(335,380,"ВЫХОД");


    int key=getch();
        if (key==81){
        break;
    }
    switch(key){
        case 65362:{setcolor(RED);
                    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                    outtextxy(305,320,"НАЧАТЬ");
                    setcolor(WHITE);
                    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                    outtextxy(335,380,"ВЫХОД");
                   
                    delay(100);
                    key=getch();
                    if (key==65293){ 
                        text_go=0;
                    }
                    break;
                }
        case 65364:{setcolor(RED);
                    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                    outtextxy(335,380,"ВЫХОД");
                    setcolor(WHITE);
                    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                    outtextxy(305,320,"НАЧАТЬ");
                    delay(100);
                    key=getch();
                     if (key==65293){
                         closegraph();
                    }
                    break;
                }
            }
         }else if(balbes==1){
        for (int y =0; y <720; y++) {
        double r=0.4;
        double g=0.4;
        double b=1.0;  
        setrgbcolor(r,g,b);
        line(0,y,720,y);
        }
        flush();
        delay(100);
        setcolor(WHITE);
        outtextxy(220, 120, "ЛЮБЛЮ ТЕБЯ БАЛЕС");
         int xx=380;
        int yy=401;
        int size=10;
        int rr = size * 3;
    setcolor(BLUE);
    fillellipse(xx - rr, yy - rr/2, rr, rr); 
    fillellipse(xx + rr, yy - rr/2, rr, rr);  
    int points[] = {
        xx - 2*rr, yy,    
        xx + 2*rr, yy,         
        xx, yy + 2*rr         
    };
    fillpoly(3, points);
         }

    
 }
    return 0;
    closegraph();
}
// gcc kr.c graphics.c $(pkg-config --cflags --libs cairo x11) -lm