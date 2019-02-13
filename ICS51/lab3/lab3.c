/*
	ICS 51. Lab #3

	IMPORTATNT NOTES:

	- Noramally, the compiler adds the prologue/epilogue code for the callee. However, when the
	__declspec(naked) attribute is used, it is the programmer's responsibility to write the
	prologue/epilogue code. In this lab you need to write prologue/epilogue code sections only
	for the functions that have been declared with the naked attribute, namely:

	   + findMinIndex
	   + recFactorial
	   + performOperation
	   + fibonacci

	- You cannot define any local variable in the C code. If you need additional variables in your
	assembly code, you have to allocate space for them in the prologue of the function.

	- You are not allowed to change anything in this file except for adding your assembly code
    between the lines marked "BEGIN YOUR CODE HERE" and "END YOUR CODE HERE".

	- Remember to fill in your name, student ID below.

	- ONLY submit the lab3.c file for grading.

*/

char *yourName = "Derek Yang";
char *yourStudentID = "63118832";

/***********************************************************************************************

	PART 1: Selection Sort

	Selection sort is an in-place comparison sort algorithm that works by dividing the input list
	into two parts: the sublist of items already sorted, which is built up from left to right of
	the list, and the sublist of items remaining to be sorted that occupy the rest of the list.
	Initially, the sorted sublist is empty and the unsorted sublist is the entire input list.
	The algorithm proceeds by finding the smallest element in the unsorted sublist, exchanging it
	with the leftmost unsorted element (putting it in sorted order), and moving the sublist
	boundaries one element to the right. To learn more, read:
	https://en.wikipedia.org/wiki/Selection_sort#Example

	Our implementation here uses a function called "findMinIndex" to find the index of smallest
	element between ith index and jth index of the array. The function "selectionSort" uses
	this function to find the smallest number and exchanges it with the leftmost unsorted element
	in each iteration. You need to implement the behavior of both functions in x86 assembly.

************************************************************************************************/

__declspec(naked)
int findMinIndex (int integer_array[], int i, int j)
{

// C code to be converted to x86 assembly
/*
    int iMin = i;
    // test against elements after i and before j to find the smallest
    for ( i ; i < j; i++) {
        // if this element is less, then it is the new minimum
        if (integer_array[i] < integer_array[iMin]) {
            // found new minimum; remember its index
            iMin = i;
        }
    }

    return iMin;
*/

	__asm{
		
			// BEGIN YOUR CODE HERE
			push ebp
			mov ebp, esp

			push edi
			push esi
			push ebx
			
			//integer array
			mov eax, [ebp+8]
			//int imin
			mov ebx, [ebp+12]
			//int j
			mov ecx, [ebp+16]
			//int i
			mov edx, ebx

		I_LOOP:
			cmp ebx, ecx
			jge END_I_LOOP

			//array[imin]
			mov esi, [eax+4*ebx]
			//array[i]
			mov edi, [eax+4*edx]
			//if i< imin
			cmp esi, edi
			jge NEXT
			//imin = i
			mov edx, ebx

		NEXT:
			inc ebx
			jmp I_LOOP

		END_I_LOOP:
			mov eax, edx

			pop ebx
			pop esi
			pop edi

			mov esp, ebp
			pop ebp
			
			// END YOUR CODE HERE
			ret
	}

}

void selectionSort (int integer_array[], int array_size)
{

// C code to be converted to x86 assembly
/*
	int j;
	int iMin;
	int temp;

	// advance the position through the entire array //
	// (could do j < n-1 because single element is also min element) //
	for (j = 0; j < array_size-1; j++) {

		// find the index of min element in the unsorted a[j .. n-1] //
 		iMin = findMinIndex (integer_array, j, array_size);

		if(iMin != j) { // swap values
			temp = integer_array[iMin];
			integer_array[iMin] = integer_array [j];
			integer_array[j] = temp;
		}
	}
*/

	__asm{
			// BEGIN YOUR CODE HERE
			mov edi, integer_array
			//edx = n-1
			mov edx, array_size
			dec edx
			//j=0
			mov esi, 0

		J_LOOP:
			cmp esi, edx
			jge END_J_LOOP

			push eax
			push ecx
			push edx

			mov ebx, array_size

			//3rd param int j
			push ebx
			//2nd param int i
			push esi
			//1st param integer array
			push edi

			//call to function
			call findMinIndex
			
			//clear stack
			add esp, 12
			mov ebx, eax

			pop edx
			pop ecx
			pop eax

			cmp ebx, esi
			je NEXT

			//j nad imin
			mov eax, [edi+4*ebx]
			mov ecx, [edi+4*esi]

			//swap eax and ecx using xor
			xor eax, ecx
			xor ecx, eax
			xor eax, ecx

			mov[edi+4*ebx], eax
			mov[edi+4*esi], ecx

		NEXT:
			inc esi
			jmp J_LOOP

		END_J_LOOP:
			mov integer_array, edi


			// END YOUR CODE HERE
	}

}

