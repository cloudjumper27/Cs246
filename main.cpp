/* 
 * File:   main.cpp
 * Author: KPINTO
 *
 * Created on March 24, 2015, 5:36 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void fill_array(int arr[], int n);
int main() 
{
    int n;
    
    cout<<"What size do you want your dynamic array enter a size 2 or greater.\n";
    cin>>n;
    if(n==1|n<1)
    {
        cout<<"Imposible size please try again.\n";
        cin>>n;
    }
       int *p1;
    p1 = new int[n];
    fill_array(p1, n);
       for(int i=0;i<n;i++)
   {
       cout<<p1[i]<<"\n";
   }
  
    return 0;
}

void fill_array(int arr[], int n)
{

   
   for(int j=0;j<n;j++)
   {
       arr[j]=j;
   }
   

}