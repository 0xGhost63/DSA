#include <iostream>
using namespace std;
int main ()
{

    int col,rows;
    cout<<"Enter the desired number of rows for the 2-D Array : ";
    cin>>rows;
    cout<<"Enter the desired number of coloumns for the 2-D Array : ";
    cin>>col;

    int arr [rows][col];

    cout<<"Enter the data of the  2-D array : ";

    for (int i = 0 ; i<rows ;i++)
    {
        for (int j=0 ;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"Data that you entered for the array is  : "<<endl;
    for (int i = 0 ; i<rows ;i++)
    {
        for (int j=0 ;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    int transpose_array [col][rows];

    for (int i = 0;i<col;i++)
    {

        for (int j =0;j<rows;j++)
        {
                transpose_array[i][j]=arr[j][i];
        }
    }
    cout<<"Transpose of the array is  : "<<endl;
    for (int i = 0 ; i<col ;i++)
    {
        for (int j=0 ;j<rows;j++)
        {
            cout<<transpose_array[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;


}
