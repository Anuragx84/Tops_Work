/*5.Given a file called insta_followers.txt containing Instagram usernames (one per line), 
write a program to count and display the total number of followers listed in the file.
Constraint: Do not use any array or vector to store the names—just count as you read.*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream rfoll("insta_followers.txt");
	string name;
	int count = 0;
	while(getline(rfoll,name)){
		cout<<name<<endl;
		count++;
	}
	cout<<"Total number of follwers : "<<count<<endl;
	rfoll.close();
	return 0;
}
