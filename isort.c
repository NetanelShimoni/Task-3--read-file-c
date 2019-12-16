//
// Created by netanel on 15/12/2019.
//
#include <string.h>
#include <stdio.h>
void swap(int *a,int *b);
void insertion_sotr(int *arr,int len);
void shift_element(int *arr,int i);
#define size_array 50
int main()
{
    int i=0;
    int r [size_array]={0};
    for (int j = 0; j < size_array; ++j) {
        scanf("%d", &i);
        *(r+j)=i;
    }
    insertion_sotr(r,size_array);
    for (int k = 0; k <size_array ; ++k) {
        if (k== size_array - 1) {
            printf("%d", *(r + k));
        } else {
            printf("%d", *(r + k));
            printf(",");
        }
    }
    return 0;
}
void shift_element(int *arr,int i) {
    for (int j = 0; j < i; j++) {
        *(arr + i - j) = *(arr + i - j - 1);
    }
}
void insertion_sotr(int *arr,int len)
{
    for (int i = 0; i <len ; ++i) {
        for (int j = i+1; j <len ; ++j) {
            if (*(arr+i)>*(arr+j)){
            swap((arr+i),(arr+j));
            }
        }
        }
}
void swap(int *a,int *b){
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;
}