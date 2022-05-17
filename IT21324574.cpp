// OOC project
// Topic    : online auction system
// Group no : MLB_WE_01.01_12
// Written by Sachinie Dissanayake/IT21324574



#include <iostream>

using namespace std;

// Report Class
class Report {
    private:
        int reportId;
        string description;
        string dateCreated;
        string timeCreated;
        string lastModified;
    
    public:
        Report();
        void addDetails();
        void viewReports();
        void createSummary();
        void listOfRestockItems();
        void listOfPreviousItems();
        ~Report();
};

//Latest Auction Report Class (Child Class to the Report Class)
class latestAuction_report : public Report {
    private:
        int latestId;
        
    public:
        latestAuction_report();
        ~latestAuction_report();
};

//Featured Auction Report Class (Child Class to the Report Class)
class featuedAuction_report : public Report {
    private:
        int featuedId;
        
    public:
        featuedAuction_report();
        ~featuedAuction_report();
};

//Closed Auction Report Class (Child Class to the Report Class)
class closedAuction_report : public Report {
    private:
        int closedId;
        
    public:
        closedAuction_report();
        ~closedAuction_report();
};

//Upcomming Auction Report Class (Child Class to the Report Class)
class upcommingAuction_report : public Report {
    private:
        int upcommingId;
        
    public:
        upcommingAuction_report();
        ~upcommingAuction_report();
};

//Closing Auction Report Class (Child Class to the Report Class)
class closingAuction_report : public Report {
    private:
        int closingId;
        
    public:
        closingAuction_report();
        ~closingAuction_report();
};

//Product Class
class Product {
	private:
		string name;
		int productId;
		string category;
		string description;
		float shippingWeight;
		float maxPrice;
		bool updateStatus;
		bool removeStatus;
		
	public:
		Product();
		void addNewProduct(string nameNew, int productIdNew, string categoryNew, string descriptionNew, float shippingWeightNew, float maxPriceNew);
		void restockProduct(string nameRestock, int productIdRestock, string categoryRestock, string descriptionRestock, float shippingWeightRestock, float maxPriceRestock);
		void updateProduct(string nameUpdate, int productIdUpdate, string categoryUpdate, string descriptionUpdate, float shippingWeightUpdate, float maxPriceUpdate);
		void removeProduct();
		void displayProduct();
		~Product();
		
};

//Order Class
class Order {
	private:
		int orderId;
		string orderDate;
		string orderTime;
		
	public:
		Order();
		void createOrder();
		void editOrder();
		~Order();
		
};

//OrderDetails Class
class OrderDetails {
	private:
		int numOfOrders;
		int taxStatus;
		
	public:
		OrderDetails();
		void calAmount();
		void calWeight();
		void calTax();
		~OrderDetails();
		
};

// Methods for OrderDetails Class
OrderDetails::OrderDetails() {
    numOfOrders = 0;
    taxStatus = 0;
}

void OrderDetails::calAmount() {
    
}

void OrderDetails::calWeight() {
    
}

void OrderDetails::calTax() {
    
}

OrderDetails::~OrderDetails() {
	cout << "OrderDetails Destructor runs" << endl;
}

// Methods for Order Class
Order::Order() {
    orderId = 0;
    orderDate = "2022/01/01";
    orderTime = "00:00:00";
}

void Order::createOrder() {
    
}

void Order::editOrder() {
    
}

Order::~Order() {
	cout << "Order Destructor runs" << endl;
}

// Methods for Report Class
Report::Report() {
    reportId = 0;
    description = "No Description";
    dateCreated = "2022/01/01";
    timeCreated = "00:00:00";
    lastModified = "00:00:00";
}

void Report::addDetails() {
    
}

void Report::viewReports() {
    
}

void Report::createSummary() {
    
}

void Report::listOfRestockItems() {
    
}

void Report::listOfPreviousItems() {
    
}

Report::~Report() {
	cout << "Report Destructor runs" << endl;
}

// Methods for CLatest Auction Report Class
latestAuction_report::latestAuction_report() {
    latestId = 0;
}

latestAuction_report::~latestAuction_report() {
	cout << "Latest Auction Report Destructor runs" << endl;
}

// Methods for Featured Auction Report Class
featuedAuction_report::featuedAuction_report() {
    featuedId = 0;
}

