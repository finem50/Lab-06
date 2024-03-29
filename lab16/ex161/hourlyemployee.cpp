//This is the IMPLEMENTATION FILE: hourlyemployee.cpp
//This is the IMPLEMENTATION for the class HourlyEmployee.
//The interface for the class HourlyEmployee is in
//the header file hourlyemployee.h.
#include <iostream>
#include <string>
#include "hourlyemployee.h"
using namespace std;

namespace savitchemployees
{

    HourlyEmployee::HourlyEmployee() : Employee()
    {
        cout << "Enter HourlyEmployee wage rate, followed by return.:\n";
        cin >> wage_rate;
        cout << "Enter number of hours worked, followed by return:\n";
        cin >> hours;
    }

    HourlyEmployee::HourlyEmployee(string new_name, 		string new_number,
                                   				double new_wage_rate, 				double new_hours)
        : Employee(new_name, new_number),
          wage_rate(new_wage_rate), 				hours(new_hours)
    {
        //deliberately empty
    }

    void HourlyEmployee::set_rate(double new_wage_rate)
    {
        wage_rate = new_wage_rate;
    }

    double HourlyEmployee::get_rate()
    {
        return wage_rate;
    }


    void HourlyEmployee::set_hours(double hours_worked)
    {
        hours = hours_worked;
    }

    double HourlyEmployee::get_hours()
    {
        return hours;
    }


    void HourlyEmployee::give_raise()
    {
        wage_rate = (wage_rate * 0.1) + wage_rate ;
    }


    void HourlyEmployee::print_check()
    {
        net_pay = hours * wage_rate;

        cout << "\n________________________________________________\n";
        cout << "Pay to the order of " << name << endl;
        cout << "The sum of         " << net_pay << " Dollars\n";
        cout << "________________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << ssn << endl;
        cout << "Hourly Employee. \nHours worked: " << hours
             << " Rate: " << wage_rate << " Pay: " << net_pay << endl;
        cout << "_________________________________________________\n";
    }


}//savitchemployees
