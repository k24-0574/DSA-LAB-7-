#include <iostream>
using namespace std;

int findMAX(int arr[], int size){
	int m = 0;
	for(int i=0;i<size;i++){
		if(arr[i]>m) m=arr[i];
	}
	return m;
}

void countSort(int arr[], int size, int exp){
	int count[10] = {0};
	
	for(int i=0;i<size;i++) count[(arr[i]/exp)%10]++;
	
	for(int i=1;i<10;i++) count[i]+= count[i-1];
	
	int *output = new int[size];
	for(int i=size-1; i>=0;i--){
		int dig = (arr[i]/exp)%10;
		output[count[dig]-1] = arr[i];
		count[dig]--;	
	}
	
	for(int i=0;i<size;i++) arr[i] = output[i];
	delete[] output; 
	
}

void radixSort(int arr[], int size){
	int maxVal = findMAX(arr, size);
	
	for(int exp = 1; maxVal/exp>0; exp*=10){
		countSort(arr, size, exp);
	}
}

int main(){
	int arr[] = {36, 987, 657, 2, 20, 99, 456, 957, 555, 420, 66, 3};
	int size = sizeof(arr)/sizeof(arr[0]);
	radixSort(arr, size);
	
	for(int i=0;i<size;i++) cout<<arr[i]<<" ";
	
	return 0;
}
