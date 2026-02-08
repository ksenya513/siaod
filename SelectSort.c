#include <stdlib.h>
#include <stdio.h>
#include "lab1(1).c"


void main(){
    int C=0;//сравнение
    int M=0;//пересылки
    FillRand();
    int sum=CheckSum();
    int series=RunNumber();
    printf("Исходный массив: ");
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    for (int i=0;i<n-1;i++){
        int k=i;
        for (int j=i+1;j<n;j++){
            C++;
            if (A[j]<A[k]){
                k=j;
            }
        }
        int move=A[i];
        M++;
        A[i]=A[k];
        M++;
        A[k]=move;
        M++;
    }
    sum=CheckSum();
    series=RunNumber();
    printf("Отсортированный массив: ");
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    int teorM=3*(n-1);
    int teorC=(n*(n-1))/2;
    printf("\n  Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n  Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
}