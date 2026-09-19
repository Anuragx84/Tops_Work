/*1.Create a class called Playlist with properties: name (string), createdOn (date), 
and isPublic (boolean). Instantiate an object of Playlist and print all its properties.*/

/*2. Add a member function to your Playlist class named togglePublic() 
that switches isPublic between true and false each time it is called. 
Demonstrate by toggling the value twice and printing the result each time.*/

/*4.Extend your Playlist class to include a member function addSong(songTitle) 
that adds the song title to an array property called songs. 
Demonstrate by adding three song titles and displaying the updated songs list.
Hint: Initialize songs as an empty array inside the constructor.*/


#include<iostream>
using namespace std;

class Playlist{
	public :
		string name;
		string createdOn;
		bool isPublic = false;
		string songs[10];	
		int idx = 0;
	//task2	
	void togglePublic(){
		isPublic = !isPublic;
	}
	
	//task3
	void addSong(string songTittle){
		songs[idx] = songTittle;
		idx++;
	}
};

int main(){
	Playlist p;
	p.name = "its a playlist";
	p.createdOn = "19-09-2026";
	p.togglePublic();
	cout<<p.name<<", Created on : "<<p.createdOn<<", isPublic : "<<p.isPublic<<endl;
	p.togglePublic();
	cout<<p.name<<", Created on : "<<p.createdOn<<", isPublic : "<<p.isPublic<<endl;
	p.addSong("Believer");
    p.addSong("Perfect");
    p.addSong("Faded");
    for(int i=0;i<p.idx;i++){
    	cout<< i+1 <<". "<<p.songs[i]<<endl;
	}
	return 0;
}
