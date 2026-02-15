#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int n = 10;
int A[10];

void FillInc(){
    for(int i =0;i<n;i++){
        A[i]=i+1;
    }
}
//Массив возрастающими числами 
void FillDec(){
    for(int i=0;i<n;i++){
        A[i]=n-i;
    }
}
//Массив убывающими числами
void FillRand(){
    srand(time(0));
    for(int i =0;i<n;i++){
        A[i]=rand()%(2*n+1);    
    }
}
//Массив случайными числами
int CheckSum(){
    int s=0;
    for(int i =0;i<n;i++){
        s+=A[i];
    }
    return s;
}
//КС
int RunNumber(){
    int s = 1;
    for(int i =0;i<n-1;i++){
        if(A[i]>A[i+1]){
            s++;
        }
    }
    return s;    
}
//Серии в массиве
void PrintMas(){
    for(int i =0;i<n;i++){
        printf("%d ", A[i]);
    }    
    printf("\n");
}
//Вывод элементов массива

// void main(){
//     FillInc();
//     PrintMas();
//     int sum = CheckSum();
//     int ser = RunNumber();
//     printf("Сумма = %d, Кол-во серий = %d\n",sum,ser);
//     FillDec();
//     PrintMas();
//     int sum1 = CheckSum();
//     int ser1 = RunNumber();
//     printf("Сумма = %d, Кол-во серий = %d\n",sum1,ser1);
//     FillRand();
//     PrintMas();
//     int sum2 = CheckSum();
//     int ser2 = RunNumber();
//     printf("Сумма = %d, Кол-во серий = %d\n",sum2,ser2);
//}

