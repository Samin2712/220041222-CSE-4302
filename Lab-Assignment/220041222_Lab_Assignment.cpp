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
        virtual ~Vehicles(){}
        virtual void performMaintenance()const=0;
        virtual void displayInfo() const
        {
            cout<< "License Plate: "<<licensePlate<<endl;
            cout<< "Manufacturer: "<<mfacturer<<endl;
            cout<< "Carriage Size Limit: "<<carriageSizelimKg<< " KG"<<endl;
        }
};
class GasolineVehicles:public virtual Vehicles
{
    protected:
        int fuelTankCapacity;
        string fuelType;

    public:
        GasolineVehicles(string l,string m, int lim, int fuelCapacity, string fuel):Vehicles(l,m,lim),fuelTankCapacity(fuelCapacity),fuelType(fuel){}
        virtual ~GasolineVehicles(){}
        void displayInfo() const override
        {
            Vehicles::displayInfo();
            cout<< "Fuel tank capacity: "<<fuelTankCapacity<< " L"<<endl;
            cout<< "Fuel type: "<<fuelType<<endl;
        }
        void performMaintenance() const override {cout<<"Maintainance of gesolin-vehicles"<<endl;}
};

class Motorcycle:public GasolineVehicles
{
    public:
        Motorcycle(string l,string m,int lim,int fuelCapacity,string fuel):Vehicles(l,m,lim),GasolineVehicles(l,m,lim,fuelCapacity, fuel){}

        void performMaintenance() const override
        {
            cout<<"Maintainance of Motorcycle"<<endl;
        }
};
class Car:public GasolineVehicles
{
    private:
        int passengerCapacity;
    public:
        Car(string l,string m,int lim,int fuelCapacity,string fuel,int pass):Vehicles(l,m,lim),GasolineVehicles(l,m,lim,fuelCapacity, fuel), passengerCapacity(pass) {}
        void displayInfo() const override
        {
            GasolineVehicles::displayInfo();
            cout<< "Car passenger capacity: "<<passengerCapacity<<endl;
        }
        void performMaintenance() const override {cout<<"Maintainance of Car"<<endl;}
};
class Truck:public GasolineVehicles
{
    private:
        int cargoCapacityKg;
    public:
        Truck(string l,string m,int lim,int fuelCapacity,string fuel,int cargoCapacity):Vehicles(l,m,lim),GasolineVehicles(l,m,lim,fuelCapacity,fuel),cargoCapacityKg(cargoCapacity) {}
        void displayInfo() const override
        {
            GasolineVehicles::displayInfo();
            cout<< "Truck cargo capacity: "<<cargoCapacityKg<<endl;
        }
        void performMaintenance() const override {cout<<"Maintainance of Truck"<<endl;}
};

class Electric_Vehicles:public virtual Vehicles
{
    protected:
        int battery_capacity;
        int charging_time;
    public:
        Electric_Vehicles(string l,string m,int lim,int bat_cap,int cg_time):Vehicles(l,m,lim),battery_capacity(bat_cap),charging_time(cg_time){}
        virtual ~Electric_Vehicles(){}
        void displayInfo() const override
        {
            Vehicles::displayInfo();
            cout<< "Battery capacity: "<<battery_capacity<< " KWh"<<endl;
            cout<< "Charging time: "<<charging_time<<" min"<<endl;
        }
        void performMaintenance() const override {cout<<"Maintainance of electric-vehicles "<<endl;}
};
class Hybrid_vehicles:public GasolineVehicles, public Electric_Vehicles
{
    private:
        double energyRegenerationEfficiency;
    public:
        Hybrid_vehicles(string l,string m,double lim,double fuelCapacity,string fuelType,
                    double batteryCap, int chargeTime, double efficiency)
            : Vehicles(l,m,lim),
            GasolineVehicles(l,m,lim,fuelCapacity,fuelType),
            Electric_Vehicles(l,m,lim,batteryCap,chargeTime),
            energyRegenerationEfficiency(efficiency) {}
        virtual void displayInfo() const
        {
            GasolineVehicles::displayInfo();
            cout<< "Battery capacity: "<<battery_capacity<< " KWh"<<endl;
            cout<< "Charging time: "<<charging_time<<" min"<<endl;
            cout<< "Energy regeneration efficiency: "<<energyRegenerationEfficiency<<endl;
        }
        void performMaintenance() const override{cout << "Maintainance of electric-vehicles"<<endl;}
};

class Employee
{
    protected:
        string name;
        //int id;
    public:
        Employee(string n):name(n){}
        virtual ~Employee(){}
        virtual void introduce()=0;
};
class Manager:public Employee
{
    private:
        static int Man_id;
    public:
        Manager(string n):Employee(n){}

        void introduce() override
        {
            cout<<"Name: Mr."<<name<<endl;
            cout<<"Manager-ID: "<<Man_id++<<endl;
        }
};
int Manager::Man_id=101;
class Driver:public Employee
{
    private:
        static int Dri_id;
    public:
        Driver(string n):Employee(n){}
        void introduce() override
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Driver-ID: "<<Dri_id++<<endl;
        }
};
int Driver::Dri_id=201;
class Branch_input
{
    private:
        vector<Vehicles*>vehicle;
        vector<Employee*>employee;
    public:
        ~Branch_input()
        {
            for(auto v:vehicle) delete v;
            for(auto e:employee) delete e;
        }
        void addVehicle(Vehicles* v)
        {
            vehicle.push_back(v);
        }
        void addEmplyee(Employee* e)
        {
            employee.push_back(e);
        }
        void introduceEmployee()const
        {
           cout<< "-----------------Employee Information------------------------"<<endl;
            for(auto x:employee)
            {
                x->introduce();
                cout<<endl;
            }
        }
        void maintenanceAllVehicles()const
        {
            cout<< "-----------------Maintenance Information------------------------"<<endl;
            for(auto v:vehicle) v->performMaintenance();
        }
        void showVehicleInfo() const
        {
            cout<< "-----------------Vehicle Information------------------------"<<endl;
            for(auto vh:vehicle)
            {
                vh->displayInfo();
                cout<<endl;
            }
        }
};

int main()
{
    Branch_input branch;
    branch.addVehicle(new Motorcycle("H-123","Discover",130,30,"Petrol"));
    branch.addVehicle(new Car("C-123","Lamborgini",300,40,"Octane",7));
    branch.addVehicle(new Truck("T-123","Volvo",2000,100,"Diesel",5000));
    branch.addVehicle(new Electric_Vehicles("E-123","Tesla",700,75,60));
    branch.addVehicle(new Hybrid_vehicles("H-123","Toyota",400,20,"Octane",40,42,90.2));

    branch.addEmplyee(new Manager("Kalam"));
    branch.addEmplyee(new Manager("Rafiq"));
    branch.addEmplyee(new Driver("Shiraj"));
    branch.addEmplyee(new Driver("Alice"));

    branch.showVehicleInfo();

    branch.introduceEmployee();

    branch.maintenanceAllVehicles();
    
}