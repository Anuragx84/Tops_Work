/*3.Create a class Movie with a parameterized constructor and then use a copy constructor 
to duplicate a Movie object. Print both the original and copied movie details to show they are identical.*/

#include<iostream>
using namespace std;

class Movie{
	public :
		string moviename;
		string actor;
		int minDuration;
	Movie(string moviename,string actor,int minDuration){
		this->moviename = moviename;
		this->actor = actor;
		this->minDuration = minDuration;
	}
	
	void movieDetails(){
		cout<<"Movie Name : "<<moviename<<", Actor : "<<actor<<", Duration : "<<minDuration<<"minutes"<<endl;
	}
};

int main(){
	Movie m1("3 Idiots", "Aamir Khan", 170);
	Movie m2 = m1;
	cout<<"original Movie : \n";
	m1.movieDetails();
    cout << "Copied Movie:" << endl;
    m2.movieDetails();
	return 0;
}
