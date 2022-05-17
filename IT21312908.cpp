// OOC Project 
//Topic		: Online Action System
// Group no	: MLB_WE_01.01_12
// Written  by Wasana Fernando/IT21312908


#include<iostream>
#include<cstring>
#include<string>
#define SIZE 2
using namespace std;

class User;
class UnregisteredAuctioneer;
class UnregisteredBidder;
class registeredAuctioneer;
class RegisteredBidder;
class Buyer;
class Payment;
class Order;
class Shipment;


class User
{
  protected :
    char name[30];
    char address[100];
    char email[50];

  public : 
    User();
    User(char *uname, char *uaddress, char *uemail);
    void search();
    void displayDetails();
};

User::User() {};

User::User(char *uname, char *uaddress, char *uemail)
{
  strcpy(name, uname);
  strcpy(address, uaddress);
  strcpy(email,uemail);
}

void User::search() {};
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

class UnregisteredAuctioneer : public User
{
    public :
      UnregisteredAuctioneer(char *uname, char *uaddress, char *uemail);
      void viewAdetails();
};

UnregisteredAuctioneer::UnregisteredAuctioneer(char *uname, char *uaddress, char *uemail) : User(uname, uaddress, uemail)
{};

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

class UnregisteredBidder : public User
{
    public :
      UnregisteredBidder(char *uname, char *uaddress, char *uemail);
      void viewAdetails();
};

UnregisteredBidder::UnregisteredBidder(char *uname, char *uaddress, char *uemail) : User(uname, uaddress, uemail)
{};

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

class registeredAuctioneer : public User
{
  protected : 
    int registerationAuNo;
    int auctioneerID;
    char dateOfBirth[10];
    int contactNo;
    char gender[10];

  public :
    registeredAuctioneer();
    registeredAuctioneer(char *uname, char *uaddress, char *uemail, int regNo, int aucID, char *dob, int conNo, char *gender);
    void auctioneerDetails();
    void addProducts();
    void addStartTime();
    void addEndTime();
    void addMinimumBid();
    void displayProducts();
    void contactBuyer();
};

registeredAuctioneer::registeredAuctioneer() {};

registeredAuctioneer::registeredAuctioneer(char *uname, char *uaddress, char *uemail, int regNo, int aucID, char *dob, int conNo, char *gen) : User(uname, uaddress, uemail)
{
  registerationAuNo = regNo;
  auctioneerID = aucID;
  strcpy(dateOfBirth, dob);
  contactNo = conNo;
  strcpy(gender, gen);
}

void registeredAuctioneer::auctioneerDetails() {};
void registeredAuctioneer::addProducts() {};
void registeredAuctioneer::addStartTime() {};
void registeredAuctioneer::addEndTime() {};
void registeredAuctioneer::addMinimumBid() {};
void registeredAuctioneer::displayProducts() {};
void registeredAuctioneer::contactBuyer() {};

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

class RegisteredBidder : public User
{
  protected :
    int registrationBiNo;
    int bidderID;
    char BdateOfBirth[10];
    int contactNum;
    char Bgender[10];

  public :
    RegisteredBidder();
    RegisteredBidder(char *uname, char *uaddress, char *uemail, int regBiNo, int bidID, char *b_dob, int conNum, char *Bgen);
    void bidderDetails();
    void selectProduct();
    void addToCart();
    void checkBid();
    void addBid();
};

RegisteredBidder::RegisteredBidder() {};

RegisteredBidder::RegisteredBidder(char *uname, char *uaddress, char *uemail, int regBiNo, int bidID, char *b_dob, int conNum, char *Bgen) : User(uname, uaddress, uemail)
{
  registrationBiNo = regBiNo;
  bidderID = bidID;
  strcpy(BdateOfBirth, b_dob);
  contactNum = conNum;
  strcpy(Bgender, Bgen);
}

void RegisteredBidder::bidderDetails() {};
void RegisteredBidder::selectProduct() {};
void RegisteredBidder::addToCart() {};
void RegisteredBidder::checkBid() {};
void RegisteredBidder::addBid() {};

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

class Buyer : public RegisteredBidder
{
  private:
    int tokenID;
    Payment *pay;
    Shipment *ship;
    Order *ord[SIZE];

  public :
    Buyer();
    Buyer(char *uname, char *uaddress, char *uemail, int regBiNo, int bidID, char *b_dob, int conNum, char *Bgen, int tokID);
    void addPayementDetails();
    void addShippingDetails();
    void contactAuctioneer();
    void returnProduct();
};

Buyer::Buyer() {};

Buyer::Buyer(char *uname, char *uaddress, char *uemail, int regBiNo, int bidID, char *b_dob, int conNum, char *Bgen, int tokID) : RegisteredBidder(uname, uaddress, uemail, regBiNo, bidID, b_dob, conNum, Bgen)
{
  tokenID = tokID;
}

void addPayementDetails() {};
void addShippingDetails() {};
void contactAuctioneer() {};
void returnProduct() {};

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

class Payment
{
  protected : 
    int paymentID;
    char paymentDate[10];
    char paymentTime[8];
    char paymentType[20];
    float paymentAmount;
    char paymentDetails[50];
    Buyer *byr;
    Order *ord;

  public :
    Payment();
    Payment(int pID, char *pDate, char *pTime, char *pType, float pAmount, char *pDetails, Buyer *Bbyr);
    void viewPaymentDetails();
    void updatePaymentDetails();
    void status();
};

Payment::Payment() {};

Payment::Payment(int pID, char *pDate, char *pTime, char *pType, float pAmount, char *pDetails, Buyer *Bbyr)
{
  paymentID = pID;
  strcpy(paymentDate, pDate);
  strcpy(paymentTime, pType);
  paymentAmount = pAmount;
  strcpy(paymentDetails,pDetails);
  byr =  Bbyr;
  byr->addPayementDetails();
}

void Payment::viewPaymentDetails() {};
void Payment::updatePaymentDetails() {};
void Payment::status() {};

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

int main()
{
  User *user;
  UnregisteredAuctioneer *UnregAuc;
  UnregisteredBidder *UnregBid;
  RegisteredBidder *regBid;
  registeredAuctioneer *regAuc;
  Buyer *buy;

  user = new User("Ann","Colombo","Ann@gmail.com");
  UnregAuc = new UnregisteredAuctioneer("pasindu","Negombo","pasindu@gmail.com");
  UnregBid = new UnregisteredBidder("kaushalya","Gampaha","Kaushalya@gmail.com");
  regBid = new RegisteredBidder("Ruwani","Jaffna","ruwani@gmail.com", 100,200,"1997-06-07",0777111111,"female");
  regBid = new RegisteredBidder("Braden","Kandy","braden@gmail.com", 101,201,"2000-11-15",0777111111,"male");
  regAuc = new registeredAuctioneer("Adam","Colombo","adam@gmail.com",300,400,"1999-01-04",0777222222,"male");
  buy = new Buyer("Ruwani","Jaffna","ruwani@gmail.com", 100,200,"1997-06-07",0777111111,"female",600);
  
}

