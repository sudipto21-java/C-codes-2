#include<stdio.h>

void getPairs(int arr1[], int arr2[], int sum, int n1, int n2) {
	
	int i,j;
	
	for(i=0;i<n1;i++) {
		for(j=0;j<n2;j++) {
			
			if(arr1[i]+arr2[j]==sum)
				printf("%d %d\n",arr2[i],arr2[j]);
		}
	}
}

int main() {
	
	int arr1[] = {-1, -2, 4, -6, 5, 7};
    int arr2[] = {6, 3, 4, 0};
    int sum=8;
    
    getPairs(arr1,arr2,sum,6,4);
	return 0;
}
