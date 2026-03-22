#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

int C=0;//сравнения
int x;//икс
int n;// количесвто элементов в массиве
int *A= NULL;//массив А
bool found;
int m=0;

void FillRand();
void ShellSort();
void BinarySearch1();
void BinarySearch2();
void BinarySearchAll1();
void BinarySearchAll2();
void PrintMas();


void main(int argc,char**argv){
    printf("Введите размер массива:\n");
    scanf("%d",&n);
    printf("Введите искомый элемент:\n");
    scanf("%d",&x);
    A = (int*)malloc(n * sizeof(int));
    int teorС1=2*floor((double)(log2(n)));
    int teorС2=floor((double)(log2(n))+1);
    printf("Исходный массив: ");
    FillRand();
    ShellSort();
    PrintMas();
    printf("1 версия: ");
    FillRand();
    ShellSort();
    BinarySearch1();
    if(found==false){
        printf("!!!Такого элемента нет в массиве!!!\n");
    }else{printf("%d",A[m]);}
    printf("\n");
    printf("Фактическое значение С:");
    printf("%d",C); 
    printf("\n");
    printf("Теоретическое значение С:");
    printf("%d",teorС1);
    printf("\n");
    printf("2 версия: ");
    FillRand();
    ShellSort();
    BinarySearch2(); 
    if(found==false){
        printf("!!!Такого элемента нет в массиве!!!\n");
    }else{printf("%d",A[m]);}
    printf("\n");
    printf("Фактическое значение С:");
    printf("%d",C);
    printf("\n");
    printf("Теоретическое значение С:");
    printf("%d",teorС2);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("|////////|/////////////////|\n");
    printf("|   N    |  Cф 1в |  Cф 2в |\n");
    printf("|////////|////////|////////|\n");

    for(n=100;n<1100;n+=100){
        A = realloc(A,n * sizeof(int));
        FillRand();
        ShellSort();
        BinarySearch1();
        int C_1=C;
        BinarySearch2();
        int C_2=C;
        printf("|%8d|%8d|%8d|\n",n,C_1,C_2);
    } 
    printf("|////////|////////|////////|\n");
     printf("\n");
    printf("\n");
    printf("\n");
    printf("|////////|/////////////////|\n");
    printf("|   N    |Cф all1в|Cф all2в|\n");
    printf("|////////|////////|////////|\n");

    for(n=100;n<1100;n+=100){
        int C_1=0;
        int C_2=0;
        A = realloc(A,n * sizeof(int));
        FillRand();
        ShellSort();
        C=0;
        BinarySearchAll1();
        C_1+=C;
        C=0;
        BinarySearchAll2();
        C_2+=C;
        printf("|%8d|%8d|%8d|\n",n,C_1,C_2);
    } 
    printf("|////////|////////|////////|\n");
    free(A);
}

    void PrintMas(){
    for(int i =0;i<n;i++){
        printf("%d ", A[i]);
    }    
    printf("\n");
}
 void FillRand(){
        srand(time(0));
        for(int i =0;i<n-1;i++){
            A[i]=rand()%(n+1);    
        }
        A[n-1]=5;
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

void BinarySearchAll1(){
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
    C+=2;
    if(A[m-1]==x||A[m+1]==x){
        A[m]=x+1;
        ShellSort();
        BinarySearchAll1();    
    }
}

void BinarySearchAll2(){
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
    C++;
    if(A[m+1]==x){
        A[m]=x+1;
        ShellSort();
        BinarySearchAll2();
    }
}

void ShellSort(){
    int m=floor(log2((double)n)-1);
    int H[m];
    H[0]=1;
    for (int i=2;i<m+1;i++){
        H[i-1]=2*H[i-2]+1;
    }
    for(int l=m-1;l>=0;l--){
        int k=H[l];
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


    