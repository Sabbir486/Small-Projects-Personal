#include<bits/stdc++.h>
using namespace std;

//Customized Data Structure
struct Product{
    int productId;
    string name;
    string category;
};

struct order{
    int orderId;
    int productId;
    int quantity;
    string cusId;
    time_t orderDate;
};


int main(){
    
    //vector ---> When using Customized Data Structure
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Mobile", "Electronics"},
        {103, "Tea Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk Lamp", "Home"},
    };

    //deque ---> One kind of Container(DS)
    deque<string> recentCus = {"C001", "C002", "C003"};
    recentCus.push_back("C004");
    recentCus.push_front("C005");

    //list ---> Order
    list<order> orderHistory; 
    orderHistory.push_back({1, 101, 5, "C001", time(0)});
    orderHistory.push_back({2, 103, 2, "C002", time(0)});
    orderHistory.push_back({3, 104, 3, "C003", time(0)});

    //set ---> Uniqueness(Category)
    set<string> categories;
    for(const auto &product : products){  //auto ---> Use it to deduce it's type
        categories.insert(product.category);
    }

    //map ---> key value payer (Sorted) --> Used Binary Search Tree
    map<int, int> productStock = {
        {101, 10},
        {102, 19},
        {103, 13},
        {104, 17},
        {105, 15},
    };

    //multimap
    multimap<string, order> customerOrder;
    for(const auto &order : orderHistory){
        customerOrder.insert({order.cusId, order});
    }

    //unordered map (Sorting/Not Sorting) --> Efficiency High (Hash Table)
    unordered_map<string, string> customerData = {
        {"C001", "Sabbir"},
        {"C002", "Rony"},
        {"C003", "Fahim"},
        {"C004", "Naimur"},
    };

    //unordered set
    unordered_set<int> uniqueProductId;
    for(const auto &product : products){
        uniqueProductId.insert(product.productId);
    }



    // OUTPUT:

    // Categories
    cout<<"Output"<<endl;
    cout << "Categories: ";
    for (const auto& cat : categories) {
        cout << cat << " ";
    }
    cout << endl << endl;

    // Recent Customers
    cout << "Recent Customers: ";
    for (const auto& cus : recentCus) {
        cout << cus << " ";
    }
    cout << endl << endl;

    // Order History
    cout << "Order History: "<<endl;
    for (const auto& ord : orderHistory) {
        cout << "Order ID: " << ord.orderId <<" , "
             << "Product ID: " << ord.productId <<" , " 
             << "Quantity: " << ord.quantity <<" , "
             << "Customer: " << ord.cusId << endl;
    }
    cout << endl;

    // Product Stock
    cout << "Product Stock: "<<endl;
    for (const auto& stock : productStock) {
        cout << "Product ID: " << stock.first 
             << ", Stock: " << stock.second << endl;
    }
    cout << endl;

    // Customer Data
    cout << "Customer Data: "<<endl;
    for (const auto& customer : customerData) {
        cout << customer.first << " -> " << customer.second << endl;
    }
    cout << endl;

    // Unique Product IDs
    cout << "Unique Product IDs: ";
    for (const auto& id : uniqueProductId) {
        cout << id << " ";
    }
    cout << endl;

    
    return 0;
}