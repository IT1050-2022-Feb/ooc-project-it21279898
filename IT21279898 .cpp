// OOC Project 
//Topic		: Online Action System
// Group no	: MLB_WE_01.01_12
// Written  by Githma Kulasekara /IT21279898


// User, Registered_Auctioneer, Unregistered_Auctioneer ,Unregistered_Bidder,Registered_Bidder,Product , Cart Classes
 
// use of overloaded Constructors
// The default constructor has sample values set once

#include <iostream>
using namespace std;
#define SIZE 2
 

class User{          //   User class (parent class )
protected:         
  string name;        
  string address;
  string email;
public:
  User();        //default constructor
  User(string NA,string Add,string EM);  //  overloaded Constructors
  void search() {}
  void dislayDeatils();  
   
};
 User::User(){
   cout <<endl<< "User Class " << endl;
 }
   
 User::User(string NA,string Add,string EM){
    name=NA;
    address=Add;
    email=EM;
  }
 

class Registered_Auctioneer : public User{      //   Registered_Auctioneer class(Child Class)
private:
  int registrationNo;
  int auctioneerID;
  int dateOfBirth ;  
  int contactNo;
  string gender;
public: 
  Registered_Auctioneer(); //default constructor
  Registered_Auctioneer(string NA,string Add,string EM,int RNo,int AID, int ADOB,int ACNo,string Gen)  ;//overloaded Constructors
  void auctioneerDetails();
  void addProduct();
  void setStartTime();
  void setEndTime();
  float setMinimumBid();
  void displayProducts();
  int contactBuyer();
   
};

 Registered_Auctioneer::Registered_Auctioneer(){
   cout << "Registered_Auctioneer Class " << endl;
 }

Registered_Auctioneer::Registered_Auctioneer(string NA,string Add,string EM,int RNo,int AID,int ADOB,int ACNo,string Gen) : User(NA , Add , EM){
    name=NA;
    address=Add;
    email=EM;
    registrationNo=RNo;
    auctioneerID=AID;
    dateOfBirth= ADOB;  
    contactNo=ACNo;
    gender=Gen;
  }
void Registered_Auctioneer::auctioneerDetails(){
  cout <<endl<<"Name : "<<name<<endl;
    cout <<"Address : "<<address<<endl;
    cout <<"E-mail : "<<email<<endl;
  cout <<"Registration No : "<<registrationNo<<endl;
  cout <<"Auctioneer ID : "<<auctioneerID<<endl;
  cout <<"Date Of Birth: "<<dateOfBirth<<endl;
  cout <<"Contact No : "<< contactNo<<endl;
  cout <<"Gender : "<< gender<<endl;
  
}
class Unregistered_Auctioneer : public User{  //   Unregistered_Auctioneer class(Child Class)
public:
  Unregistered_Auctioneer(); //default constructor
  void viewDetails();
};

Unregistered_Auctioneer::Unregistered_Auctioneer(){
   cout << " Unregistered_Auctioneer Class " << endl;
 }

class Unregistered_Bidder : public User{ //   Unregistered_Bidder class(Child Class)
public:
  Unregistered_Bidder();      //default constructor
  void viewDetails();
};

 Unregistered_Bidder::Unregistered_Bidder(){
   cout << " Unregistered_Bidder Class " << endl;
 }
class Registered_Auctioneer;
class Cart;
class Product;

class Registered_Bidder : public User{ //   Registered_Bidder class(Child Class)
private:
  Cart *Carts;  //an object of Cart as attribute
  Product *Products;  //an object of Product as attribute
  int B_registrationNo;
  int bidderID;
  int B_dateOfBirth ;  
  int B_contactNo;
  string B_gender;
  
public: 
  Registered_Bidder();  //default constructor
  Registered_Bidder(string NA,string Add,string EM,int RNo,int BID,int DOB,int CNo,string Gen );//overloaded Constructors
  void bidderDetails() ;
  void selectProduct(Product *Pd);
  void addToCart(Cart *c);
  void checkBid();
  float addBid() ;
 
};


 Registered_Bidder::Registered_Bidder(){
   cout << "Registered_Bidder Class " << endl;
 }

