#include<stdio.h>

int big1(int num1, int num2){
	if (num1 > num2){
	return num1;
	}
	else{
	return num2;
	}
}

int big2(int num1, int num2){
	return (num1 > num2) ? num1 : num2;
}

int main(){
	int num1, num2;

	printf("Enter the first number: ");
	scanf("%d", &num1);

	printf("Enter the second number: ");
	scanf("%d", &num2);

	int usingIfelse = big1(num1,num2);
	printf("The biggest number using ifelse: %d\n", usingIfelse);

	int usingternary = big2(num1, num2);
	printf("The biggest number using ternary operator: %d\n", usingternary);

	return 0;
}
