/*
    BUBBLE SORT'S EACH ITERATION PUSHES THE LARGEST ELEMENT TO THE TOP 
    & HENCE THE NAME BUBBLE SORT.

    USES THE N-1 ITERATIONS AND COMAPRES THE ADJACENT ELEMENTS
    O(N^2) ---> TIME COMPLEXITY
*/

#include <iostream>
#include <iterator>
using namespace std;

void bubbleSort(int arr[],int len)
{
    cout<<"\n";
    for (int i =0;i<len-1;i++)
    {
        bool swapped=false;//Optimization to check if the array is already sorted or not
        cout<<"Iteration # "<<i+1<<" : \n";

        for (int j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                cout<<"Swapping "<<arr[j]<<" with "<<arr[j+1]<<" \n";
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
            else
            {
                cout<<"No swap needed for the "<<arr[j]<<" & "<<arr[j+1]<<endl;
            }
        }
        if(!swapped)
        {
            break;//If no swapping is done in an iteration...it means the array is already sorted
        }

        
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
    bubbleSort(arr,len);
    cout<<"\nSorted Array :";
    printArray(arr,len);

}