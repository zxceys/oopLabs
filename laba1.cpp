#include <stdio.h>
#include <iostream>
using namespace std;



void fillArray(int(&a)[10])
{
    for(int i{}; i < 10; i++) 
    {
        cin >> a[i];
    }
}

void printArray(int (&a)[10])
{
    cout << "Massiv = ";
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}

void swapElements(int(&a)[10]) 
{
    int index1{};
    cout << "Vedite index 1 elem = ";
    cin >> index1;
    int index2{};
    cout << "Vedite index 2 elem = ";
    cin >> index2;
    int karman{};
    karman = a[index1];
    a[index1] = a[index2];
    a[index2] = karman;
    cout << endl;
    
}
void multiplyByTwo(int(&a)[10])
{
    cout << "Massiv = ";
    for (int& x : a)
    {
       x = x * 2;
       cout << x << " ";
    }
    


}


int main()
{
    int masiv[10];
    fillArray(masiv);
    printArray(masiv);
    swapElements(masiv);
    printArray(masiv);
    multiplyByTwo(masiv);
    
    return 0;
}