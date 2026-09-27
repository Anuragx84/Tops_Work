/*4.Build a Flipkart-style wishlist tracker: ask the user to enter 3 product names and prices, 
save them to a file called wishlist.txt, then read the file and display each product with its price.*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream file1("wishlist.txt");
	string inpt;
	cout<<"Enter product : ";
	cin>>inpt;
	file1<<"Product : "<<inpt;
	cout<<"Enter price of "<<inpt<<": ";
	cin>>inpt;
	file1<<" | Price : "<<inpt<<endl;
	cout<<"Enter product : ";
	cin>>inpt;
	file1<<"Product : "<<inpt;
	cout<<"Enter price of "<<inpt<<": ";
	cin>>inpt;
	file1<<" | Price : "<<inpt<<endl;
	cout<<"Enter product : ";
	cin>>inpt;
	file1<<"Product : "<<inpt;
	cout<<"Enter price of "<<inpt<<": ";
	cin>>inpt;
	file1<<" | Price : "<<inpt<<endl;
	file1.close();
	
	ifstream read("wishlist.txt");
	while(getline(read,inpt)){
		cout<<inpt;
	}
	read.close();
	return 0;
}
