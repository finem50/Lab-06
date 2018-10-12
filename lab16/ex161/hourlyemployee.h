//This is the HEADER FILE hourlyemployee.h.
//This is the INTERFACE for the class HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;

namespace savitchemployees
{

    class HourlyEmployee : public Employee
    {
    public:
        HourlyEmployee();
        HourlyEmployee(string new_name, string new_ssn, double new_wage_rate, double new_hours);
        void set_rate(double new_wage_rate);
        double get_rate();
        void set_hours(double hours_worked);
        double get_hours();
        void give_raise();
        void print_check();
    private:
        double wage_rate;
        double hours;
    };

}//savitchemployees

#endif //HOURLYMPLOYEE_H
