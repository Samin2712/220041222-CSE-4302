#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//Task-1
class Vehicles
{
protected:
    string licensePlate;
    string mfacturer;
    int carriageSizelimKg;

public:
    Vehicles(string l,string m,int lim):licensePlate(l),mfacturer(m),carriageSizelimKg(lim){}
    double getCarriageSizeLimit() const
    {
       return carriageSizelimKg;
    }
    virtual void performMaintenance()=0;
    virtual void displayInfo() const
    {
        cout << "License Plate: " << licensePlate << ", Manufacturer: " << mfacturer
             << ", Carriage Size Limit: " << carriageSizelimKg << endl;
    }
};

//Task-2

class GasolineVehicles:public Vehicles
{
protected:
    int fuelTankCapacity;
    string fuelType;
    double fuel_con_rate;
public:
    GasolineVehicles(string l,string m, int lim, int fuelCapacity, string fuel,double fuel_rate):Vehicles(l,m,lim),fuelTankCapacity(fuelCapacity),fuelType(fuel),fuel_con_rate(fuel_rate){}
    virtual double calculateFuelConsumption(double distance) const
    {
        return (distance/100)*fuel_con_rate;
    }
    void performMaintenance() override {cout<<"Maintainance of gesolin-vehicles"<<endl;}
     void displayInfo() const override
     {
        Vehicles::displayInfo();
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters, Fuel Type: " << fuelType << endl;
        //cout<< "Gasolin_Vehicle Fuel Consumption: "<<calculateFuelConsumption(240)<<endl;
    }
};

class Electric_Vehicles:public Vehicles
{
 protected:
    int battery_capacity;
    int charging_time;
    double elec_con_rate;
 public:
    Electric_Vehicles(string l,string m,int lim,int bat_cap,int cg_time,double elc_con_rate):Vehicles(l,m,lim),battery_capacity(bat_cap),charging_time(cg_time){}
    double electricityConsumption(double distance) const
    {
        return (distance/100)*elec_con_rate;
    }
    void performMaintenance() override {cout<<"Maintainance of electric-vehicles "<<endl;}
    void displayInfo() const override
    {
        Vehicles::displayInfo();
        cout << "Battery Capacity: " << battery_capacity << " KWh, Charging Time: " << charging_time << " minutes" << endl;
        cout<< "ElectricityConsumption: "<<electricityConsumption(240)<<endl;
    }
};

//Task-3
class Motorcycle:public GasolineVehicles
{
public:
    Motorcycle(string l,string m,int lim,int fuelCapacity,string fuel,double rate):GasolineVehicles(l,m,lim,fuelCapacity, fuel,rate){}
    double calculateFuelConsumption(double distance) const override
    {
        return (distance/100)*fuel_con_rate;
    }
    void performMaintenance() override
    {
        cout<<"Maintainance of Motorcycle"<<endl;
    }
    void displayInfo() const override
    {
        GasolineVehicles::displayInfo();
        cout<< "Truck Fuel Consumption: "<<calculateFuelConsumption(200)<<endl;
    }
};
class Car:public GasolineVehicles
{
private:
    int passengerCapacity;
public:
    Car(string l,string m,int lim,int fuelCapacity,string fuel,int pass,double rate):GasolineVehicles(l,m,lim,fuelCapacity, fuel,rate), passengerCapacity(pass) {}
    double calculateFuelConsumption(double distance) const override
    {
        return (distance/100)*fuel_con_rate;
    }
    void performMaintenance() override {cout<<"Maintainance of Car"<<endl;}
    void displayInfo() const override
    {
        GasolineVehicles::displayInfo();
        cout << "Passenger Capacity: " << passengerCapacity << endl;
       cout<< "Car Fuel Consumption: "<<calculateFuelConsumption(120)<<endl;
    }
};
class Truck:public GasolineVehicles
{
private:
    int cargoCapacityKg;
public:
    Truck(string l,string m,int lim,int fuelCapacity,string fuel,int cargoCapacity,double rate):GasolineVehicles(l,m,lim,fuelCapacity,fuel,rate),cargoCapacityKg(cargoCapacity) {}
    double calculateFuelConsumption(double distance) const override
    {
        return (distance/100)*fuel_con_rate;
    }
    void performMaintenance() override {cout<<"Maintainance of Truck"<<endl;}
    void displayInfo() const override
    {
        GasolineVehicles::displayInfo();
        cout << "Cargo Capacity: " << cargoCapacityKg << " tons" << endl;
        cout<< "Truck Fuel Consumption: "<<calculateFuelConsumption(320)<<endl;
    }
};

 class HybridVehicle:public GasolineVehicles,public Electric_Vehicles
{
private:
    double energyRegenerationEfficiency;
public:
    HybridVehicle(string l, string m, int lim, double fuelCapacity, string fuelType,
                  double batteryCap, int chargeTime, double regenEfficiency,double fuel_rate,double elc_con_rate)
          :GasolineVehicles(l,m,lim, fuelCapacity, fuelType,fuel_rate),
          Electric_Vehicles(l,l,lim, batteryCap, chargeTime,elc_con_rate),
          energyRegenerationEfficiency(regenEfficiency) {}

    double calculateFuelConsumption(double distance)const override
    {
        double fuelConsumption = (distance / 100) * 6;
        double electricConsumption = electricityConsumption(distance);
        return fuelConsumption + electricConsumption * (1 - energyRegenerationEfficiency);
    }

    void performMaintenance() override {
        cout << "Hybrid Vehicle Maintenance: Fuel system, Battery check, Regeneration system check" << endl;
    }

    void displayInfo()
    {
        Electric_Vehicles::displayInfo();
        GasolineVehicles::displayInfo();
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters, Fuel Type: " << fuelType << endl;
        cout << "Battery Capacity: " << battery_capacity << " KWh, Charging Time: " << charging_time << " minutes" << endl;
        cout << "Energy Regeneration Efficiency: " << energyRegenerationEfficiency * 100 << "%" << endl;
    }
};

//Task-4
void sort_vehicles_by_capacity(vector<Vehicles*>& vehicles)
{
    sort(vehicles.begin(), vehicles.end(), [](Vehicles* a, Vehicles* b)
    {
        return a->getCarriageSizeLimit() > b->getCarriageSizeLimit();
    });
}
int main()
{
    vector<Vehicles*> vehicles;
    vehicles.push_back(new Motorcycle("Y-1234", "Yamaha", 200, 15, "petrol",1.2));
    vehicles.push_back(new Car("T-5678", "Toyota", 500, 50, "octane", 5,1.1));
    vehicles.push_back(new Truck("F-9101", "Ford", 1000, 150, "diesel", 10000,1.5));
    vehicles.push_back(new Electric_Vehicles("1122", "Tesla", 600, 85, 120,2.3));
    vehicles.push_back(new Truck("T-123","Volvo",2000,100,"Diesel",5000,1.5));
    vehicles.push_back(new Motorcycle("H-123","Discover",130,30,"Petrol",0.8));


    HybridVehicle hyb("3344", "Toyota", 700, 40, "petrol", 90, 130, 0.1,1.2,2.3);


    sort_vehicles_by_capacity(vehicles);
    cout << "Sorted Vehicles by Carriage Size Limit:\n";
    for (auto vehicle:vehicles)
    {
        vehicle->displayInfo();
        cout << endl;
    }

    cout << "\nHybrid Vehicle Information:\n";
    hyb.displayInfo();

    for (auto vehicle : vehicles)
    {
        delete vehicle;
    }

    return 0;
}
