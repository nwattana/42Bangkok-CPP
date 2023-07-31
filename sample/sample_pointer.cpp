#include <iostream>
#include <stdio.h>

int main(void){
    int num = 10;
    int *ptr = &num;
    int *ptr2;
    int &num2=num;

    printf("num: %d\n", num);
    printf("&num: %p\n", &num);
    printf("ptr: %p\n", ptr);
    printf("ptr2: %p\n", ptr2);
    printf("num2: %d\n", num2);


}