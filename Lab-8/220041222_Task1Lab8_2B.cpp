#include<iostream>
using namespace std;
class Account
{
    protected:
        string accountNo;
        string accountName;
        float balance;
    public:
        Account():accountNo(NULL),accountName(NULL),balance(0.0){}
        Account(string ac_name,float bal):accountName(ac_name),balance(bal){}
        void get_accNo() {cout<<accountNo<<endl;}
        void get_accName() {cout<<accountName<<endl;}
        void get_balance() {cout<<balance<<endl;}
        virtual void description()const
        {
            cout<< "Account No: "<<accountNo<<", Account Name: "<<accountName<< ", Balance: "<<balance<<endl;
        }
};
int nexnextAccount=1;
class CurrentAccount: public Account
{
    private:
        const static int serviceCharge=100;
        const static int accountPrefix=100;
        static int nextAccount;
    public:
        CurrentAccount(string ac_name,float bal):Account(ac_name,bal)
        {
            accountNo=to_string(accountPrefix)+to_string(nextAccount++);
        }
        void description()const override
        {
            cout<< "Current-Account: "<<endl;
            Account::description();
            cout<< "Service Charge: "<<serviceCharge<<endl;
            cout<<endl;
        }

};
int CurrentAccount::nextAccount=1;
class SavingsAccount:public Account
{
    private:
        float interestRate;
        float monthlyDepositAmount;
        const static int accountPrefix=200;
        static int nextAccount;
    public:
        SavingsAccount(string ac_name,float bal,float int_rate,float dep_am):Account(ac_name,bal),interestRate(int_rate),monthlyDepositAmount(dep_am)
        {
            accountNo=to_string(accountPrefix)+to_string(nextAccount++);
        }
        void description()const override
        {
            cout<< "Savings-Account: "<<endl;
            Account::description();
            cout<< "Interest Rate: "<<interestRate<<", Monthly Deposit Amount: "<<monthlyDepositAmount<<endl;
            cout<<endl;
        }

};
int SavingsAccount::nextAccount=1;

class MonthlyDepositScheme:public Account
{
    protected:
        float interestRate;
        float monthlyDepositAmount;
        const static int accountPrefix=300;
        static int nextAccount;
    public:
        MonthlyDepositScheme(string ac_name,float bal,float int_rate,float dep_am):Account(ac_name,bal),interestRate(int_rate),monthlyDepositAmount(dep_am)
        {
            accountNo=to_string(accountPrefix)+to_string(nextAccount++);
        }
        void description()const override
        {
            cout<< "Monthly Deposit-Account: "<<endl;
            Account::description();
            cout<< "Interest Rate: "<<interestRate<<", Monthly Deposit Amount: "<<monthlyDepositAmount<<endl;
        }

};
int MonthlyDepositScheme::nextAccount=1;
class TwoYearMDS:public MonthlyDepositScheme
{
private:
    float maximumInterest;
public:
    TwoYearMDS(string ac_name,float bal,float int_rate,float dep_am,float max_int)
        : MonthlyDepositScheme(ac_name,bal,int_rate,dep_am),maximumInterest(max_int){}

    void description()const override
    {
         cout<< "Two Year Monthly Deposit Scheme Account: "<<endl;
         MonthlyDepositScheme::description();
         cout<< "Maximum Interest: "<<maximumInterest<<endl;
         cout<<endl;
    }
};

class FiveYearMDS:public MonthlyDepositScheme
{
private:
    float maximumInterest;
public:
    FiveYearMDS(string ac_name,float bal,float int_rate,float dep_am,float max_int)
        : MonthlyDepositScheme(ac_name,bal,int_rate,dep_am),maximumInterest(max_int){}

    void description()const override
    {
         cout<< "Five Year Monthly Deposit Scheme Account: "<<endl;
         MonthlyDepositScheme::description();
         cout<< "Maximum Interest: "<<maximumInterest<<endl;
         cout<<endl;
    }
};

class InitialDepositMDS:public MonthlyDepositScheme
{
private:
    float maximumInterest;
    float initialDepositAmount;
public:
    InitialDepositMDS(string ac_name,float bal,float int_rate,float dep_am,float max_int,float int_dep_am)
        : MonthlyDepositScheme(ac_name,bal,int_rate,dep_am),maximumInterest(max_int),initialDepositAmount(int_dep_am){}

    void description()const override
    {
         cout<< "Initial Deposit Monthly Deposit Scheme Account: "<<endl;
         MonthlyDepositScheme::description();
         cout<< "Maximum Interest: "<<maximumInterest<<endl;
         cout<<"Initial Deposit Amount: "<<initialDepositAmount<<endl;
         cout<<endl;
    }
};
class LoanAccount:public Account
{
    private:
        float interestRate;
        float monthlyDepositAmount;
        const static int accountPrefix=900;
        static int nextAccount;
    public:
        LoanAccount(string ac_name,float bal,float int_rate,float dep_am):Account(ac_name,bal),interestRate(int_rate),monthlyDepositAmount(dep_am)
        {
            accountNo=to_string(accountPrefix)+to_string(nextAccount++);
        }
        void description()const override
        {
            cout<< "Savings-Account: "<<endl;
            Account::description();
            cout<< "Interest Rate: "<<interestRate<<" Monthly Deposit Amount: "<<monthlyDepositAmount<<endl;
            cout<<endl;
        }

};
int LoanAccount::nextAccount=1;

int main()
{
    Account ac("Rafi",3000);
    ac.get_accName();
    ac.get_balance();
    cout<<endl;
    CurrentAccount cr1("Mahi",5500),cr2("Jarif",20000);
    cr1.description();
    cr2.description();

    SavingsAccount sv("Shafiq",43000,7.5,2000);
    sv.description();

    TwoYearMDS tyd("Junaid",34000,2.4,1000,5.2);
    tyd.description();

    InitialDepositMDS idm("Islam",23000,6.4,2000,7.2,2400);
    idm.description();

    LoanAccount la("Ashraf",50000,1.2,1200);
    la.description();
}