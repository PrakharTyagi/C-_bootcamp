#include <iostream>
#include <vector>

 int max(int a ,int b)
 {
     if(a>b)
     {
         return a;
     }
     else if (b>a)
     {
return b;     }
     
else
{
    return 0;
}
 }

int solution(int N)
{           std::vector<int> v;

    while(N>0)
 {
        int a =N%2;

            v.push_back (a);
        N/=2;
 }   
 int b=0, maxb=0;
 for(int i =v.size()-1;i>=0;i--)
 {
     if(v[i]==0)
     {
         b++;
     }
     else if(v[i]==1)
     {
         maxb=max(maxb,b);b=0;
     }

 }
 return maxb;
 }


 int main()
 {
     int N=100;
    int a = solution(N);
    std::cout << "  "<<a <<std::endl;
    
 }