//This is the IMPLEMENTATION FILE: salariedemployee.cpp
//This is the IMPLEMENTATION for the class SalariedEmployee.
//The interface for the class SalariedEmployee is in
//the header file salariedemployee.h.
#include <iostream>
#include <string>
#include "salariedemployee.h"
using namespace std;

namespace savitchemployees
{
    SalariedEmployee::SalariedEmployee():Employee()
    {
        cout << " Enter Salaried Employee's weekly salary\n";
        cin >> salary;
    }

    SalariedEmployee::SalariedEmployee(string new_name, 	string new_number,
                                   				double new_weekly_pay				)
                     : Employee(new_name, new_number), salary(new_weekly_pay)
    {
        //deliberately empty
    }

    void SalariedEmployee::give_raise()
    {
        salary = (salary * 0.1) + salary;
    }

    double SalariedEmployee::get_salary()
    {
        return salary;
    }

    void SalariedEmployee::change_salary(double new_salary)
    {
        salary = new_salary;
    }

    void SalariedEmployee::print_check()
    {
        net_pay = salary;
        cout		 << 		"\n__________________________________________________\n";
        cout << "Pay to the order of " << name << endl;
        cout		 << "The sum of " << net_pay << " Dollars\n";
        cout 		<< "_________________________________________________\n";
        cout 		<< "Check Stub NOT NEGOTIABLE \n" ;
        cout		 << "Employee Number: " << ssn << endl;
        cout		 << " Salaried Employee. Regular Pay: "
             		<< salary << endl;
        cout		<< "_________________________________________________\n";
    }
}//savitchemployees
