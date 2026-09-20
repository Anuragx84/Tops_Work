/*2.Build a class Product for a Flipkart-style app with a parameterized constructor 
that takes productName, price, and rating as arguments and displays all details using a displayInfo() method.*/

#include<iostream>
using namespace std;

class Product{
	public : 
		string productName;
		int price;
		float rating;
	Product(string productName,int price,float rating){
		this->productName = productName;
		this->price = price;
		this->rating = rating;
	}
	void displayInfo(){
		cout<<"Product : "<<productName<<", Price : "<<price<<", Rating : "<<rating<<endl;
	}
}; 

int main(){
	Product p1("Samsung Mobile", 25000, 4.5);
	p1.displayInfo();
	return 0;
}
