/*3.Create a class called FoodOrder with properties: orderId (number), restaurantName (string), 
and isDelivered (boolean). Write a member function markDelivered() that sets isDelivered 
to true and prints a message. Instantiate FoodOrder and call markDelivered().*/

/*5.Refactor your FoodOrder class so that the constructor takes an object as a 
parameter (with keys orderId, restaurantName, isDelivered) instead of separate arguments. 
Update your instantiation code to use this new constructor signature.*/

#include<iostream>
using namespace std;

class FoodOrder{
	public :
		int orderId;
		string restaurantName;
		bool isDelivered;
		
	FoodOrder(int orderId,string restaurantName,bool isDelivered){
		this->orderId = orderId;
		this->restaurantName = restaurantName;
		this->isDelivered = isDelivered;
	}
	
	void markDelivered(){
		isDelivered = true;
		cout<<"Delivered successfully\n";
	}
};

int main(){
//	order.orderId = 523;
//	order.restaurantName = "Patel restaurant";
//	order.markDelivered();
	FoodOrder order(523,"Patel restaurant",true);
	cout<< order.orderId << "\t" << order.restaurantName <<"\t"<< order.isDelivered<<endl;
	order.markDelivered();
	return 0;
}
