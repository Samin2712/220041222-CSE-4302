#include "Temperature.h"

Celsius::Celsius(double temp)
{
    if (temp>=-273.15) temperature=temp;
    else cout<<"Temperature cannot be below absolute zero (-273.15 °C)."<<endl;

}

void Celsius::assign(double temp)
{
    if (temp>=-273.15) temperature=temp;
    else cout<<"Temperature cannot be below absolute zero (-273.15 °C)."<<endl;

}

void Celsius::display() const
{
    cout << "The temperature is " << temperature << " Celsius." << endl;
}

Celsius::operator Fahrenheit()
{
    return Fahrenheit(temperature*9.0/5.0+32.0);
}

Celsius::operator Kelvin()
{
    return Kelvin(temperature+273.15);
}
Fahrenheit::Fahrenheit(double temp)
{
    if (temp>=-459.67)temperature=temp;
     else cout<<"Temperature cannot be below absolute zero (-459.67 °F)."<<endl;

}

void Fahrenheit::assign(double temp)
{
    if (temp>=-459.67) temperature=temp;
    else cout<<"Temperature cannot be below absolute zero (-459.67 °F)."<<endl;

}

void Fahrenheit::display() const
{
    cout << "The temperature is " << temperature << " Fahrenheit." << endl;
}

Fahrenheit::operator Celsius()
{
    return Celsius((temperature-32)*5.0/9.0);
}

Fahrenheit::operator Kelvin()
{
    return Kelvin((temperature+459.67)*5.0/9.0);
}
Kelvin::Kelvin(double temp)
{
    if (temp>=0.0) temperature = temp;
    else cout<<"Temperature cannot be below absolute zero (0 K)."<<endl;

}

void Kelvin::assign(double temp)
{
    if (temp>=0.0) temperature=temp;
     else cout<<"Temperature cannot be below absolute zero (0 K)."<<endl;

}

void Kelvin::display() const
{
    cout << "The temperature is " << temperature << " Kelvin." << endl;
}

Kelvin::operator Celsius()
{
    return Celsius(temperature-273.15);
}

Kelvin::operator Fahrenheit()
{
    return Fahrenheit(temperature*9.0/5.0-459.67);
}
