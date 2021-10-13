#include <iostream>
#include <cstring>

int main() {
std::cout << "Please think of the number between 0 and 100!"<< std::endl;
int low = 0;
int high = 128;
    int count = 0;

while(1)
{
    int guess = (high + low)/2;//testing
    char a;
    std::cout <<"Is your testing secret number "<<guess<< " ?"<< std::endl;
    std::cout <<"Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly."<< std::endl;
    ++count;
    std::cout<<"count is "<< count<<std::endl;
    std::cin >> a;
    if(a == 'c')
    {
        std::cout <<"Game over. Your secret number was:"<<guess<< std::endl;
        break;
    }

    else if(a == 'l')
    {
          low = guess;
    }
    else if(a == 'h')
    {
        high = guess;
    }
        
    else{
         std::cout<<"Sorry, I did not understand your input."<< std::endl;

    }
        }
        }