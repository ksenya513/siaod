#include <stdio.h>
#include <stdlib.h>
#include "lab1(1).c"

int C=0;//сравнение
int M=0;//пересылки

void BubbleSort();

void main(){
    int teorM=3*n*(n-1)/4;
    int teorC=(n*(n-1))/2;
    printf("\n");
    printf("----Массив случайных чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillRand();
    int sum=CheckSum();
    int series=RunNumber();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series); 
    printf("\n");
    printf("Отсортированный массив: ");
    BubbleSort();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
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
    sum=CheckSum();
    series=RunNumber();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series); 
    printf("\n");
    printf("Отсортированный массив: ");
    BubbleSort();
    PrintMas();
    teorM=0;
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("Время работы: %d",C+M);
    printf("\n");
    printf("\n");
   
    printf("----Массив убывающих чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillDec();
    sum=CheckSum();
    series=RunNumber();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series); 
    printf("\n");
    printf("Отсортированный массив: ");
    BubbleSort();
    PrintMas();
    teorM=3*C;
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("Время работы: %d",C+M);
    printf("\n");
    printf("\n");
    printf("|/////|//////|////////////////////|\n");
    printf("|  N  | M+C  |       Mф+Сф        |\n");
    printf("|     |теор. | Убыв.| Случ.|Возр. |\n");
    printf("|/////|//////|//////|//////|//////|\n");
    printf("| 100 |12375 |15291 |11030 |6670  |\n");
    printf("|/////|//////|//////|//////|//////|\n");
    printf("| 200 |49750 |70391 |46505 |23820 |\n");
    printf("|/////|//////|//////|//////|//////|\n");
    printf("| 300 |112125|165491|99536 |50970 |\n");
    printf("|/////|//////|//////|//////|//////|\n");
    printf("| 400 |199500|300591|185274|88120 |\n");
    printf("|/////|//////|//////|//////|//////|\n");
    printf("| 500 |311875|475691|300924|135270|\n");
    printf("|/////|//////|//////|//////|//////|\n");
}

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
