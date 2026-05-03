/*

    BASICALLY DIVIDES THE ARRAY INTO TWO HALVES...ONE IS SORTED PART
    AND THE OTHER IS UNSORTED PART

    AN ELEMENT IS PICKED FROM THE SORTED HALF(CURRENT) AND THEN THAT IS 
    COMPARED WITH THE ELEMENTS IN THE UNSORTED HALF UNTIL ITS (CURRENT'S)
    APPROPRIATE LOCATION IS FOUND !


    TIME COMPLEXITY : O(N^2)
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[],int len)
{
    cout<<"\n";

    for (int i =1;i<len;i++)
    {
        int curr = arr[i];
        int prev= i-1;

        while(prev >=0 && arr[prev]>curr)
        {
            arr [prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }

        
    
}

void printArray(int arr[],int len)
{
    for(int i =0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int len=5;
    int arr [len]={};

    for (int i =0;i<len;i++)
    {
        cout<<"Enter the element # "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"Unsorted Array : ";
    printArray(arr,len);
    insertionSort(arr,len);
    cout<<"\nSorted Array :";
    printArray(arr,len);

}
