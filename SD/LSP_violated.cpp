#include<bits/stdc++.h>
using namespace std;

class Account{
    public:
    virtual void deposite(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount: public Account{
    private:
        double balance;
    public:
        SavingAccount(){
            balance = 0;
        }

        void deposite(double amount){
            balance += amount;
            cout<<"deposite: "<<amount<<" in saving account, current balance: "<<balance<<endl;
        }

        void withdraw(double amount){
            if(amount > balance){
                cout<<"Insufficient balance in account"<<endl;
            }
            else{
                balance -= amount;
                cout<<"withdraw: "<<amount<<" from saving account, current balance: "<<balance;
            }
        }
};

class CurrrentAccount: public Account{
    private:
        double balance;
    public:
        CurrrentAccount(){
            balance = 0;
        }

        void deposite(double amount){
            balance += amount;
            cout<<"deposite: "<<amount<<" in current account, current balance: "<<balance<<endl;
        }

        void withdraw(double amount){
            if(amount > balance){
                cout<<"Insufficient balance in account"<<endl;
            }
            else{
                balance -= amount;
                cout<<"withdraw: "<<amount<<" from current account, current balance: "<<balance;
            }
        }
};


class FixedDepostieAccount: public Account{
    private:
        double balance;
    public:
        FixedDepostieAccount(){
            balance = 0;
        }

        void deposite(double amount){
            balance += amount;
            cout<<"deposite: "<<amount<<" in FD account, current balance: "<<balance<<endl;
        }

        void withdraw(double amount){
            throw logic_error("withdraw not allowed in fixed term account");
        }
};

class BankClient{
    private:
        vector<Account*> accounts;
    public:
        BankClient(vector<Account*> accounts){
            this->accounts = accounts;
        }

        void processTransactions(){
            for(auto acc : accounts){
                acc->deposite(100);

                try{
                    acc->withdraw(100);
                } catch(const logic_error& e){
                    cout<<"Exceptions: "<<e.what()<<endl;
                }
            }
        }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrrentAccount());
    accounts.push_back(new FixedDepostieAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();
    return 0;
}