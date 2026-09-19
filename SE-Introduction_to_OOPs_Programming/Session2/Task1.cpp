/*1.Create a class called Playlist with properties: name (string), createdOn (date), 
and isPublic (boolean). Instantiate an object of Playlist and print all its properties.*/

#include<iostream>
using namespace std;

class Playlist{
	public :
		string name;
		string createdOn;
		bool isPublic;	
};

int main(){
	Playlist p;
	p.name = "its a playlist";
	p.createdOn = "19-09-2026";
	p.isPublic = true;
	cout<<p.name<<", Created on : "<<p.createdOn<<", isPublic : "<<p.isPublic;
	return 0;
}
