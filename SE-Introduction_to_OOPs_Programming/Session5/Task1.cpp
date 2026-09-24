/*1.Create a Java class called PaymentProcessor with two overloaded methods processPayment(): 
one that takes only an amount, and one that takes amount and a coupon code. 
Print which version is called and the final amount in each case.*/

#include<iostream>
using namespace std;

class PaymentProcessor{
	public :
	void processPayment(int amount){
		cout<<"Function with amount \nAmount : "<<amount<<endl;
	}
	void processPayment(int amount,string couponCode){
		cout<<"Function with amount & Coupon Code\nAmount : "<<amount<<"\nCoupon Code : "<<couponCode<<endl;
	}
};

int main(){
	PaymentProcessor payment;
	payment.processPayment(5000);
	payment.processPayment(5000,"AXHJKKS");
	return 0;
}
