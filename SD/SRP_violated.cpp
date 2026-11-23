#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
    int price;
    string name;

    Product(int price, string name){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    private:
        vector<Product*> products;

    public:
        void addProduct(Product* p){
            products.push_back(p);
        }

        const vector<Product*>& getProduct(){
            return products;
        }

        // calculate total price 1
        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }

        // violating SRP - prints invoice
        void printInvoice(){
            cout<<"Shopping cart invoice:"<<endl;

            for(auto p : products){
                cout<<p->name<<" - "<<p->price<<endl;
            }
            cout<<"total price: "<<calculateTotal()<<endl;
        }

        // violating SRP - save in database
        void saveToDB(){
            // some db saving conditions
            cout<<"saving inforamtion to db";
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product(150, "laptop"));
    cart->addProduct(new Product(100, "phone"));

    cart->printInvoice();
    cart->saveToDB();
}