/***********************************************************************************************

    PART 2: Recursive Factorial

	Implement two functions that calculates the factorial of an integer not greater than 12.

	The 1st function, factorial (unsigned int input, unsigned int *output), is the non
	recursive wrapper function which takes the input, sets up the stack, calls the recursive
	function and finally puts the result in the location pointed to by the pointer argument called
    output.

	The 2nd function, recFactorial(unsigned int n), is the recursive function that actually
	calculates the factorial.

	Given an unsigned integer number n,we define FACTORIAL(n) as:

        FACTORIAL(n) =  1                   ,    if n = 0 or n = 1
                        n * FACTORIAL(n-1)  ,    if n > 1

	Tip:

	- You need to use IMUL instruction to multiply unsigned integers. Learn how to use it:
	http://www.cs.virginia.edu/~evans/cs216/guides/x86.html#instructions

************************************************************************************************/

__declspec(naked)
unsigned int recFactorial (unsigned int n)
{

// C code to be converted to x86 assembly
/*
	if (n<=1)
		return 1;
	else
		return n * recFactorial(n-1);
*/

	__asm{
			// BEGIN YOUR CODE HERE

			push ebp
			mov ebp, esp
			//unsignedint n
			mov ebx, [ebp+8]

			//if n<=1
			mov eax, 1
			cmp ebx, 1
			jbe ELSE
			
			//n=n-1
			dec ebx
			push ebx
			
			//call on n-1
			call recFactorial
			
			//clear stack
			add esp, 4
			mov ebx, eax
			//ebx*n-1
			imul ebx, [ebp+8]
			mov eax, ebx

		ELSE:
			mov esp, ebp
			pop ebp
			// END YOUR CODE HERE

			ret
	}

}

void factorial (unsigned int input, unsigned int *output)
{

// C code to be converted to x86 assembly
/*
	*output = recFactorial (input);
*/

	__asm{
			// BEGIN YOUR CODE HERE
			
			mov eax, input
			push eax

			//call fact(input)
			call recFactorial

			//clear stack
			add esp, 4

			//return output
			mov ebx, output
			mov[ebx], eax

			// END YOUR CODE HERE
	}

}

/***********************************************************************************************

    PART 3: Vector Operation

	The vectorOperations function gets as parameters 4 arrays of the same length and
	the number of elements in those arrays.

	For each pair of elements in first_array and second_array, it calls performOperation
	and stores the returned result in the same index of output_array.

	output_array[index] = performOperation(operation_array[index], first_array[index], second_array[index]).

	You also need to implement the body of performOperation function according to the provided
	C code.

************************************************************************************************/

__declspec(naked)
int performOperation (int operation, int first, int second)
{

// C code to be converted to x86 assembly
/*
	if (operation==0)
		return first + second;
	else if (operation==1)
		return first - second;
	else if (operation==2)
		return (first > second)? first : second;
	else if (operation==3)
		return (first < second)? first : second;
	else
		return first;
*/

	__asm {
			// BEGIN YOUR CODE HERE
			push ebp
			mov ebp, esp
			sub esp, 4

			//operation
			mov ebx, [ebp+8]
			//first
			mov ecx, [ebp+12]
			//second
			mov edx, [ebp+16]
			
			//if op == 0
			cmp ebx, 0
			jne ELSE_IF_ONE

			//return first+second
			mov [ebp-4], ecx
			add [ebp-4], edx
			mov eax, [ebp-4]
			jmp END
		
			//if op == 1
		ELSE_IF_ONE:
			cmp ebx, 1
			jne ELSE_IF_TWO

			//return first-second
			mov [ebp-4], ecx
			sub [ebp-4], edx
			mov eax, [ebp-4]
			jmp END

			//if op == 2
		ELSE_IF_TWO:	
			cmp ebx, 2
			jne ELSE_IF_THREE

			cmp ecx, edx
			jg F_GT_S

			//return second
			mov eax, edx
			jmp END
			
			//if first > second
		F_GT_S:
			//return first
			mov eax, ecx
			jmp END

			//if op == 3
		ELSE_IF_THREE:
			cmp ebx, 3
			jne ELSE

			cmp ecx, edx
			jl F_LT_S

			//return second
			mov eax, edx
			jmp END

			// if first < second
		F_LT_S:
			//return first
			mov eax, ecx
			jmp END

			//else
		ELSE:
			//return first
			mov eax, ecx

		END:
			mov esp, ebp
			pop ebp
			// END YOUR CODE HERE
			ret
	}

}

