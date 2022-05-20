//OOC Project 
//Topic		  : Online Action System
//Group no	: MLB_WE_01.01_12
//Written by Pathiraja Y.P.M.A/IT21327544
//Payment,Shipment,Order

#include <iostream>
#include <string.h>
#define SIZE 2;
using namespace std;
//Functions in the prgramm
class Payment;
class Shipment;
class Oder;

//class Payment
class Payment {
	protected :
		int paymentId;
		string paymentDate;
		string paymentTime;
		float paymentAmount;
		string paymentDetails;
	
	public:
		Payment();
		Payment(int id,string Date,string Time,float Amount ,string Details);
		void viewPaymnetDetails();
		void updatePaymnetDetails();
		void status();
};
Payment::Payment(){
	cout <<"Payment class"<< endl;
}

 Payment::Payment(int id,string Date,string Time,float Amount ,string Details){
 		paymentId=id;
		paymentDate=Date;
		paymentTime=Time;
		paymentAmount=Amount;
		paymentDetails=Details;
 }
 	void Payment::viewPaymnetDetails() {}
	void Payment::updatePaymnetDetails() {}
	void Payment::status() {}
	
	
	
class Credit : public Payment{
	private:
		int cardNO;
		int expirDate;

	public:
		Credit();//Default constructor
		Credit(int id,string Date,string Time,float Amount ,string Details, int C_NO,	int ExDate);
};

	Credit::Credit(){
		cout <<"Credit class"<< endl;
	}
	Credit::Credit(int id,string Date,string Time,float Amount ,string Details, int C_NO,	int ExDate) : Payment(id,Date,Time,Amount,Details){
		paymentId=id;
		paymentDate=Date;
		paymentTime=Time;
		paymentAmount=Amount;
		paymentDetails=Details;
		cardNO=C_NO;
		expirDate=ExDate;
	}







class Paypal : public Payment{
	private:
		string paypalEmail;
	 
	public:
		Paypal();//Default constructor
		Paypal(int id,string Date,string Time,float Amount,string Details,string Email);
};

	Paypal::Paypal(){
		cout <<"Paypal class"<< endl;
	}
	Paypal::Paypal(int id,string Date,string Time,float Amount ,string Details,string Email) : Payment(id,Date,Time,Amount,Details){
		paymentId=id;
		paymentDate=Date;
		paymentTime=Time;
		paymentAmount=Amount;
		paymentDetails=Details;
		paypalEmail=Email; 
	}




class Payoneer : public Payment{
	private:
		string PayoneerEmail;
	 
	public:
		Payoneer();//Default constructor
		Payoneer(int id,string Date,string Time,float Amount,string Details,string Email);
};

	Payoneer::Payoneer(){
		cout <<"Paypal class"<< endl;
	}
	Payoneer::Payoneer(int id,string Date,string Time,float Amount ,string Details,string Email) : Payment(id,Date,Time,Amount,Details){
		paymentId=id;
		paymentDate=Date;
		paymentTime=Time;
		paymentAmount=Amount;
		paymentDetails=Details;
		PayoneerEmail=Email; 
	}

//class Shipment
class Shipment {
private:
    int shipmentID;
    string shipment;
    Order* order;
public:
    Shipment();//Default constructor
    void storeDetails(int shipmentID, string shipment);
    void viewShipmentDetails();
    void validateDetails();
    void calcDistance();
    void calcShipmentPrice();
};

Shipment::Shipment() {
    shipmentID = 0;
    shipment = "";
    cout << "Shipment class begins" << endl;
}
void Shipment::storeDetails(int ShipmentID,string Shipment) {
    shipmentID = ShipmentID;
    shipment = Shipment;
}
void Shipment::viewShipmentDetails() {
    cout << "ShipmentID : " << shipmentID << endl
        << "Shipment : " << shipment << endl;
}
void Shipment::validateDetails() {

}
void Shipment::calcDistance() {

}
void Shipment::calcShipmentPrice() {

}

//Order Class
class Order{
private:
    int orderID;
    int orderDate;
    int orderTime;
     Payment* payment;
     Shipment *ship;
public:
    Order(); //Default Constuctor
    Order(int OrderID, int OrderDate, int orderTime); //Overloading contructor
    ~Order();  //destructor
    void createOrder(Payment* payment1);
    void editOrder(int orderID);
};
Order::Order()
{
    orderID = 0;
    orderDate = 0;
    orderTime = 0;
   
}
Order::Order(int OrderID, int OrderDate, int orderTime) {
    orderID = OrderID;
    orderDate = OrderDate;
    orderTime = orderTime;
   

}
Order::~Order() {
    cout << "Deleting Order " << orderID << endl;
        s
}
void Order::createOrder(Payment* payment1) {
    payment=payment1;
}
void Order::editOrder(int orderID) {

}
int main()
{
  Payment    p1;
  Shipment   s1;
  Oder       o1;
}
