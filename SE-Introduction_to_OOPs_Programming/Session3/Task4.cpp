/*4.Simulate a BookMyShow ticket booking by creating a Ticket class that prints 'Saving your ticket...' in its destructor. 
Create and delete a Ticket object to demonstrate the destructor lifecycle.
Hint: Use the __del__ method (Python) or ~Ticket() (C++) to define the destructor.*/

#include<iostream>
using namespace std;

class Ticket{
	public :
		
	Ticket(){
		cout << "Ticket booked successfully!" << endl;
	}
	
	~Ticket(){
		cout << "Saving your ticket..." << endl;
	}
};

int main(){
	Ticket ticket;
    cout << "Ticket is being used..." << endl;
    cout << "Ticket object deleted." << endl;
	return 0;
}
