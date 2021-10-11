#include <iostream>
#include <cstring>

int main() {
unsigned int key;
std::string input;
std::cout << "input code to be cyphered: ";
std::cin >> input;
std::cout << "Your code is: " << "\t"<< input<< std::endl;
 
    int n = input.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, input.c_str());
 
    // for (int i = 0; i < n; i++){
    //     std::cout << char_array[i];
    //     }
    std::cout << "Please enter the a positive number key between 0 to 26..." << std::endl;
    std::cin >> key;

    if(key>=0 && key<=26)
    { 
       std::cout << "correct input key.." << std::endl;
       for(int j=0;j<n;j++)
       {
            
               char_array[j]=char_array[j]-key;
                if(char_array[j]< 65||char_array[j]>90)
           {
               char_array[j]=char_array[j]+26;
           }

           std::cout <<char_array[j]<< std::endl;;
       }

    }
    else
    {
        std::cout << "incorrect input key.. please run program again" << std::endl;
        exit(0);
    }
}
