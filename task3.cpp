#include <iostream>
using namespace std;

struct participant{
	string name;
	int time;
};

void Merge(participant *arr, int start, int end, int mid){
	participant *temp = new participant[end-start+1];
	int i=start, j=mid+1, count=0;
	
	while(i<=mid && j<=end){
		if(arr[i].time<arr[j].time) temp[count++] = arr[i++];
		else temp[count++] = arr[j++];
	}
	while(i<=mid) temp[count++] = arr[i++];
	while(j<=end) temp[count++] = arr[j++];
	
	count =0;
	i=start;
	while(i<=end) arr[i++] = temp[count++];
	
	delete[] temp;
}

void mergeSort(participant *arr, int start, int end){
	if(start>=end) return;
	int mid = start + (end-start)/2;
	
	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);
	
	Merge(arr, start, end, mid);
	
}

int main(){
	participant *P = new participant[10];
	
	for(int i=0;i<10;i++){
		cout<<"Enter name and finish time for runner "<<i+1<<": ";
		cin>>P[i].name;
		cin>>P[i].time;
	}
	mergeSort(P, 0, 9);
	cout<<"Top 5 fastest runners: "<<endl;
	for(int i=0;i<5;i++){
		cout<<i+1<<". "<<P[i].name<<" - "<<P[i].time<<" seconds"<<endl;
	}
	
	
	delete[] P;
	return 0;
}

