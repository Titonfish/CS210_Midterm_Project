#include <string>
using namespace std;

struct School
{
    string name;
    string address;
    string city;
    string state;
    string county;
    School(string name, string address, string city, string state, string county)
    : name(name), address(address), city(city), state(state), county(county) {}

    string display() const
    {
        return name + ": " + address + ", " + city + " " + state + ", " + county;
    }
};