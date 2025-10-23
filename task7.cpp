#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
int comparision=0;

int partitionFirst(int arr[], int start, int end){
	int pivot = arr[start];
	int i = start+1;
	for(int j=start+1;j<=end;j++){
		comparision++;
		if(arr[j]<pivot) swap(arr[i++],arr[j]);
	}
	swap(arr[start],arr[i-1]);
	return i-1;
}

int partitionEnd (int arr[], int start, int end){
	int pivot = arr[end];
	int i = start-1;
	for (int j=start; j<end; j++){
		comparision++;
		if(arr[j]<pivot){
			swap(arr[j], arr[++i]);
		}
	}
    swap(arr[++i], arr[end]);
    return i;
}

int partitionMiddle(int arr[],int start,int end){
	int mid = start+(end-start)/2;
	swap(arr[start], arr[mid]);
	return partitionFirst(arr,start,end);
}

int partitionRandom(int arr[],int start,int end){
	int randomIndex = start+rand()%(end-start+1);
	swap(arr[start], arr[randomIndex]);
	return partitionFirst(arr,start,end);
}

int partitionMedian(int arr[],int start,int end){
	//median fron start, end and mid
	int mid = start+(end-start)/2;
	int a=arr[start] , b=arr[mid] , c=arr[end];
	int median;
	if((a<=b&&b<=c) || (c<=b&&b<=a)) median=mid;
	else if((b<=a&&a<=c)||(c<=a&&a<=b)) median=start;
	else median=end;
	comparision+=3;
	swap(arr[start],arr[median]);
	return partitionFirst(arr,start,end);
}

void QuickSort(int arr[], int start, int end, int type=0){
	if(start >=end) return;
	int pivot;
	switch(type){
		case 1: pivot =partitionEnd(arr, start, end);break;
		case 2: pivot =partitionFirst(arr, start, end);break;
		case 3: pivot =partitionMiddle(arr, start, end);break;
		case 4: pivot =partitionMedian(arr, start, end);break;
		default: pivot =partitionRandom(arr, start, end);
	}
	QuickSort(arr, start, pivot-1, type);
	QuickSort(arr, pivot+1, end, type);
}

void testAll(int arr[],int n,string type){
	int copy[10];
	cout<<type<<endl;
	for(int t=1;t<=5;t++){
		for(int i=0;i<n;i++) copy[i]=arr[i];
		comparision=0;
		QuickSort(copy,0,n-1,t);
		switch(t){
			case 1:cout<<"End pivot: ";break;
			case 2:cout<<"First pivot: ";break;
			case 3:cout<<"Middle pivot: ";break;
			case 4:cout<<"Median pivot: ";break;
			default:cout<<"Random pivot: ";
		}
		cout<<comparision<<endl;
	}
	cout<<endl;
}

int main(){
	srand(time(0));
	int sorted[]={1,2,3,4,5,6,7,8,9,10};
	int reverse[]={10,9,8,7,6,5,4,3,2,1};
	int randomArr[]={5,2,9,1,7,3,10,4,6,8};

	testAll(sorted,10,"For Sorted Array:");
	testAll(reverse,10,"For Reverse Sorted Array:");
	testAll(randomArr,10,"For Random Array:");
	return 0;
}
