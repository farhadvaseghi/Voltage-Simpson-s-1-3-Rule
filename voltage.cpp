
#include<iostream>
#include<math.h>


using namespace std;

float current(float t)
{   
    return pow((60-t),2)+(60-t)*sin(sqrt(t));
}
float resistance(float i)
{ 
    return 0.01*i+2*pow(i,2/3);
}
float simpsons(float a, float b, int c)
{
    
    float h=(b-a)/c;
    float result=0;
    float x[1000], y[1000];
    for(int i=0; i<=c; i++)
    {
        x[i]= a+i*h;
        y[i]= current(x[i]);
    }

    for(int i=0; i<=c; i++)
    {
        if(i==0||i==c)
            result += y[i];
        else if(i%2!=0)
            result += 4*y[i];
        else
            result += 2*y[i];
        
    }
    result = result * (h / 3);
    return result;
}
int main()
{  
    float lower_limit, upper_limit, n;
    cout<<"Please Enter Lower Limit: ";
    cin>>lower_limit;
    cout<<"Please Enter Upper Limit: ";
    cin>>upper_limit;
    cout<<"Please Enter the number of intervals: ";
    cin>>n;
    cout<<"The approximation of the Volatag is: "<< resistance(simpsons(lower_limit, upper_limit, n));
    return 0;
}