void vectorOperations (int number_of_elements, int *first_array, int *second_array,
					   int *operation_array, int *output_array)
{
// C code to be converted to x86 assembly
/*
	int i;
	for (i=0; i<number_of_elements; i++)
	{
		output_array[i] = performOperation(operation_array[i], first_array[i], second_array[i]);
	}
*/

	__asm {
			// BEGIN YOUR CODE HERE
			mov edi, output_array
			// i =0
			mov esi, 0

		I_LOOP:
			cmp esi, number_of_elements
			jge END_I_LOOP

			//second_array[i]
			mov eax, second_array
			mov eax, [eax+4*esi]
			//first_array[i]
			mov ebx, first_array
			mov ebx, [ebx+4*esi]
			//operation_array[i]
			mov ecx, operation_array
			mov ecx, [ecx+4*esi]

			//push parameters to stack
			push eax
			push ebx
			push ecx

			//call function with params on stack
			call performOperation

			//clear stack
			add esp, 12
			
			//store output[i]
			mov [edi+4*esi], eax

			inc esi
			jmp I_LOOP

		END_I_LOOP:
			//return output
			mov output_array, edi
			// END YOUR CODE HERE
	}
}

/***********************************************************************************************

    PART 4: Change Letter Case

	You are given an array of characters (a string) that may contain numbers, upper and	lower case
    letters, punctuations symbols, etc. Implement a function to convert all uppercase letters to
    lowercase and vice versa.
    For example "ThisIsTheFinalLabOf51" should be converted to "tHISiStHEfINALlABoF51".
	The function has the following argument: An array of charaters and the size of the array. The
	array should be changed in place. There is no explicit output for this function.

	Tips:

	- Note that each element of the arrays is a char (1 byte). You can NOT use a 32-bit register
	to read/write from/to a memory location. Instead you should use the 8-bit version of the x86
	general-purpose registers.
	More info: http://www.cs.virginia.edu/~evans/cs216/guides/x86.html#registers

	- The link to the ascii codes is here: http://www.asciitable.com/

************************************************************************************************/

void changeCase (char char_array[], int array_size ) {

	__asm{
			// BEGIN YOUR CODE HERE
			mov ebx, char_array

			mov esi, 0
		UPPER:
			cmp esi, array_size
			jge END_UPPER

			//char_array[i]
			mov al, byte ptr[ebx+esi]
			//check 65 == A
			cmp al, 65
			jl ELSE

			//check 90 == Z
			cmp al, 90
			jg LOWER

			//change upper to lower case
			add al, 32
			//store changed char
			mov byte ptr[ebx+esi], al
			jmp ELSE

		LOWER:
			//check 97 == a
			cmp al, 97
			jl ELSE

			//check 122 == z
			cmp al, 122
			jg ELSE

			//change lower to upper case
			sub al, 32
			//store changed char
			mov byte ptr[ebx+esi], al

		ELSE:
			inc esi
			jmp UPPER

		END_UPPER:
			//return new array
			mov char_array, ebx

			// END YOUR CODE HERE
	}
}

/***********************************************************************************************

    PART 5: Fibonacci

	Implement a recursive function in assembly which returns the Nth number in the fibbonaci
	series (1, 1, 2, 3, 5, 8, ...).

************************************************************************************************/

__declspec(naked)
unsigned int fibonacci (unsigned int n) {

// C code to be converted to x86 assembly
/*
	if (n < 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
*/

	__asm{
			// BEGIN YOUR CODE HERE
			push ebp
			mov ebp, esp

			push edi
			push esi
			push ebx

			//store n into ebx
			mov ebx, [ebp+8]

			mov eax, 1
			//if n < 2 return 1
			cmp ebx, 2
			jb END

			//else return fibonacci
			xor eax, eax

			push eax
			push ecx
			push edx

			//move n-1 into ecx
			mov ecx, ebx
			dec ecx

			//push to stack to call func
			push ecx

			//fib(n-1)
			call fibonacci

			//clear stack
			add esp, 4
			mov esi, eax
			//n-2 into ecx
			mov ecx, ebx
			sub ecx, 2

			//push n-2 to call stack
			push ecx

			//fib(n-2)
			call fibonacci

			//clear stack
			add esp, 4

			mov edi,eax

			pop edx
			pop ecx
			pop eax
			// add fib(n-1), fib(n-2)
			mov eax, esi
			add eax, edi

		END:
			pop ebx
			pop esi
			pop edi

			mov esp, ebp
			pop ebp

			// END YOUR CODE HERE
			ret
	}
}
