// First Day.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>  // c string class
#include <string> // c++ string class  
#include <Person.h>

using namespace std;


int main()
{

    int x = 42;
    float y = 3.14f;
    char name[32] = "Bob Jones";        //c-style
    const char* name2 = "Sally Smith"; //c-style 
    strcpy_s(name, "Rober Jones");
    x = strlen(name);
    if (strcmp(name, "mmm") < 0){
        printf("name is alphabetically less than mmm\n");
    }

    string cpp_name = "Bob Jones"; 
    cpp_name = "Robert Jones";   // no strcpy needed
    x = cpp_name.length();

    if (cpp_name < "mmm")
        cout << "cpp_name is alphabetically les than mmm\n";
       
    name2 = cpp_name.c_str(); // getting the underlying c char pointer

    cout << "x = " << x << " Hello World!\n";


    // some code that uses the Person Class
    Person P(41, "Bob", "Jones");
    Person Q(21, "Sally", "Smith");

    P.set_hourly_rate(24.53f);
    P.set_hours_worked(50);
    Q.set_hourly_rate(15.21f);
    Q.set_hours_worked(60);

    Person* pptr = new Person(44, "Eric", "Davis");

    pptr->set_hourly_rate(12.15f);
    pptr->set_hours_worked(23);
    (*pptr).set_hourly_rate(12.35f);

    delete pptr; 

    pptr = NULL; // NULL is just a macro for 0
    y = NULL; // valid but "weird"



    cout << P.get_id() << " " << P.get_first_name() << " " << P.get_last_name() << "\n";


}
