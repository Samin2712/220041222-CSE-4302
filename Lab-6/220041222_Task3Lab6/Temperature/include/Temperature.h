#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <iostream>
using namespace std;
class Fahrenheit;
class Kelvin;
class Celsius
{
private:
    double temperature;
public:
    Celsius(double temp=0.0);
    void assign(double temp);
    void display() const;
    operator Fahrenheit();
    operator Kelvin();
};
class Fahrenheit
{
private:
    double temperature;
public:
    Fahrenheit(double temp=32.0);
    void assign(double temp);
    void display() const;
    operator Celsius();
    operator Kelvin();
};
class Kelvin
{
private:
    double temperature;
public:
    Kelvin(double temp=0.0);
    void assign(double temp);
    void display() const;
    operator Celsius();
    operator Fahrenheit();
};

#endif

