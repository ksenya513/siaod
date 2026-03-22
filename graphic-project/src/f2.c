#include <stdlib.h>
#include "graphics.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>

int n=1;
int C=0;
int A[100000];
bool found;
int m=0;
int x=3;//икс



void ShellSort(){
    int m=floor(log2((double)n)-1);
    int H[m];
    H[0]=1;
    for (int i=2;i<m+1;i++){
        H[i-1]=2*H[i-2]+1;
    }
    for(int k=H[m-1];m>=0;m--){
        for(int i=k;i<n;i++){
            int temp = A[i];
            int j = i-k;
            for(;j>=0&&temp<A[j];){
                A[j+k]=A[j];
                j=j-k;
            }
            A[j+k]=temp; 
        }
    }
}

void BinarySearch1(){
    C=0;
    int L=0;
    int R=n-1;
    found=false;
    while(L<=R){
        m=floor((double)(L+R)/2);
        C++;
        if(A[m]==x){
            found=true;
            break;
        }
        C++;
        if (A[m]<x){
            L=m+1;
        }else{
            R=m-1;
        }
    }
}

void BinarySearch2(){
    C=0;
    int L=0;
    int R=n-1;
    found=false;   
    while(L<R){
        m=floor((double)(L+R)/2);
        C++;
        if(A[m]<x){
            L=m+1;
        }else{R=m;}
    }
    C++;
    if(A[R]==x){
        found=true;
        m=R;
    }
}

void FillRand(){
    srand(time(0));
    for(int i =0;i<n;i++){
        A[i]=rand()%(n/2+1);    
    }
}

#define COLOR(r,g,b) (r|(g<<8)|(b<<16)|15<<24)
int main()
{
    initgraph(1920,1280,"AAAAAAAAAAAAA"); 
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3); 
    setcolor(DARKGRAY); 
      moveto(80,800);    
      lineto(1800,800);    
      line(1800,800,1780,840);  
      line(1800,800,1780,760); 
    
    setcolor(WHITE);
    outtextxy(1800,750,"N");//x
    
    setcolor(DARKGRAY);
      moveto(200,80);      
      lineto(200,880);     
      line(200,80,240,100);   
      line(200,80,160,100); 
    
    setcolor(WHITE);
      outtextxy(130,30,"Cф"); //y 
    

    setcolor(LIGHTRED);
      moveto(200,800);     
    for (n=1; n<10000; n++){
        FillRand();
        ShellSort();
        BinarySearch1();
        lineto((200+n/6), 800-(C)*12);  
    }

    setcolor(LIGHTBLUE);
      moveto(200,800);     
    for (n=1; n<10000; n++){
        FillRand();
        ShellSort();
        BinarySearch2();
        lineto((200+n/6), 800-(C)*12);  
    }    

    setcolor(LIGHTBLUE);
    outtextxy(1400,150,"2 version - light blue"); 
    setcolor(LIGHTRED);
    outtextxy(1400,100,"1 version - light red");

    

    getch();      
    closegraph();  
    return 0;
}
// gcc f1.c graphics.c $(pkg-config --cflags --libs cairo x11) -lm
