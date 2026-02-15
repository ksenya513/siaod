#include <stdlib.h>
#include "graphics.h"
#include <time.h>

int n=1;
int C=0;
int M=0;
int A[30];

void BubbleSort(){
    C=0;
    M=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            C++;
            if(A[j]<A[j-1]){
                M+=3;
                int temp = A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
}
void SelectSort2(){
    C=0;
    M=0;
     for (int i=0;i<n-1;i++){
        int k=i;
        for (int j=i+1;j<n;j++){
            C++;
            if (A[j]<A[k]){
                k=j;
            }
        }
        if(k!=i){            
            int move=A[i];
            A[i]=A[k];
            A[k]=move;
            M+=3;
        }
    }

}
void FillRand(){
    srand(time(0));
    for(int i =0;i<n;i++){
        A[i]=rand()%(2*n+1);    
    }
}

#define COLOR(r,g,b) (r|(g<<8)|(b<<16)|15<<24)
int main()
{
    initgraph(720,720,"working time and size of array comparison"); 
    
    setcolor(DARKGRAY); 
      moveto(80,460);    
      lineto(640,460);    
      line(640,460,620,440);  
      line(640,460,620,480); 
    
    setcolor(WHITE);
    outtextxy(660,470,"N");//x
    
    setcolor(DARKGRAY);
      moveto(360,80);      
      lineto(360,640);     
      line(360,80,380,100);   
      line(360,80,340,100); 
    
    setcolor(WHITE);
      outtextxy(300,50,"Mф+Cф"); //y 
    

    setcolor(RED);
      moveto(360,460);     
    for (n=1; n<30; n +=1){
        FillRand();
        BubbleSort();
        lineto(360+3*n, 460-(C+M)/2);  
    } 

     setcolor(BLUE);
      moveto(360,460);     
    for (n=1; n<30; n +=1){
        FillRand();
        SelectSort2();
        lineto(360+3*n, 460-(C+M)/2);  
    }

    outtextxy(600,100,"SelectSort - blue"); 
    setcolor(RED);
    outtextxy(600,140,"BubbleSort - red");

    getch();      
    closegraph();  
    return 0;
}
// gcc f1.c graphics.c $(pkg-config --cflags --libs cairo x11) -lm
