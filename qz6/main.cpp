#include <iostream>
#include <string>

using namespace std;

class Clock {
    protected:
        int hour;
        int minute;
        int second;
        string meridian;
    public:
        Clock(int x, int y, int z, string s) {
            if (x>12 || x<1)    cout << "mistake" <<endl;
            else hour = x;
            if (y>59 || y<0)    cout << "mistake" <<endl;
            else minute = y;
            if (z>59 || z<0)    cout << "mistake" <<endl;
            else second = z;
            if (s!="AM" && s!="PM")    cout << "mistake" <<endl;
            else meridian = s;
        }
        void display() {
            cout << hour << ":" << minute << ":" << second << " " 
            << meridian << endl;
        }
};

class StandardClock : Clock {
    public:
        StandardClock (int x, int y, int z, string s) : Clock(x, y, z, s) {}
        void display() {
            if (meridian == "AM")
                cout << "上午" << hour << ":" << minute << ":" << second << endl;
            else if(meridian == "PM")
                cout << "上午" << hour << ":" << minute << ":" << second << endl;
        }
};

class MilitaryClock : Clock {
    public:
        MilitaryClock (int x, int y, int z, string s) : Clock(x, y, z, s) {}
        void display() {
            if (meridian == "AM")
                cout  << hour << ":" << minute << ":" << second << endl;
            else if(meridian == "PM") {
                hour += 12;
                cout << hour << ":" << minute << ":" << second << endl;
            }
        }
};

int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
