#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int C=0;//сравнение
int M=0;//пересылки
int n; 
int *A= NULL;

void FillInc();
void FillDec();
void FillRand();
void InsertSort();
void PrintMas();


void main(int argc,char**argv){
    n=10;
    A = (int*)malloc(n * sizeof(int));
    int teorM=((n*n-n)/2+2*n-2)/2;
    int teorC=(n*n-n)/4;
    printf("\n");
    printf("----Массив случайных чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillRand();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    InsertSort();
    PrintMas();
    printf("Среднее теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("Время работы: %d",C+M);
    printf("\n");
    printf("\n");

    printf("----Массив возрастающих чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillInc();
    PrintMas(); 
    printf("\n");
    printf("Отсортированный массив: ");
    InsertSort();
    PrintMas();
    teorM=2*(n-1);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    teorC=n-1;
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("Время работы: %d",C+M);
    printf("\n");
    printf("\n");
   
    printf("----Массив убывающих чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillDec();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    InsertSort();
    PrintMas();
    teorM=n*(n-1)/2+2*n-2;
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    teorC=(n*(n-1))/2;
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("Время работы: %d",C+M);
    printf("\n");
    printf("\n");

    printf("\n");
    printf("\n");
    printf("|////////|////////|//////////////////////////|\n");
    printf("|   N    |  M+C   |         Mф+Сф            |\n");
    printf("|        |  теор. | Убыв.  | Случ.  |Возр .  |\n");
    printf("|////////|////////|////////|////////|////////|\n");

    for(n=100;n<600;n+=100){
        A = realloc(A,n * sizeof(int));
        teorM=((n*n-n)/2+2*n-2)/2;
        teorC=(n*(n-1))/4;
        FillDec();
        InsertSort();
        int MDec=M;
        int CDec=C;
        FillRand();
        InsertSort();
        int MRand=M;
        int CRand=C;
        FillInc();
        InsertSort();
        int MInc=M;
        int CInc=C;
        printf("|%8d|%8d|%8d|%8d|%8d|\n",n,teorM+teorC,MDec+CDec,MRand+CRand,MInc+CInc);
    } 
    printf("|////////|////////|////////|////////|////////|\n");
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
    