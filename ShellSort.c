#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int C=0;//сравнение
int M=0;//пересылки
int n; 
int *A= NULL;

void FillInc();
void FillDec();
void FillRand();
void ShellSort();
void PrintMas();
void InsertSort();
void ShellSort2();


void main(int argc,char**argv){
    n=10;
    A = (int*)malloc(n * sizeof(int));
    printf("\n");
    printf("|////////|///////////////////|////////|////////|\n");
    printf("|   N    |       H по        | Insert | Shell  |\n");
    printf("|        |     Д.Кнуту       | Mф+Сф  | Mф+Сф  |\n");
    printf("|////////|///////////////////|////////|////////|\n");

    for(n=100;n<600;n+=100){
        A = realloc(A,n * sizeof(int));
        FillRand();
        ShellSort();
        int MRandS=M;
        int CRandS=C;
        FillRand();
        InsertSort();
        int MRandI=M;
        int CRandI=C;
        int m=floor(log2((double)n)-1);
        int H[m];
        H[0]=1;
        for (int i=2;i<m+1;i++){
            H[i-1]=2*H[i-2]+1;
        }
        printf("|%8d|",n);
        for(int i=0;i<m;i++){
            printf("%d ",H[i]);
        }
        if(m==5){
            printf("       ");
        }else if (m==6){
            printf("    ");
        }
        printf("|%8d|%8d|\n",MRandI+CRandI,MRandS+MRandS);
    } 
    printf("|////////|///////////////////|////////|////////|\n");
    printf("\n\n\n\n");




    printf("|////////|///////////////////|////////|///////////////////////|////////|\n");
    printf("|   N    |       H по        | Shell  |          H по         | Shell  |\n");
    printf("|        |     Д.Кнуту       | Mф+Сф  |        Хиббарду       | Mф+Сф  |\n");
    printf("|////////|///////////////////|////////|///////////////////////|////////|\n");
    for(n=100;n<600;n+=100){
        A = realloc(A,n * sizeof(int));
        FillRand();
        ShellSort();
        int MRandS=M;
        int CRandS=C;
        int m=floor(log2((double)n)-1);
        int H[m];
        H[0]=1;
        for (int i=2;i<m+1;i++){
            H[i-1]=2*H[i-2]+1;
        }
        printf("|%8d|",n);
        for(int i=0;i<m;i++){
            printf("%d ",H[i]);
        }
        if(m==5){
            printf("       ");
        }else if (m==6){
            printf("    ");
        }
        printf("|%8d|",MRandS+CRandS);

        FillRand();
        ShellSort2();
        MRandS=M;
        CRandS=C;
        m=0;
        int k=1;
        int H1[20];
        while(1){
            int h = (int)pow(2,k)-1;
            if(h>=n) break;
            H1[m]=h;
            m++;
            k++;
        }
        for(int i=0;i<m;i++){
            printf("%d ",H1[i]);
        }
        if (m==6){
            printf("        ");
        }else if(m==7){
            printf("    ");
        }
        printf("|%8d|\n",MRandS+CRandS);
    } 
    printf("|////////|///////////////////|////////|///////////////////////|////////|\n");
    free(A);
}



    void FillInc(){
        for(int i =0;i<n;i++){
        A[i]=i+1;
        }
    }
    void FillDec(){
        for(int i=0;i<n;i++){
            A[i]=n-i;
        }
    }
    void FillRand(){
        srand(time(0));
        for(int i =0;i<n;i++){
            A[i]=rand()%(2*n+1);    
        }
    }
    void PrintMas(){
    for(int i =0;i<n;i++){
        printf("%d ", A[i]);
    }    
    printf("\n");
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
void ShellSort2(){
    C=0;
    M=0;
    int m=0;
    int k=1;
    int H1[20];
    while(1){
        int h = (int)pow(2,k)-1;
        if(h>=n) break;
        H1[m]=h;
        m++;
        k++;
    }
    for(int k=H1[m-1];m>=0;m--){
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
    