#include <stdio.h>
#include <iostream>
using namespace std;



/*void fillArray(int(&a)[10])
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
    cout << "Massiv =";
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
}*/



#include <iostream>

using namespace std;

void process(int*& arr, int& size)
{
    for (int i{}; i < size; i++)
    {
        if (arr[i] < 0)
        {
            int* arr1 = new int[i]{};

            for (int d{}; d < i; d++)
            {
                arr1[d] = arr[d];
            }

            delete[] arr;
            arr = arr1;

            size = i;

            break;
        }
    }
}

void printArray(int* arr, int size)
{
    cout << "Massiv = ";

    for (int i{}; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Vedite razmer masiva = ";
    cin >> n;

    int* arr = new int[n]{};

    cout << "Vedite elementi masiva: ";

    for (int i{}; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Do process: ";
    printArray(arr, n);

    process(arr, n);

    cout << "Posle process: ";
    printArray(arr, n);

    delete[] arr;
    arr = nullptr;

    return 0;
}
