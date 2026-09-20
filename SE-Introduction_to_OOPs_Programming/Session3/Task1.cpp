/*1.Create a class called Playlist with a default constructor that sets the playlist 
name to 'My Favourites' and prints a welcome message when an object is created.*/

/*5.Modify your Playlist class so that it auto-saves the playlist name 
to a file called autosave.txt when the object is destroyed, simulating an 
auto-save feature like Spotify.Hint: Write the file-saving code inside the destructor.*/


#include<iostream>
#include<fstream>
using namespace std;

class Playlist{
	public : 
		string name;
		Playlist(){
			name = "My Favourites";
			cout<<"Hey Welcome to the playlist class you have created an object of this class\nThank you...\n";
		}
		
		~Playlist(){
			ofstream writeFile("autosave.txt");
			writeFile<<name;
		}
};

int main(){
	Playlist playlist1;
	return 0;
}
