/*4.Refactor the following code so that the user’s phone number in the UserProfile class 
is private and can only be set or retrieved using public methods.Hint: Add private access 
modifier to the phone number and create setPhoneNumber() and getPhoneNumber() methods.*/

#include<iostream>
using namespace std;

class UserProfile{
	private :
		string PhoneNo;
		
	public :
		void setPhone(string PhoneNo){
			this->PhoneNo = PhoneNo;
		}
		
		string getPhone(){
			return this->PhoneNo;
		}
};
int main(){
	UserProfile user1;
	user1.setPhone("8461792182");
	cout<<"User's Phone number : "<<user1.getPhone()<<endl;
	return 0;
}
