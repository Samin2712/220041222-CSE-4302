#include<iostream>
#include<cmath>
using namespace std;
class Trigonmetry_Calc
{
    private:
        float curr_angle;
        float prev_angle;
         float set_current(float x)
        {
            prev_angle=curr_angle;
            curr_angle=x;
        }
        float get_current()
        {
            return curr_angle;
        }
    public:
        Trigonmetry_Calc():curr_angle(0.0),prev_angle(0.0){}
        Trigonmetry_Calc(int x):curr_angle(x),prev_angle(x){}
        float calculateSine()
        {
            return sin(curr_angle*M_PI/180);
        }
        float calculateCosine()
        {
            return cos(curr_angle*M_PI/180);
        }
        float calculateTangent()
        {
            if(fmod(curr_angle,180.0)==90.0)
            {
                cout<< "Invalid operation: undefined result."<<endl;
                curr_angle=prev_angle;
                return tan(prev_angle);
            }
            else
            {
                return tan(curr_angle*M_PI/180);
            }
        }
        float calculateArcSine()
        {
            float redian_eq=curr_angle*M_PI/180;
            cout<< "Radian equivalent: "<<redian_eq<<endl;
            return asin(redian_eq);
        }
        float calculateArcCosine()
        {
            return acos(curr_angle*M_PI/180);
        }
        float calculateArcTangent()
        {
            return atan(curr_angle*M_PI/180);
        }
        void calculateForAngle(float paramAngle)
        {
            cout<< "Calculating for angle: "<<paramAngle<< "degrees"<<endl;
            cout<< "Sine: "<< sin(paramAngle*M_PI/180)<<endl;
            cout<< "Cosine: "<< cos(paramAngle*M_PI/180)<<endl;
            if(fmod(paramAngle,180.0)==90.0)
            {
                cout<< "Invalid operation: undefined result."<<endl;
            }
            else cout<< "Tangent: "<< tan(paramAngle*M_PI/180)<<endl;
        }
        void clear()
        {
            curr_angle=0.0;
        }
        void display()
        {
            cout<< "Calculator display: "<<curr_angle<< "degrees"<<endl;
        }
        ~Trigonmetry_Calc()
        {
            cout<< "Destructor of the Calculator object is called."<<endl;
        }
};
int main()
{
    Trigonmetry_Calc calculator;
    calculator.display();
    cout<< "Sine: "<<calculator.calculateSine()<<endl;
    cout<< "Cosine: "<<calculator.calculateCosine()<<endl;
    cout<< "Tangent: "<<calculator.calculateTangent()<<endl;
     Trigonmetry_Calc calc_with_angle(270);
     cout<< "Sine: "<<calc_with_angle.calculateSine()<<endl;
    cout<< "Cosine: "<<calc_with_angle.calculateCosine()<<endl;
    cout<< "Tangent: "<<calc_with_angle.calculateTangent()<<endl;
    calc_with_angle.display();
    calculator.calculateForAngle(45.0);
    calculator.clear();
    calculator.display();
}

