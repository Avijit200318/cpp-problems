#include<bits/stdc++.h>
using namespace std;

class NonWithdrawlAccount{
    public:
    virtual void deposite(double amount) = 0;
};

class WithdrawlAccount: public NonWithdrawlAccount{
    public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount: public WithdrawlAccount{
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

class CurrrentAccount: public WithdrawlAccount{
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


class FixedDepostieAccount: public NonWithdrawlAccount{
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
};

class BankClient{
    private:
        vector<NonWithdrawlAccount*> accounts1;
        vector<WithdrawlAccount*> accounts2;

    public:
        BankClient(vector<NonWithdrawlAccount*> accounts1, vector<WithdrawlAccount*> accounts2){
            this->accounts1 = accounts1;
            this->accounts2 = accounts2;
        }

        void processTransactions(){
            for(auto acc: accounts1){
                acc->deposite(200);
            }

            for(auto acc : accounts2){
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
    vector<NonWithdrawlAccount*> accounts1;
    vector<WithdrawlAccount*> accounts2;
    accounts2.push_back(new SavingAccount());
    accounts2.push_back(new CurrrentAccount());
    accounts1.push_back(new FixedDepostieAccount());

    BankClient* client = new BankClient(accounts1, accounts2);
    client->processTransactions();
    return 0;
}