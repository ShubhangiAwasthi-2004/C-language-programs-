#include<stdio.h>
int main(){
	char aaa[5]={'a','g','t','d','e'};
	char *ptr = &aaa[0];
	printf("The val of third element of the array is : %c",*(ptr+2));
	return 0;
}