Registered_Bidder::Registered_Bidder(string NA,string Add,string EM,int RNo,int BID,int DOB,int CNo,string Gen): User(NA , Add , EM){
    name=NA;
    address=Add;
    email=EM;
    B_registrationNo=RNo;
    bidderID=BID;
    B_dateOfBirth= DOB;  
    B_contactNo=CNo;
    B_gender=Gen;
  }

void Registered_Bidder::bidderDetails() {
  cout <<endl<<"Name : "<<name<<endl;
    cout <<"Address : "<<address<<endl;
    cout <<"E-mail : "<<email<<endl;
  cout <<"Registration No : "<<B_registrationNo<<endl;
  cout <<"bidderID ID : "<<bidderID<<endl;
  cout <<"Date Of Birth: "<<B_dateOfBirth<<endl;
  cout <<"Contact No : "<<B_contactNo<<endl;
  cout <<"Gender : "<< B_gender<<endl;
  
}

void Registered_Bidder::selectProduct(Product *Pd){
    Products=Pd;
}

void Registered_Bidder::addToCart(Cart *c){
  Carts=c;
}


class Cart{       //   Cart class  
private:
  int cartID;
  int noOfProducts;
  float price;
  Registered_Bidder *RB;
public:
  Cart();   //default constructor
  Cart(int ID,int Products,float amount,Registered_Bidder *RBider );//overloaded Constructors
  float calcTotalPrice();
};


 Cart::Cart(){
   cout << endl<< "Cart Class " << endl;
 }

Cart::Cart(int ID,int Products,float amount,Registered_Bidder *RBider){
  cartID=ID;
  noOfProducts=Products;  
  price=amount;
  RB=RBider;
  RB->addToCart(this);
}

class Product{      //   ProductCart class  
private:
  string name;
  int productID ;
  string category;
  string description;
  float shippingWeight;
  float maxPrice;
  Registered_Bidder *RB;    //an object of Registered_Bidder as attribute

public:
  Product();       //default constructor
  Product(string Na,int PID,string Cap,string Des,float shipWeigh,float MAXPrice,Registered_Bidder *RBider );//overloaded Constructors
  void displayProducts( );
  void addNewProducts();
  void removeProducts();
  void restockProducts();
  void updateProducts();
  
};



  Product::Product(string Na,int PID,string Cap,string Des,float shipWeigh,float MAXPrice,Registered_Bidder *RBider ){
    name=Na;
    productID=PID ;
    category=Cap;
    description=Des;
    shippingWeight=shipWeigh;
    maxPrice=MAXPrice;
    RB=RBider;
    RB->selectProduct( this);
    }

void Product::displayProducts() {
  cout <<"Name : "<<name<<endl;
  cout <<"Product ID : "<<productID<<endl;
  cout <<"Description: "<<description<<endl;
  cout <<"Shipping Weight : "<<shippingWeight<<endl;
  cout <<"Max Price : "<<maxPrice  <<endl;
  cout <<"Bid amount : "<<RB  <<endl;
  
}
 Product::Product(){
   cout<< endl << "Product Class " << endl;
 }


int main(void) {

  
   User();
   User u1("Githma","Homagama","githam@gmail.com");        // create  Static Objects
   

  Registered_Auctioneer();
  Registered_Auctioneer A1("Githma","Homagama","githam@gmail.com",001,200,2001,07664 ,"Male");  // create  Static Objects
  A1.auctioneerDetails();


    User u2("Sujith","Colombo","Sujith@gmail.com");
     
  
   Registered_Bidder();
  Registered_Bidder B1("Sujith","Colombo","Sujith@gmail.com", 1000,500,2000,075023,"Male" );  // create  Static Objects
  B1.bidderDetails();

  Unregistered_Auctioneer();
  Unregistered_Bidder();
  
Registered_Bidder *B2=new Registered_Bidder("Sujith","Colombo","Sujith@gmail.com", 1000,500,2000,075023,"Male" ); //create Dynamic Objects 
  
Cart *c1=new Cart (300,2,1000.00,B2);  //create Dynamic Objects 
Product *P1 = new Product("phone",900,"Electrical","good",200,20000.00,B2);  //create Dynamic Objects 
  

  Cart();
  P1->displayProducts();
  Product();
  
return 0 ; 
}



