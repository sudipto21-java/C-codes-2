/* Array name indicates address of the first element and array are always passed as a pointer (even if we use
square braces). Arrays in C language does not calculate array bounds during compile time.
Vectors in C++ is a class of Standard Tamplete Library (STL) and also known as dynamic array */

#include<stdio.h>

void demo(int a[]) {
	
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++) {
		
		printf("%d\t",a[i]);
	}
}

int main() {
	
	int arr[3]= {2,6,8};
	int *ptr=arr;
	
	// array members are accessed using pointer arithmatic
	printf("%d\n",arr[2]);
	printf("by arr:%d\n",*(arr+1));
	printf("by ptr:%d\n",*(ptr+1));
	
	// array name given address of first element
	printf("by arr:%d and by ptr:%d\n", *arr, *ptr);
	
	// array name is a pointer to access memory locations
	printf("address of arr:%d and address of ptr:%d\n", arr, ptr);
	
	// different behaviour of array and pointer
	printf("size of arr:%d and size of ptr:%d\n", sizeof(arr), sizeof(ptr));
	
	// arrays are always passed as a parameter in a function
	demo(arr);
	
	return 0;
}
