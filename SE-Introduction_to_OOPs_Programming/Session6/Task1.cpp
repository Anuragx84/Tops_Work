/*1.Create a class called Song in your preferred OOP language with private properties title and artist. 
Add public getter and setter methods to access and modify these properties, then create an object and update its title.*/
#include<iostream>
using namespace std;

class Song{
	
	string tittle;
	string artist;
	
	public :
	
	string gettittle(){
		return tittle;
	}
	
	string getartist(){
		return artist;
	}	
	
	void set(string tittle,string artist){
		this->tittle = tittle;
		this->artist = artist;
	}
};

int main(){
	Song s1;
	s1.set("Ashqui","Arijit");
	cout<<"Tittle : "<<s1.gettittle()<<endl<<"Artist : "<<s1.getartist();
	return 0;
}
