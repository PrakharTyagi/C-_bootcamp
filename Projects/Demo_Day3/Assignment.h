#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Customer
{
	// Access specifier
public:
    Customer() = default;
    Customer(const string &_name,const string &_date,const string &_service,const int &_part,const int &_payment):charge(_part),customerlevel(_payment){}
    virtual ~Customer() = 0;
	// Data Members
protected:
	string visitdate;
    string customername;
    string services;
    string part_change;
    int service_id;
    int part_number;
    int payment_type;
private:
    int charge=0,customerlevel=0;
     void print() {
        std::cout << "the bill for this customer is"<<charge << "and the " << customerlevel << std::endl;
    }
};

class Service : public Customer{
    public:
    ~Service() = default;
    int serviceprice( int a)
    {
        if(a==1)// 1 is for oil change
        {
            return(1*500);//500 is price of oil change
        }
        if(a==2)// 1 is for oil change
        {
            return(1*500);//500 is price of oil change
        }

    }
    int customerlevel( int b)
    {
        if(b==1)// vip
        {
            return(1);//500 is price of oil change
        }
        if(b==2)// 
        {
            return(2);//non vip
        }

    }
    Service(const int &servicenum):Customer(serviceprice(servicenum),customerlevel(servicenum)){}

};


    // void partschange(Customer E,int x)
    // {   E.part_number=x;

    //     if(x==1)
    //     {
    //         E.part_change="wheel";
    //     }
    //     else if(x==2)
    //     {
    //         E.part_change="dampers";
    //     }
    //     else{
    //         E.part_change="no part changed";
           
    //     }
    // }
    
    // void printname()
	// {
	// cout <<"Date Customer visited  is: " << visitdate<< std::endl;
    // cout <<"Customer name is:"<< customername<< std::endl;
    // cout <<"The service done on :"<< customername<<"is has service on"<<services<< std::endl;
    // cout <<"The part change on :"<< customername<<"is "<<part_change<<std::endl;
	// }

// };
