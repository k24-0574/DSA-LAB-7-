#include <iostream>
using namespace std;

class Product{
	public:
	string name;
	double price;
	string description;
	bool availability;
	Product(){}
	Product(string n, double p, string d, bool a):name(n), price(p), description(d), availability(a){}
    void display(){
        cout<<name<<" - $"<<price<<endl;
    }
	
};

int partition (Product arr[], int start, int end){
	int pivot = arr[end].price;
	int i = start-1;
	for (int j=start; j<end; j++){
		if(arr[j].price<pivot){
			swap(arr[j], arr[++i]);
		}
	}
    swap(arr[++i], arr[end]);
    return i;
}
void QuickSort(Product arr[], int start, int end){
	if(start >=end) return;
	int pivot = partition(arr, start, end);
	
	QuickSort(arr, start, pivot-1);
	QuickSort(arr, pivot+1, end);
}

int main(){
    Product products[3] = 
    {Product("Product 1", 10.99, "This is product 1", true),
     Product("Product 2", 5.99, "This is product 2", false),
     Product("Product 3", 2.99, "This is product 3", true)
    };
    QuickSort(products, 0, 2);
    cout<<"Products sorted by price: "<<endl;
    for(int i=0;i<3;i++) products[i].display();

	return 0;
}