featuedAuction_report::~featuedAuction_report() {
	cout << "Featured Auction Report Destructor runs" << endl;
}

// Methods for Closed Auction Report Class
closedAuction_report::closedAuction_report() {
    closedId = 0;
}

closedAuction_report::~closedAuction_report() {
	cout << "Closed Auction Report Destructor runs" << endl;
}

// Methods for Upcomming Auction Report Class
upcommingAuction_report::upcommingAuction_report() {
    upcommingId = 0;
}

upcommingAuction_report::~upcommingAuction_report() {
	cout << "Upcomming Auction Report Destructor runs" << endl;
}

// Methods for Closing Auction Report Class
closingAuction_report::closingAuction_report() {
    closingId = 0;
}

closingAuction_report::~closingAuction_report() {
	cout << "Closing Auction Report Destructor runs" << endl;
}

// Methods for Product Class
Product::Product() {
	name = "No Name";
	productId = 0;
	category = "No Category";
	description = "No Description";
	shippingWeight = 0.00;
	maxPrice = 0.00;
	updateStatus = false;
	removeStatus = false;
}

void Product::addNewProduct(string nameNew, int productIdNew, string categoryNew, string descriptionNew, float shippingWeightNew, float maxPriceNew) {
	name = nameNew;
	productId = productIdNew;
	category = categoryNew;
	description = descriptionNew;
	shippingWeight = shippingWeightNew;
	maxPrice = maxPriceNew;
}

void Product::updateProduct(string nameUpdate, int productIdUpdate, string categoryUpdate, string descriptionUpdate, float shippingWeightUpdate, float maxPriceUpdate) {
	name = nameUpdate;
	productId = productIdUpdate;
	category = categoryUpdate;
	description = descriptionUpdate;
	shippingWeight = shippingWeightUpdate;
	maxPrice = maxPriceUpdate;
	updateStatus = true;
}

void Product::removeProduct() {
	name = "No Name";
	productId = 0;
	category = "No Category";
	description = "No Description";
	shippingWeight = 0.00;
	maxPrice = 0.00;
	updateStatus = false;
	removeStatus = true;
}

void Product::restockProduct(string nameRestock, int productIdRestock, string categoryRestock, string descriptionRestock, float shippingWeightRestock, float maxPriceRestock) {
	name = nameRestock;
	productId = productIdRestock;
	category = categoryRestock;
	description = descriptionRestock;
	shippingWeight = shippingWeightRestock;
	maxPrice = maxPriceRestock;
	updateStatus = false;
	removeStatus = false;
}

void Product::displayProduct() {
	cout << "............................" << endl;
	cout << "Product " << productId << endl;
	if(updateStatus) {
		cout << "*** Product Updated ***" << endl;	
	} else if(removeStatus) {
		cout << "*** Product Removed ***" << endl;	
	}
	cout << "Product Name : " << name << endl;
	cout << "Product Category : " << category << endl;
	cout << "Product Description : " << description << endl;
	cout << "Product Shipping Weight : " << shippingWeight << endl;
	cout << "Product Max Price : " << maxPrice << endl;
	cout << "............................" << endl;
	cout <<  endl;
	cout <<  endl;
}

Product::~Product() {
	cout << "Order Destructor runs" << endl;
}

int main()
{
    Product p1, p2, p3;
    
    p1.addNewProduct("Samsung Note 9", 10, "Mobile Phone", "128GB Storage, Blue Color", 125.25, 105000.50);
    p2.addNewProduct("Apple I Phone 13 Pro", 11, "Mobile Phone", "512GB Storage, Gold Color", 175.25, 360000.50);
    p3.addNewProduct("Xperia XA 1", 12, "Mobile Phone", "64GB Storage, Gray Color", 135.25, 85500.50);
    
    p2.updateProduct("Apple I Phone 13 Pro", 11, "Mobile Phone", "512GB Storage, Gold Color", 175.25, 451200.50);
    
    p3.removeProduct();
    
    p3.restockProduct("Xperia XA 1", 12, "Mobile Phone", "64GB Storage, Brown Color", 135.25, 93000.50);
    
    p1.displayProduct();
    p2.displayProduct();
    p3.displayProduct();

    return 0;
}


