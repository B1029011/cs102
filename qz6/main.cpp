/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Clock {
    protected:
        int hour;
        int min;
        int sec;
        string day;
    public:
        Clock (int h,int m,int s,string d){
            hour = h;
            min = m;
            sec = s;
            day = d;
        };
        void display(void){
            cout << hour << ":"<<min << ":" << sec << " " << day <<endl;
        }
};

class StandardClock : Clock {
    public:
        StandardClock (int h,int m,int s,string d) : Clock(h, m, s, d){
            hour = h;
            min = m;
            sec = s;
            day = d;
        };
        void display(void){
            if(day[0] == 'A')
                cout<<"上午 "<< hour << ":"<<min << ":" << sec <<endl;
            else if (day[0] == 'P')
                cout<<"下午 "<< hour << ":"<<min << ":" << sec <<endl;
        }
};

class MilitaryClock : Clock{
    public:
        MilitaryClock (int h,int m,int s,string d) : Clock(h, m, s, d){
            hour = h;
            min = m;
            sec = s;
            day = d;
            if(day == "PM") hour+=12;
        };
        void display(void){
            cout<< hour << ":"<<min << ":" << sec <<endl;;
        }
};



int main()
{
    Clock cc(10,25,43,"AM");
    StandardClock sc(10,25,43,"AM");
    MilitaryClock mc(10,25,43,"AM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
