//In this code im practicing and revising the concepts of the OOP,File Handling and the vectors

#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Student
{
    public:
        static int number_of_students;
        string name;
        int id;
        string subjects [3] ;

        Student(string name,int id,float cgpa,string subjects [])
        {
            this->name=name;
            this->id=id;
            this->cgpa=cgpa;
            for (int i = 0;i<3;i++)
            {
                this->subjects[i]=subjects[i];
            }

            number_of_students++;
        }

        float getCgpa()
        {
            return this->cgpa;
        }
        void setCgpa(float cgpa)
        {
            this->cgpa=cgpa;
        }

        string toString()
        {
            ostringstream out;
            out << "Name : " << this->name << "\n";
            out << "CGPA : " << this->cgpa << "\n";
            out << "ID : " << this->id << "\n";
            out << "Subjects Enrolled : ";
            for (const string& s : subjects)
            {
                out << s << " ";
            }
            return out.str();

        }

    private:
        float cgpa;

};
int Student::number_of_students=0;

void printMenu()
{
    cout<<"=======================================\n";
    cout<<"1-Add a Student\n";
    cout<<"2-Access Student's Data\n";
    cout<<"3-View All Students\n";
    cout<<"4-Back-Up Data\n";
    cout<<"5-Total Number of Students\n";
    cout<<"0-EXIT\n";
    cout<<"=======================================\n";
}

void backup(vector <string> students)
{
    ofstream file ("Students_Data.txt");



}
int main ()
{
    int choice=63;
    vector <string> students ;
    while(!(choice==0))
    {
        printMenu();
        cout<<"Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
            case 1 :
            {
                string name;
                int id;
                string subjects [3] ;
                float cgpa;

                cout<<"Enter the name of the student : ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter the ID of the student : ";
                cin>> id;
                cout<<"Enter the CGPA of the student : ";
                cin>> cgpa;
                for (int i = 0 ; i<3;i++)
                {
                    cout<<"Enter the subject # "<< i+1<<" : ";
                    cin>>subjects[i];
                }
                Student s (name,id,cgpa,subjects);
                students.push_back();
                
            }

                cout<<"Succesfully added the student !\n";
                break;
            
            case 2 :
                cout <<"hi";

                break;

            case 0 :
                // backup();
                cout<<"The data has been backed-up to the Students_Data.txt\n";
                cout<<"Thank you for using the program !\n";
                break;

            default : 
                cout<<"Please Enter a valid choice !\n";
                break;

                
                



        }
    }
}