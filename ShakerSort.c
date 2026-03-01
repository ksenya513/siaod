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
void ShakerSort();
void PrintMas();


void main(int argc,char**argv){
    n=10;
    A = (int*)malloc(n * sizeof(int));
    int teorM=3*n*(n-1)/4;
    int teorC=(n*(n-1))/2;
    printf("\n");
    printf("----Массив случайных чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillRand();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    ShakerSort();
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
    ShakerSort();
    PrintMas();
    teorM=0;
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
    ShakerSort();
    PrintMas();
    teorM=3*n*(n-1)/2;
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
        teorM=3*n*(n-1)/4;
        teorC=(n*(n-1))/4;
        FillDec();
        ShakerSort();
        int MDec=M;
        int CDec=C;
        FillRand();
        ShakerSort();
        int MRand=M;
        int CRand=C;
        FillInc();
        ShakerSort();
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

