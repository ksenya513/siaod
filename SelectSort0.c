#include <stdlib.h>
#include <stdio.h>
#include "lab1(1).c"

int C=0;//сравнение
int M=0;//пересылки

void SelectSort1();
void SelectSort2();

void main(){
    int teorM=3*(n-1);
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
    printf("Отсортированный массив(1 способ): ");
    SelectSort1();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("\n");
    FillRand();
    printf("Отсортированный массив(2 способ): ");
    SelectSort2();
    sum=CheckSum();
    series=RunNumber();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
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
    printf("Отсортированный массив(1 способ): ");
    SelectSort1();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("\n");
    FillInc();
    printf("Отсортированный массив(2 способ): ");
    SelectSort2();
    sum=CheckSum();
    series=RunNumber();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
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
    printf("Отсортированный массив(1 способ): ");
    SelectSort1();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("\n");
    FillDec();
    printf("Отсортированный массив(2 способ): ");
    SelectSort2();
    sum=CheckSum();
    series=RunNumber();
    PrintMas();
    printf("КС = %d, Кол-во серий = %d\n",sum,series);
    printf("Теоретическое значение  M:%d, фактическое:%d",teorM,M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC,C);
    printf("\n");


}
void SelectSort1(){
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
        int move=A[i];
        A[i]=A[k];
        A[k]=move;
        M+=3;
        
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