#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Vehicles
{
protected:
    string licensePlate;
    string mfacturer;
    int carriageSizelimKg;

public:
    Vehicles(string l,string m,int lim):licensePlate(l),mfacturer(m),carriageSizelimKg(lim){}
    virtual void performMaintenance()=0;
};
class GasolineVehicles:public Vehicles
{
protected:
    int fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicles(string l,string m, int lim, int fuelCapacity, string fuel):Vehicles(l,m,lim),fuelTankCapacity(fuelCapacity),fuelType(fuel){}

    void performMaintenance() override {cout<<"Maintainance of gesolin-vehicles"<<endl;}
};

class Motorcycle:public GasolineVehicles
{
public:
    Motorcycle(string l,string m,int lim,int fuelCapacity,string fuel):GasolineVehicles(l,m,lim,fuelCapacity, fuel){}

    void performMaintenance() override {
        cout<<"Maintainance of Motorcycle"<<endl;
    }
};
class Car:public GasolineVehicles
{
private:
    int passengerCapacity;
public:
    Car(string l,string m,int lim,int fuelCapacity,string fuel,int pass):GasolineVehicles(l,m,lim,fuelCapacity, fuel), passengerCapacity(pass) {}

    void performMaintenance() override {cout<<"Maintainance of Car"<<endl;}
};
class Truck:public GasolineVehicles
{
private:
    int cargoCapacityKg;
public:
    Truck(string l,string m,int lim,int fuelCapacity,string fuel,int cargoCapacity):GasolineVehicles(l,m,lim,fuelCapacity,fuel),cargoCapacityKg(cargoCapacity) {}

    void performMaintenance() override {cout<<"Maintainance of Truck"<<endl;}
};

class Electric_Vehicles:public Vehicles
{
 private:
    int battery_capacity;
    int charging_time;
 public:
    Electric_Vehicles(string l,string m,int lim,int bat_cap,int cg_time):Vehicles(l,m,lim),battery_capacity(bat_cap),charging_time(cg_time){}
    void performMaintenance() override {cout<<"Maintainance of electric-vehicles "<<endl;}
};
class Hybrid_vehicles:public Vehicles
{
 private:
    int fuelTankCapacity;
    string fuelType;
    int battery_capacity;
    int charging_time;
    float energyRegeneration;
  public:
    Hybrid_vehicles(string l,string m,int lim,int f_cap,string f_type,int bat_cap,int cg_time,float e_r)
    : Vehicles(l,m,lim),fuelTankCapacity(f_cap),fuelType(f_type),battery_capacity(bat_cap),charging_time(cg_time),energyRegeneration(e_r){}
    void performMaintenance() override {cout<<"Maintainance of hybrid-vehicles "<<endl;}
};

class Employee
{
protected:
    string name;
    int id;
public:
    Employee(string n,int i):name(n),id(i){}
    virtual void introduce()=0;
};
class Manager:public Employee
{
public:
    Manager(string n,int i):Employee(n,i){}

    void introduce() override {cout<<"Mr. "<<name<<endl;}
};

class Driver:public Employee
{
public:
    Driver(string n,int i):Employee(n,i){}

    void introduce() override {cout<<name<<endl;}
};
class Branch_input
{
 private:
    vector<Motorcycle>motorcycles;
    vector<Car>cars;
    vector<Truck>trucks;
    vector<Electric_Vehicles>electricVehicles;
    vector<Hybrid_vehicles>hybridVehicles;
    vector<Manager>managers;
    vector<Driver>drivers;
 public:
    Branch_input(vector<Motorcycle>m,vector<Car>c,vector<Truck>t,vector<Electric_Vehicles>e,vector<Hybrid_vehicles> h,
    vector<Manager> mgrs, vector<Driver> drvs):motorcycles(m),cars(c),trucks(t),electricVehicles(e),hybridVehicles(h),managers(mgrs),drivers(drvs) {}
     void introduceEmployees()
     {
        cout<<"Introducing Managers:"<<endl;
        for(auto &man:managers) {man.introduce();}
        cout << "\nIntroducing Drivers:" << endl;
        for (auto &dri:drivers) {dri.introduce();}
    }
    void perform_vehicle_maintainance()
    {
        for(auto &mt:motorcycles) mt.performMaintenance();
        for(auto &cr:cars) cr.performMaintenance();
        for(auto &tr:trucks) tr.performMaintenance();
        for(auto &el:electricVehicles) el.performMaintenance();
        for(auto &hv:hybridVehicles) hv.performMaintenance();
    }
};

int main()
{
    vector<Motorcycle>motorcycles;
    vector<Car>cars;
    vector<Truck>trucks;
    vector<Electric_Vehicles>electricVehicles;
    vector<Hybrid_vehicles>hybridVehicles;
    vector<Manager>managers;
    vector<Driver>drivers;

    for(int i=0;i<2;i++)
    {
        motorcycles.push_back(Motorcycle("H-123","Discover",130,30,"Petrol"));
        cars.push_back(Car("C-123","Lamborgini",300,40,"Octane",7));
        trucks.push_back(Truck("T-123","Volvo",2000,100,"Diesel",5000));
        electricVehicles.push_back(Electric_Vehicles("E-123","Tesla",700,75,60));
        hybridVehicles.push_back(Hybrid_vehicles("H-123","Toyota",400,20,"Octane",40,42,90.2));
    }
    for(int i=1;i<=2;i++) managers.push_back(Manager("Rafiq",100+i));
    for(int i=1;i<=2;i++) drivers.push_back(Driver("Kalam",300+i));

    Branch_input br(motorcycles,cars,trucks,electricVehicles,hybridVehicles,managers,drivers);

    cout<<"-----Employee Intoduction-----"<<endl;
    br.introduceEmployees();
    cout<<"-----Vehicle Maintainance-----"<<endl;
    br.perform_vehicle_maintainance(); 
}