/*Create a Task class in your favorite OOP language (Java, Python, or C++) with properties: title and isDone. 
Add a method markDone() that sets isDone to true, and a method display() that prints the task with its status.*/

#include<iostream>
#include <string>
using namespace std;

class Task{
	public:
		string title;
		bool isDone=false;
		
	void markDone(){
		isDone = true;
	}
	a
	void display(){
		cout<<title<<" : ";
		if(isDone)
			cout<<"its Done"<<endl;
		else
			cout<<"its not Done"<<endl;
	}
};

int main(){
	string check;
	Task t1;
	cout<<"Enter title of task : ";
	getline(cin,t1.title);
	cout<<"is it Done ?(yes/no) : ";
	cin>>check;
	if(check=="yes"){
		t1.markDone();
	}
	cout<<"check"<<check<<"t1.markdon()"<<t1.isDone;
	t1.display();
	return 0;
}
