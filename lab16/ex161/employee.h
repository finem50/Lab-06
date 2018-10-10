//This is the HEADER FILE employee.h.
//This is the INTERFACE for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

namespace savitchemployees
{

    class Employee
    {
    public:
        Employee();
        Employee(string new_name, string new_ssn);
        string get_name();
        string get_ssn();
        void change_name(string new_name);
        void change_ssn(string new_ssn);
        void print_check();
        void give_raise(double amount);
    protected:
        string name;
        string ssn;
        double net_pay;
    };

}//savitchemployees

#endif //EMPLOYEE_H
