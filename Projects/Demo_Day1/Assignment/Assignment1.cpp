#include <iostream>

int main() {
    unsigned int input;
    unsigned int random[8][9][11];
    unsigned int v,v1;
    std::cout << "Please enter the a positive number..." << std::endl;
    std::cin >> input;
    if(input>0)
    {   v=rand()%100;// limiting range of random number 0 to 100
        std::cout << "the random number is" <<v<< std::endl;; 
        v1 = (v%input); 
        for(int i =0;i <8;i++)
        {
            for(int j =0;j <9;j++)
            {
                for(int k =0;k<11;k++)
                {
                    random[i][j][k] =(v1);
                }
            }
        }
    
    }
    else{
        std::cout << "Please run the program again ,your input number is not positive.." << std::endl;
            exit(0);// or maybe add go to label
    }
    for(int p =0;p <8;p++)
        {
            for(int q =0;q <9;q++)
            {
                for(int r =0;r<11;r++)
                {
                    std::cout <<random[p][q][r]<< "\t"; 
                }
                  std::cout << std::endl;
            }
             std::cout << std::endl;
        }


    return 0;
}
