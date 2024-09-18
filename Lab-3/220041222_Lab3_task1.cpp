#include<iostream>
using namespace std;
class Counter
{
    private:
        int count;
        int In_step;
    public:
        Counter()
        {
            count=0;
            In_step=0;
        }
        void setIncrementStep(int step)
        {
            In_step=step;
        }
        int getCount()
        {
            return count;
        }
        void increment()
        {
            count+=In_step;
        }
        void resetcount()
        {
            count=0;
        }
};
int main()
{
    Counter val;
    cout<<val.getCount()<<endl;
    val.setIncrementStep(2);
    val.increment();
    cout<<val.getCount()<<endl;
    val.setIncrementStep(4);
    val.increment();
    cout<<val.getCount()<<endl;
    val.resetcount();
    cout<<val.getCount()<<endl;
};