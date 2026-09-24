/*4.Given this code: class MusicPlayer { void play(String song) { System.out.println("Playing: " + song); } } 
class SpotifyPlayer extends MusicPlayer { void play(String song) { System.out.println("Streaming on Spotify: " + song); } } — 
Create an object of type MusicPlayer but assign it a SpotifyPlayer instance, then call play(). Explain the output. 
Hint: This tests runtime polymorphism (overriding) and dynamic method dispatch.*/

#include<iostream>
using namespace std;

class MusicPlayer{
	public :
	virtual void play(string song){
	 	cout<<"Playing: "<<song<<endl;
	}
};
 
class SpotifyPlayer : public MusicPlayer {
	public :
	void play(string song) override
	{
		cout<<"Streaming on Spotify: "<<song<<endl;
	}
};

int main(){
	MusicPlayer* m = new SpotifyPlayer();
	m->play("Ashqui");
	return 0;
}
