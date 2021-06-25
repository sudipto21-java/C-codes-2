/* Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. 
* Return the maximum possible summation of i*arr[i].
 
Input: arr[] = {1, 20, 2, 10}
Output: 72
We can get 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9}
Output: 330
We can get 330 by rotating array 9 times.
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
0*1 + 1*2 + 2*3 ... 9*10 = 330	*/

#include<stdio.h>

int RotateArrAndSum(int arr[], int n) {
	
	int sum=0,i,tarr[n],j;
	
	for(i=0,j=i+1;i<n-1;i++,j++) {
		tarr[j]=arr[i];
	}
	tarr[0]=arr[n-1];
	
	for(i=0;i<n;i++) {
		
		sum+=tarr[i]*i;
	}
	
	for(i=0;i<n;i++) {
		arr[i]=tarr[i];
	}
	
	return sum;
}

int MaxSum1(int arr[], int n) {			// time complexity O(n^2) and space complexity O(n)
	
	int sum=0,i,j,maxsum=0,cursum=0;
	
	for(i=0;i<n;i++) {
		
		sum+=arr[i];
		cursum+=i*arr[i];		// 0-th rotation
	}
	
	maxsum=cursum;
	
	for(j=1;j<n;j++) {
		
		cursum=RotateArrAndSum(arr,n);
		
		if(maxsum<cursum)
			maxsum=cursum;
	}
	
	return maxsum;
}

int MaxSum2(int arr[], int n) {			// time complexity O(n) and space complexity O(1)
	
	int i,sum=0,cursum=0,maxsum=0;
	
	for(i=0;i<n;i++) {
		
		sum+=arr[i];
		cursum+=arr[i]*i;
	}
	
	maxsum=cursum;
	
	for(i=1;i<n;i++) {
		
		cursum+=sum-(n*arr[n-i]);
		
		if(cursum>maxsum)
			maxsum=cursum;
	}
	
	return maxsum;
}

int main() {
	
	int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n=sizeof(arr)/sizeof(int);

	printf("Maximum allowed sum using method_1 is:%d\n",MaxSum1(arr,n));
	printf("Maximum allowed sum using method_2 is:%d",MaxSum2(arr,n));
	
	return 0;
}
