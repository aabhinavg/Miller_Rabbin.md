#include<iostream>
#include<cstdlib>
using namespace std;
int Miller(long long p,int value);
long long mulmod(long long a, long long b, long long mod);
long long modulo(long long base, long long exponent, long long mod);


long long mulmod(long long a, long long b, long long mod)
{
   long long x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod; 
}



long long modulo(long long base, long long exponent, long long mod)

{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}


int Miller(long long p,int value)
{
    int j;
    long long check;
    if (p<2){return 0;} 
   /*if less than 2 return 0 becuause 0 and 1 are neither prime not composite number*/
   
    if(p!=2 && p%2 ==0){ return 0;}  
    /*checking number is even or not*/
    check = p - 1;
    while (check %2 ==0 ){check/=2;} /*check if number is power of 2*/
    for (j = 0; j < value ; j ++)
    {  
        long long a = rand() % (p-1) +1 ,temp =check;
        long long mod = modulo(a , temp, p) ;
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0){return 0;}
    }	
}
int main()
{
     int value=5;
     long long n;
     cout <<"Enter the Number to check whether it is prime or not"<<endl;
     cin>>n;
     if(Miller(n,value))
             cout <<"The number is prime number "<<n<<endl;
     else
             cout<<"The number is not prime number "<<n<<endl;
     return 0;
}
