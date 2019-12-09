#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_BOUND  100
#define LOWER_BOUND  1

typedef int (*operation) (int a, int b);

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);


int main (void)
{
	// An array that stores function pointers of type operations
	operation operations[5];
  char option[25];
  
  operations[0] = add;
  operations[1] = subtract;
  operations[2] = multiply;
  operations[3] = divide;
  
  // Randomly generate two operands in range LOWER_BOUND to UPPER_BOUND
  srand(time(NULL));
  int num1 = rand()%(UPPER_BOUND - LOWER_BOUND +1) + LOWER_BOUND;
  int num2 = rand()%(UPPER_BOUND -LOWER_BOUND + 1) + LOWER_BOUND;
  
  while(1){
    printf("Operand 'a' : %d | Operand 'b' : % d\nSpecify the operation to perform\n0 : add | 1 : subtract | 2 : multiply | 3 : divide | 4 : exit the program\n", num1, num2);
    scanf("%s", option);
    // If input is 4 exit program.
    if (atoi(option) == 4){
      printf("Exiting!!!\n");
      break;
    }
    
    int result = (*operations[atoi(option)])(num1, num2);
    printf("Answer: %d\n", result);
  }

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }

int subtract (int a, int b) {printf("Subtracting 'b' from 'a'\n" ); return a-b;}

int multiply (int a, int b) {printf("Multiplying 'a' and 'b'\n"); return a*b;}

int divide (int a, int b) { printf("Dividing 'a' by 'b'\n"); return a/b;}
