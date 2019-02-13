//as long as you have pointers the default copy constructor is bad
//otherwise the default copy constructors is fine

//dynamic allocation from the freestore(heap)

//cost of dynamic allocation
//1.performance (1000x's more allocations from heap)
//2.
//advantages
//1.flexible

//using pointers outside of class have higher chance of memory leaks

//delete[]  the brackets makes sure the array also get destructed, or else
// on the memory is freed but the array is still there.

//copy constructor- makes a clone of object
//when you have pointers, you must make the copy constructor

//returning a & (reference to an object), you can you it as a l or r value
//(right/left value) left = right;
//l store into the cell
//r read out of the cell
//copies can only be used as R values

//type this is a Vector* (pointer to a vector)
//assignment is different from constructor bc/
// this is already constructed
//with assignment,
//arrays cannot be made bigger or smaller
// you need to delete old array and create a new array


// uninitialized pointer is a grabage pointer
//dangling referece - pointer to a deleted storage

//never return a local variable of a returned reference

// int * IntPointer -- int pointer variable
// typedef int * IntPointer -- intPointer == int *