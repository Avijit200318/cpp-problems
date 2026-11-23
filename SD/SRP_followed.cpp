#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
        string name;
        int price;

        Product(string name, int price){
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart{
    private:
        vector<Product*> products;

    public:
        void addProducts(Product* p){
            products.push_back(p);
        }

        vector<Product*> getProducts(){
            return products;
        }

        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }
};

class ShoppingCartInvoice{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartInvoice(ShoppingCart* cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout<<"Shopping cart invoice:"<<endl;

            for(auto p : cart->getProducts()){
                cout<<p->name<<" - "<<p->price<<endl;
            }
            cout<<"total: "<<cart->calculateTotal()<<endl;
        }
};

class ShoppingCartSaveDB{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartSaveDB(ShoppingCart* cart){
            this->cart = cart;
        }

        void saveToDB(){
            cout<<"information are saved to db";
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProducts(new Product("laptop", 150));
    cart->addProducts(new Product("phone", 100));

    ShoppingCartInvoice* printer = new ShoppingCartInvoice(cart);
    printer->printInvoice();

    ShoppingCartSaveDB* db = new ShoppingCartSaveDB(cart);
    db->saveToDB();

    return 0;
}