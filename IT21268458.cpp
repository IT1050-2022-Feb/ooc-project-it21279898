//OOC Project 
//Topic		  : Online Action System
//Group no	: MLB_WE_01.01_12
//Written by Dissanayaka A.V.R./IT21268458
//Registered Auctioneer, Unregistered Auctioneer, Order, Order Details


#include <iostream>
#include <string.h>
#define SIZE 2;
using namespace std;
//Functions in the prgramm
class Product;
class User;
class Unregistered_Auctioneer;
class Registered_Auctioneer;
class Order_Details;
class Order;


//Product Class
class Product {
private:
    string name;
    int productID;
    string category;
    string description;
    float shippingWeight;
    float maxPrice;

    Registered_Auctioneer* auctioneer;
    Unregistered_Auctioneer* unregauctioneer;
public:
    Product();  //default constructor
    void addNewProducts(string Name, int ProductID, string Category, string Description, float ShippingWeight, float MaxPrice, Registered_Auctioneer* Auctioneer, Unregistered_Auctioneer* Unregauctioneer);
    void removeProducts();
    void restockProducts();
    void updateProducts();
    ~Product();  //destructor
};
Product::Product() {
    name = "";
    productID = 0;
    category = "";
    description = "";
    shippingWeight = 0;
    maxPrice = 0;
    auctioneer = 0;
    unregauctioneer = 0;
    cout << "Product Class" << endl;
};

Product::~Product() {
    cout << "Product " << productID << "is deleted" << endl;
};
void Product::addNewProducts(string Name, int ProductID, string Category, string Description, float ShippingWeight, float MaxPrice, Registered_Auctioneer* Auctioneer, Unregistered_Auctioneer* Unregauctioneer) {
    name = Name;
    productID = ProductID;
    category = Category;
    description = Description;
    shippingWeight = ShippingWeight;
    maxPrice = MaxPrice;
    auctioneer = Auctioneer;
    unregauctioneer = Unregauctioneer;
};
void Product::removeProducts() {

};
void Product::restockProducts() {

};
void Product::updateProducts() {

}


//Parent class(User class) begins
class User {
protected:
    string name;
    string address;
    string email;
public:
    User();  //default constructor
    User(string Name, string Address, string Email);  //overloading constructor
    ~User(); //destructor
    void search();
    void displayDetails();
};
User::User() {
    name = "";
    address = "";
    email = "";
    cout << "User Class" << endl;
}
User::User(string Name, string Address, string Email) {
    name = Name;
    address = Address;
    email = Email;
}
User::~User() {
    cout << "User" << name << "is deleted" << endl;
};
void User::search() {

}
void User::displayDetails() {
    cout << "Name : " << name << endl
        << "Address : " << address << endl
        << "Email : " << email << endl;
}

//UnregisteredAuctioneer

class Unregistered_Auctioneer : public User {
private:
    Product* product;
public:
    void viewDetails();
};
void Unregistered_Auctioneer::viewDetails(){
    displayDetails();
}


//Registered Auctioneer class
class Registered_Auctioneer : public User {
private:
    int registrationNo;
    int auctioneerID;
    string dateOfBirth;
    int contactNo;
    string gender;
    Product* product;
public:
    Registered_Auctioneer(); //default constructor
    ~Registered_Auctioneer();//destructor
    void auctioneerDetails(int registrationNo, int auctioneerID, string dateOfBirth, int contactNo, string gender);
    void addProducts();
    void addStartTime();
    void addEndTime();
    void addMinimumBid();
    void displayProducts();
    void contactBuyer();
};

Registered_Auctioneer::Registered_Auctioneer() {
    registrationNo = 0;
    auctioneerID = 0;
    dateOfBirth = "";
    contactNo = 0 ;
    gender = "";
    cout << "Registered Auctioneer Class" << endl;
};
Registered_Auctioneer::~Registered_Auctioneer() {
    cout << "Registered_Auctioneer " << name << "is deleted" << endl;
};
void Registered_Auctioneer::auctioneerDetails(int RegistrationNo, int AuctioneerID, string DateOfBirth, int ContactNo, string Gender) {
    registrationNo = RegistrationNo;
    auctioneerID = AuctioneerID;
    dateOfBirth = DateOfBirth;
    contactNo = ContactNo;
    gender = Gender;
};
void Registered_Auctioneer::addProducts() {

};
void Registered_Auctioneer::addStartTime() {

};
void Registered_Auctioneer::addEndTime() {
};
void Registered_Auctioneer::addMinimumBid() {

};
void Registered_Auctioneer::displayProducts() {

};
void Registered_Auctioneer::contactBuyer() {

};


//Order Details class
class Order_Details {
private:
    int noOfOrders;
    int taxStatus;

    Product* product;
public:
    Order_Details(); //default constructor
    Order_Details(int NoOfOrders, int taxStatus); //overloading constructor
    ~Order_Details(); //destructor
    void calAmount();
    void calWeight();
    void calTax();
};

Order_Details::Order_Details() {
    noOfOrders = 0;
    taxStatus = 0;
    product ->addNewProducts("", 0, "", "", 0, 0, 0, 0);
    cout << "Order Details Class" << endl;

}

Order_Details::Order_Details(int NoOfOrders, int TaxStatus) {
    noOfOrders = NoOfOrders;
    taxStatus = TaxStatus;
    product = 0;
};
Order_Details::~Order_Details() {
    cout << "Deleting Order Details" << endl;
};
void Order_Details::calAmount() {

}
void Order_Details::calWeight() {

}
void Order_Details::calTax() {

}


//Order Class
class Order {
private:
    int orderID;
    int orderDate;
    int orderTime;
    Order_Details* details;
    Product* product;
public:
    Order(); //Default Constuctor
    Order(int OrderID, int OrderDate, int orderTime, int NoOfOrder, int TaxStatus); //Overloading contructor
    ~Order();  //destructor
    void createOrder(Product* product1);
    void editOrder(int orderID);
};
Order::Order()
{
    orderID = 0;
    orderDate = 0;
    orderTime = 0;
    details = new Order_Details(0, 0);
    product = 0;
    cout << "Order Class" << endl;

}
Order::Order(int OrderID, int OrderDate, int OrderTime, int NoOfOrder, int TaxStatus) {
    orderID = OrderID;
    orderDate = OrderDate;
    orderTime = OrderTime;
    details = new Order_Details(NoOfOrder, TaxStatus);
    product = 0;
}
Order::~Order() {
    cout << "Deleting Order " << orderID << endl;
        delete details;
}
void Order::createOrder(Product* product1) {
    product = product1;
}
void Order::editOrder(int orderID) {

}


int main()
{
    User u1;
    Unregistered_Auctioneer unRegA1;
    Registered_Auctioneer regA1;
    Product p1;
    Order o1;
    Order_Details od1;
}

