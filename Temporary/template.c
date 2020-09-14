#include <stdio.h>
#include <stdlib.h>

//functions
int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int main(int argc, char* argv[]){

	//FUNCTION POINTERS
	/*
	int (*ptr)(int, int);
	ptr = &add;

	int ans = ptr(2, 3);

	ptr = &sub;

	int ans2 = ptr(2, 3);

	printf("%d\n", ans2);
	*/


	// printf("%s\n", argv[0]); prints template.exe


	//FILE READ WRITE
	
	// FILE *file = fopen("input.txt", "r");

	// if(file==0){
	// 	printf("could not open\n");
	// }
	// else{
	// 	char x;
	// 	while( (x=fgetc(file)) != EOF ) {
	// 		printf("%c\n", x);
	// 	}
	// 	fclose(file);
	// }
	

	


}