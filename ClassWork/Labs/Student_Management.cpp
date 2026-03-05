#include <iostream>
using namespace std;

struct Student
{
    string name;
    int id;
    double cgpa;
    string sub [3];
};
 int main ()
 {


    Student arr [10];

    for (int i = 0;i<2;i++)
    {

        cout<<"Enter the name of the Student # "<<i+1<<" : ";
        cin>>arr[i].name;
        cout<<"Enter the ID of the Student # "<<i+1<<" : ";
        cin>>arr[i].id;
        cout<<"Enter the cgpa of the Student # "<<i+1<<" : ";
        cin>>arr[i].cgpa;

        for (int j =0;j<3;j++)
        {
            cout <<"Enter the Subject # "<<j+1<<" : ";
            cin>>arr[i].sub[j];
        }

    }

    //Output !!!
    for (int i = 0;i<10;i++)
    {

    if (arr[i].cgpa>=2.5)
    {
        cout<<"Name of the Student # "<<i+1<<" : ";
        cout<<arr[i].name<<endl;
        cout<<"The ID of the Student # "<<i+1<<" : ";
        cout<<arr[i].id<<endl;
        cout<<"CGPA of the Student # "<<i+1<<" : ";
        cout<<arr[i].cgpa<<endl;

        cout<<"Subjects Enrolled by the student are : ";
        for (int j =0;j<3;j++)
        {
            cout<<arr[i].sub[j]<<" ";
        }
    }
    else
    {
        cout<<"Student # "<<i+1<<" Skipped due to CGPA<2.5 !";

    }

 }

}
