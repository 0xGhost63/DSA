/*

    DIVIDE THE STRUCTURE INTO TWO PARTS (SORTED & UNSORTED)
    SORTED---> I
    UNSORTED STARTS ---> I+1
    SELECT (FIND) THE SMALLEST VALUE AND APPEND IT AT I(END OF THE SORTED ARRAY)


    TIME COMPLEXITY : O(N^2)
*/

#include <iostream>
using namespace std;

void selectionSort(int arr[],int len)
{
    cout<<"\n";

    for (int i=0;i<len;i++)
    {
        int smallestIndex=i;

        for(int j=i+1;j<len;j++)
        {
            if (arr[j]<arr[smallestIndex])
            {
                smallestIndex=j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
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
    selectionSort(arr,len);
    cout<<"\nSorted Array :";
    printArray(arr,len);

}
