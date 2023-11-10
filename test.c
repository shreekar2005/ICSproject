#include<stdio.h>
#include<string.h>
#define fli(i,n,x) for(int abc = i; abc<n;abc+=x)
#define fls(x) for(int abc = 0; abc<x;abc++)
struct t {
    int test;
};
void inc(struct t *a){
    a->test += 1;
}
int main(){ 
    struct t t1 = {5};
    struct t *ptr = &t1;
    inc(ptr);
    printf("%d" , ptr->test);
}