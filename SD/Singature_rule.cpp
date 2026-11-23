#include<bits/stdc++.h>
using namespace std;

class Parent{
    public:
    virtual void print(string s){
        cout<<"Parent: "<< s<<endl;
    }
};

class Child: public Parent{
    public:
    void print(string s){
        cout<<"Child: "<< s<<endl;
    }
};

class Client{
    private:
        Parent* p;
    public:
        Client(Parent* p){
            this->p = p;
        }

        void printMsg(){
            p->print("Hello");
        }
};

int main(){
    Parent* p = new Parent();
    Child* c = new Child();

    Client* client = new Client(p);
    client->printMsg();

    Client* client2 = new Client(c);
    client2->printMsg();

    return 0;
}