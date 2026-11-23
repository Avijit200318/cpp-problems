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

class DBpersistance{
    private:
        ShoppingCart* cart;
    public:
        virtual void save(ShoppingCart* cart) = 0;
};

class SQLpersistance: public DBpersistance{
    public:
        void save(ShoppingCart* cart){
            cout<<"information is saved to sql";
        }
};

class Mongopersistance: public DBpersistance{
    public:
        void save(ShoppingCart* cart){
            cout<<"informaion is saved to mongodb";
        }
};

class saveToFile: public DBpersistance{
    public:
        void save(ShoppingCart* cart){
            cout<<"information is saved to file";
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProducts(new Product("laptop", 150));
    cart->addProducts(new Product("phone", 100));

    ShoppingCartInvoice* printer = new ShoppingCartInvoice(cart);
    printer->printInvoice();

    DBpersistance* sql = new SQLpersistance();
    DBpersistance* mongo = new Mongopersistance();
    DBpersistance* file = new saveToFile();

    sql->save(cart);
    mongo->save(cart);
    file->save(cart);

    return 0;
}