#include <bits/stdc++.h>
#include <iostream>
#include "Assignment.h"

int main() {

	// Declare an object of class geeks
	Customer obj1;
    Customer obj2;

	// accessing data member
	obj1.visitdate = "7/10/2021";
    obj1.customername ="prakhar";
    obj1.service_id=1;
    obj1.part_number=1;
    obj1.service(obj2,obj2.service_id);
    obj1.partschange(obj1,obj1.part_number);
    //
    obj2.visitdate="17/09/2021";
    obj2.customername ="tyagi";
    int a=2;
    int b=2;
    obj2.service(obj2,obj2.service_id);
    obj2.partschange(obj2,obj2.part_number);

	// accessing member function
	obj1.printname();
	return 0;
}
