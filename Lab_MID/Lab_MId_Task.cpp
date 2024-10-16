#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Laptop
{
    private:
        string modelno;
        double price;
        string manufacturer;
    public:
        Laptop(string modelno = "",double price = 0.0,string manufacturer = ""):modelno(modelno),price(price),manufacturer(manufacturer){}
        void setModelNo(string modno)
        {
            modelno=modno;
        }
        string getModelNo() const
        {
            return modelno;
        }
        void setPrice(double p)
        {
            price=p;
        }
        double getPrice() const
        {
            return price;
        }
        void setManufacturer(string m)
        {
            manufacturer=m;
        }
        string getManufacturer() const
        {
            return manufacturer;
        }
        void display() const
        {
            cout<<"Model No: "<<modelno<<", Price: "<<price<<", Manufacturer: "<<manufacturer<< endl;
        }
        Laptop updatePrice(float discount)
        {
            price-=discount;
            return *this;
        }

};
double calculateAveragePrice(Laptop l[], int size)
{
    double s=0;
    for(int i=0;i<size;i++) s+=l[i].getPrice();
    return s/10;
}
void sortByManufacturer(Laptop l[], int size)
{
    sort(l,l+size,[](Laptop a,Laptop b)
    {
        return a.getManufacturer()<b.getManufacturer();
    });
}
int main()
{
    Laptop l[10];
    l[0]=Laptop("Model-1",1200.99,"Dell");
    l[1]=Laptop("Model-2",1100.50,"Apple");
    l[2]=Laptop("Model-3",900.50,"HP");
    l[3]=Laptop("Model-4",1400.25,"Lenovo");
    l[4]=Laptop("Model-5",850.75,"Asus");
    l[5]=Laptop("Model-6",1300.60,"Acer");
    l[6]=Laptop("Model-7",950.80,"Microsoft");
    l[7]=Laptop("Model-8",780.40,"Toshiba");
    l[8]=Laptop("Model-9",1150.90,"Sony");
    l[9]=Laptop("Model-10",1020.10,"Samsung");

    l[0].updatePrice(100.34);
    for(int i=0;i<10;i++) l[i].display();
    cout<<endl;
    sortByManufacturer(l,10);
    for(int i=0;i<10;i++) l[i].display();
    cout<<endl;
    cout<<"Average Price is: "<<calculateAveragePrice(l,10)<<endl;

}