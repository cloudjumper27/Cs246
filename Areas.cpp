#include <iostream>
using namespace std;

void circle ();
void trapeziod ();
void triangle ();

int main ()
{
    int num;
    
    cout<<" What area are you trying to find for which shape? "<<endl;
    
    cout<<" Enter 1 for circle or 2 for trapeziod or 3 for triangle. "<<endl;
    
    cout<<"\n";
    
    cin>>num;
    
    switch (num)
      {
        case 1:
             {
             circle ();
             break;
             }
        case 2:
             {
             trapeziod ();
             break;
             }
        case 3:
             {
             triangle ();
             break;
             }
        default:
                {
                cout<<" Please try again\n";
                cin>>num; 
                } 
        }             
}
    system ("pause");
    return 0;
}

void circle ()
{
     double pi=3.14,area;
     int radius;
     
     cout<<" Enter radius \n";
     cin>>radius;
     
     area=pi*radius*radius;
     
     cout<<" The area the circle is \n";
     area;
}

void trapeziod ()
{
     int base1,base2,height;
     double area;
     
     cout<<" Enter base1 \n";
     cin>>base1;
     
     cout<<" Enter base2 \n ";
     cin>>base2;
     
     cout<<" Enter height \n";
     cin>>height;
     
     area=((base1+base2)/2)*height;
     
     cout<<" The area of the trapezoid \n";
     area;   
}

void triangle ()
{
   int base,height;
   double area;
   
   cout<<" Enter base \n";
   cin>>base;
   
   cout<<" Enter height \n";
   cin>>height;
   
   area=((base*height)/2);
   
   cout<<" The area of the triangle \n";
   area;
}   
