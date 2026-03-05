#include <iostream>
using namespace std;
int main()
{
    int arr[2][2];
    int arr1[2][2];
    int result[2][2] = {0};
    cout<<"Enter the data of the first 2x2 matrix:\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<"Enter the data of the second 2x2 matrix:\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += arr[i][k] * arr1[k][j];
            }
        }
    }
    cout << "Product Matrix:\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
