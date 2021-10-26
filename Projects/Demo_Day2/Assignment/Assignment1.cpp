#include <iostream>

int main() {

size_t m,n,k;
// input m ,n,k from the user 

unsigned int ***Array = new unsigned int **[m];
//*Array = new unsigned int *[n];   
for(size_t i =0;i<m;i++)
{
    *(Array+i) = new unsigned int *[n];
}
for (size_t j = 0; j < n; n++)
{
    for (size_t x = 0; x < k; x++)
    {
        *(*(Array+i)) = new unsigned int *[n];
    }
    
}

**Array = new unsigned int [6];
for(size_t j =0;j<)
unsigned char *ArrDemo  = new unsigned int[2];


int size1,size2,size3;
std::cout << "Please enter size of  first array..." << std::endl;
std::cin >> size1;

int* ptr = *array; // valid, equivalent to 'ptr = &array[0]'
*array=*(array+size1);
std::cout << "Please enter size of  first array..." << std::endl;
std::cin >> size2;

int** ptr = **array; // valid, equivalent to 'ptr = &array[0]'
**array=**(array+size2);

std::cout << "Please enter size of  first array..." << std::endl;
std::cin >> size2;

int*** ptr = ***array; // valid, equivalent to 'ptr = &array[0]'
***array=***(array+size2);

std::cout << "Please enter size of  first array..." <<sizeof(array)<< std::endl;
// for(int i =0;i<size;i++)
// {
//     int value;
//     std::cout << "please enter value in first  at this adress"<<ptr << std::endl;
//     std::cin >> value;
//     ptr +i = &value;
// }
return 0;
}

