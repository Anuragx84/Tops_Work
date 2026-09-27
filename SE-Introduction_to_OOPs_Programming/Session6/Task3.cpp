/*Imagine a Flipkart-like app: create an abstract class Product with an abstract method upload(). 
Then, create two subclasses, Electronics and Clothing, that each implement the upload() method to print a different upload message.*/
#include<iostream>
using namespace std;

class Product{
	protected :
		virtual void upload() = 0;
};

class Electronics : public Product{
	public :
		void upload () override
		{
			cout<<"Uploading Electronic product.....\n";	
		}
};

class Clothing : public Product{
	public :
		void upload () override
		{
			cout<<"Uploading Clothing product.....\n";	
		}
};

int main(){
	Electronics prdct1;
	prdct1.upload();
	Clothing prdct2;
	prdct2.upload();
	return 0;
}
