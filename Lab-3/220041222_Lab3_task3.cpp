#include<iostream>
#include<cstring>
using namespace std;
class Medicine
{
    private:
       char trade_name[30];
       char generic_name[30];
       double unit_price=0;
       double dis_percent=5;
    public:
       void assignName(char name[], char genericName[])
       {
          strcpy(trade_name,name);
          strcpy(generic_name,genericName);
       }
       void assignPrice(double price)
       {
          unit_price=price;
       }
       void setDiscountPercent(double percent)
       {
         if(percent<0||percent>50) cout<< "Your Percent for discount exceeded the limit"<<endl;
         else dis_percent=percent;
       }
       double getSellingPrice(int nos)
       {
          double result=unit_price-(unit_price*dis_percent)/100;
          return result*nos;
       }
       double getSellingPrice()
       {
          double result=unit_price-(unit_price*dis_percent)/100;
          return result;
       }
       void display()
       {
         cout<< "MRP. of "<<trade_name<< " ("<<generic_name<<") "<< "is BDT "<<unit_price<< ".Current discount "<<dis_percent<< "%."<<endl;
       }
};
int main()
{
    Medicine med;
    med.assignName("Napa","Paracetamol");
    med.assignPrice(1.00);
    med.setDiscountPercent(10);
    med.display();
    cout<< "Selling price BDT "<< med.getSellingPrice(10)<<endl;
}