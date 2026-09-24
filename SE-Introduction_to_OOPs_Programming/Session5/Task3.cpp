/*3.Write a function in Java or Python that simulates a Flipkart-style search: overload a method searchProduct() 
to allow searching by product name or by product name and category. Demonstrate both usages with sample data.*/

#include<iostream>
using namespace std;

class Flipkart{
	public : 
		void searchProduct(string productName){
				cout<<"searching : "<<productName<<endl;
		}
		
		void searchProduct(string productName, string category){
				cout<<"searching : "<<productName<<",category : "<<category<<endl;
		}
};

int main(){
	Flipkart find;
	find.searchProduct("ideapdSlim3");
	find.searchProduct("hauser","pen");
	return 0;
}
