#include <iostream>
using namespace std;

void Merge(int *arr, int start, int end, int mid){
	int *temp = new int[end-start+1];
	int i=start, j=mid+1, count=0;
	
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]) temp[count++] = arr[i++];
		else temp[count++] = arr[j++];
	}
	while(i<=mid) temp[count++] = arr[i++];
	while(j<=end) temp[count++] = arr[j++];
	
	count =0;
	i=start;
	while(i<=end) arr[i++] = temp[count++];
	
	delete[] temp;
}

void mergeSort(int *arr, int start, int end){
	if(start>=end) return;
	int mid = start + (end-start)/2;
	
	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);
	
	Merge(arr, start, end, mid);
	
}

void sortArray(int *&arr, int arr1[], int arr2[], int size1, int size2){
	arr = new int[size1+size2];
	for(int i=0;i<size1;i++) arr[i] = arr1[i];
	for(int i=0;i<size2;i++) arr[size1+i] = arr2[i];
	mergeSort(arr, 0, size1+size2-1);
}

int main(){
	int arr1[10]={9,4,1,8,22,7,3,6,45,0};
	int arr2[10]={15,2,19,8,18,11,3,6,17,10};
	int* arr;
	sortArray(arr, arr1, arr2, 10, 10);
	cout<<"Array 1: ";
	for(int i=0;i<10;i++) cout<<arr1[i]<<" " ;
	cout<<endl<<"Array 2: ";
	for(int i=0;i<10;i++) cout<<arr2[i]<<" " ;
	cout<<endl<<"Sorted array: "<<endl;
	for(int i=0;i<20;i++) cout<<arr[i]<< " ";

	return 0;
}
