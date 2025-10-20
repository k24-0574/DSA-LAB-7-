#include <iostream>
using namespace std;

class Product{
	public:
	string name;
	double price;
	string description;
	bool availability;
	Product(){}
	Product(string n, double p, string d, bool a):name(n), price(p), description(d), availbility(a){}
	
};

int partition (Product *arr, int start, int end){
	int pivot = arr[end].price;
	int i = start-1;
	for (int j=start; j<end; j++){
		if(arr[j].price<pivot){
			Product temp(arr[])
			
		}
	}
		//swap
		return i;
		
}
void QuickSort(int *arr, int start, int end){
	if(start >=end) return;
	int pivot = partition(arr, start, end);
	
	QuickSort(arr, start, pivot-1);
	QuickSort(arr, pivot+1, end);
}

int main(){
	
	
	return 0;
}

