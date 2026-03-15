#include <stdlib.h>
#include "graphics.h"
#include <time.h>
#include <math.h>

int n=1;
int C=0;
int M=0;
int A[100];

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
    void ShakerSort(){
    C=0;
    M=0;
    int L=0;
    int R=n-1;
    int k=n-1;
    start:
    for(int j=R;j>L;j--){
        C++;
        if(A[j]<A[j-1]){
            int temp=A[j];
            A[j]=A[j-1];
            A[j-1]=temp;
            k=j;
            M+=3;
        }
    }
    L=k;
    for (int j=L;j<R;j++){
        C++;
        if(A[j]>A[j+1]){
            int temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
            k=j;
            M+=3;
        }
    }
    R=k;
    if(R>L) goto start;
    }
void InsertSort(){
    C=0;
    M=0;
    for (int i=1;i<n;i++){
        M++;
        int temp=A[i];
        int j=i-1;
        if(A[j]<temp)C++;
        for(;j>=0 && temp<A[j];C++){
            M++;
            A[j+1]=A[j];
            j=j-1;
        }
        M++;
        A[j+1]=temp;
    }
}

void ShellSort(){
    C=0;
    M=0;
    int m=floor(log2((double)n)-1);
    int H[m];
    H[0]=1;
    for (int i=2;i<m+1;i++){
        H[i-1]=2*H[i-2]+1;
    }
    for(int k=H[m-1];m>=0;m--){
        for(int i=k;i<n;i++){
            M++;
            int temp = A[i];
            int j = i-k;
            if(A[j]<temp)C++;
            for(;j>=0&&temp<A[j];C++){
                M++;
                A[j+k]=A[j];
                j=j-k;
            }
            M++;
            A[j+k]=temp; 
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
    initgraph(1920,1280,"working time and size of array comparison"); 
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3); 
    setcolor(DARKGRAY); 
      moveto(80,800);    
      lineto(1800,800);    
      line(1800,800,1780,840);  
      line(1800,800,1780,760); 
    
    setcolor(WHITE);
    outtextxy(1800,750,"N");//x
    
    setcolor(DARKGRAY);
      moveto(800,80);      
      lineto(800,880);     
      line(800,80,840,100);   
      line(800,80,760,100); 
    
    setcolor(WHITE);
      outtextxy(730,30,"Mф+Cф"); //y 
    

    setcolor(RED);
      moveto(800,800);     
    for (n=1; n<70; n +=1){
        FillRand();
        BubbleSort();
        lineto(800+10*n, 800-(C+M)/6);  
    } 

     setcolor(BLUE);
      moveto(800,800);     
    for (n=1; n<70; n +=1){
        FillRand();
        SelectSort2();
        lineto(800+10*n, 800-(C+M)/6);  
    }
     setcolor(CYAN);
      moveto(800,800);     
    for (n=1; n<70; n +=1){
        FillRand();
        ShakerSort();
        lineto(800+10*n, 800-(C+M)/6);  
    }
     setcolor(YELLOW);
      moveto(800,800);     
    for (n=1; n<70; n +=1){
        FillRand();
        InsertSort();
        lineto(800+10*n, 800-(C+M)/6);  
    }
      setcolor(LIGHTMAGENTA);
      moveto(800,800);     
    for (n=1; n<100; n +=1){
        FillRand();
        ShellSort();
        lineto(800+10*n, 800-(C+M)/6);  
    }

    setcolor(BLUE);
    outtextxy(100,100,"SelectSort - blue"); 
    setcolor(RED);
    outtextxy(100,150,"BubbleSort - red");
    setcolor(CYAN);
    outtextxy(100,200,"ShakerSort - cyan");
    setcolor(YELLOW);
    outtextxy(100,250,"InsertSort - yellow");
    setcolor(LIGHTMAGENTA);
    outtextxy(100,300,"ShellSort - magenta");
    

    getch();      
    closegraph();  
    return 0;
}
// gcc f1.c graphics.c $(pkg-config --cflags --libs cairo x11) -lm
