/*1.Create a text file called my_fav_songs.txt and write the names of your 5 favorite songs into it using ofstream.*/

/*2.Read all song names from my_fav_songs.txt using ifstream and display each song on a new line in the console.*/

/*3.Modify your code to append a new song name entered by the user to my_fav_songs.txt without overwriting the existing list.
Hint: Open the file in append mode using ofstream.*/

/*4.Build a Flipkart-style wishlist tracker: ask the user to enter 3 product names and prices, 
save them to a file called wishlist.txt, then read the file and display each product with its price.*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	//Task1
	ofstream File("my_fav_songs.txt");
	File<<"Tum Hi Ho"<<endl;
	File<<"Kesariya"<<endl;
	File<<"Apna Bana Le"<<endl;
	File<<"Channa Mereya"<<endl;
	File<<"Agar Tum Saath Ho"<<endl;
	cout<<"Data Added Successfully.....\n";
	File.close();
	
	//Task2
	ifstream File1("my_fav_songs.txt");
	string line;
	getline(File1,line);
	cout<<line<<endl;
	getline(File1,line);
	cout<<line<<endl;
	getline(File1,line);
	cout<<line<<endl;
	getline(File1,line);
	cout<<line<<endl;
	getline(File1,line);
	cout<<line<<endl;
	File1.close();
	
	//Task3
	ofstream file2("my_fav_songs.txt",ios::app);
	cout<<"Enter song name : ";
	string inpt;
	getline(cin,inpt);
	file2<<inpt<<endl;
	cout<<"Data Updated Successfully.....\n";
	file2.close();
	return 0;
}
