#include<iostream>
using namespace std;
class BankAccount
{
    private:
        int account_number;
        string holder_name;
        string account_type;
        double current_balance;
        const double minimum_balance;
        static int total_accounts;
        static int active_accounts;
        static double total_source_tax;
    public:
        BankAccount(int a_no,string h_name,string type,double balance,double min_balance):
        account_number(a_no),holder_name(h_name),account_type(type),current_balance(balance),minimum_balance(min_balance){total_accounts++;}
        ~BankAccount()
        {
            total_accounts--;
            cout<< "Account of Mr./Ms. "<<holder_name<< " with account no "<<account_number<<" is destroyed with a balance BDT "<<current_balance<<endl;
        }
        void showinfo() const
        {
            cout<< "Account Number: "<<account_number<<endl;
            cout<< "Account Holder: "<<holder_name<<endl;
            cout<< "Account Type: "<<account_type<<endl;
            cout<< "Current Balance(BDT): "<<current_balance<<endl;
            cout<<"Minimum Balance(BDT): "<<minimum_balance<<endl;
        }
        void showBalance()
        {
           cout<< "Current Balance(BDT): "<<current_balance<<endl; 
        }
        void deposit(int amount)
        {
            if(amount<=0) cout<< "Invalid deposit amount"<<endl;
            else
            {
                current_balance+=amount;
                cout<< "Deposited Amount(BDT): "<<amount<<endl;
            }
        }
        void withdrawal(int amount)
        {
            if(amount<=0) cout<< "Invalid withdrawal amount"<<endl;
            else if(current_balance-amount<=minimum_balance) cout<<"Can't withdeawal!!Amount is less then minimum balance"<<endl;
            else
            {
                current_balance-=amount;
                cout<< "Withdrawal Amount(BDT): "<<amount<<endl;
            }
        }
        void giveInterst(double R_interest=3.0)
        {
            double interest=(current_balance*R_interest)/100.0;
            double tex=interest*0.10;
            total_source_tax+=tex;
            double n_interest=interest-tex;
            current_balance+=n_interest;
            cout<< "Total interest amount is(BDT): "<<n_interest<<endl;
            cout<< "Total tex amount is(BDT): "<<tex<<endl;
        }
        int tot_ac()
        {
            return total_accounts;
        }
        double tot_tex()
        {
            return total_source_tax;
        }
        static void display_state();
        static BankAccount Larger(const BankAccount &A,const BankAccount &B);
        
};
int BankAccount::total_accounts=0;
double BankAccount::total_source_tax=0.0;
void BankAccount::display_state()
{
    cout<<"Total number of BankAccount objects created: "<<BankAccount::total_accounts<<endl;
    cout<<"Total Source Tax Collected: BDT: "<<BankAccount::total_source_tax<<endl;

}
BankAccount BankAccount::Larger(const BankAccount& A,const BankAccount& B)
{
    return (A.current_balance<B.current_balance)?A:B;
}

int main()
{
    BankAccount a(37849, "Rafi", "Savings", 10000, 500);
    BankAccount b(47384, "Mahi", "Current", 5000, 1000);
    a.showinfo();
    b.showinfo();
    a.deposit(3000);
    b.deposit(6000);
    a.showBalance();
    b.showBalance();
    a.withdrawal(500);
    a.showBalance();
    b.giveInterst();
    b.showBalance();
    BankAccount::display_state();
    BankAccount larger_ac=BankAccount::Larger(a,b);
    cout<< "The account with larger balance is: "<<endl;
    larger_ac.showinfo();
}

