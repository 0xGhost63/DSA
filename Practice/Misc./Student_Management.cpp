//In this code im practicing and revising the concepts of the OOP,File Handling and the vectors
//Incomplete !!!

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
            out<<"----------------------------------------------\n";
            out<<"Name : "<< this->name << "\n";
            out<<"CGPA : "<<this->cgpa<<"\n";
            out<<"ID : "<< this->id<< "\n";
            out<< "Subjects Enrolled : ";
            for (const string& s : subjects)
            {
                out << s << " ";
            }
            out<<endl;
            out<<"----------------------------------------------\n";
            return out.str();

        }

    private:
        float cgpa;

};
int Student::number_of_students = 0;

vector <string> initialize()
{
    //retreiving the storen 'Number' of students
    int total_students=0;
    string number = "Number_Of_Students.txt";
    ifstream numberFile(number);

    if(!numberFile)
    {
        cout<<"Error accessing the file : "<<number;
        cout<<"Please create a new txt file by the name of the : "<<number;
        return {};
    }
    while(!(numberFile.eof()))
    {
        numberFile>>total_students;
    }
    Student::number_of_students=total_students;

    numberFile.close();

    //retrieving the stored data
    vector <string> stored_students;
    string filename="Students_Data.txt";
    ifstream dataFile(filename);
    if(!dataFile)
    {
        cout<<"Error accessing the file : "<<filename;
        cout<<"Please create a new txt file by the name of the : "<<filename;
        return{};
    }
    string line;
    while(getline(dataFile, line))
    {
        string studentData = line + "\n";   // first line of the student
        while(line != "----------------------------------------------" && getline(dataFile, line))
        {
            studentData += line + "\n";
        }
        stored_students.push_back(studentData);
    }


    cout<<"Initialzing Done ! \n";
    
    return  stored_students;

}
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
    string datafile="Students_Data.txt";
    ofstream dataFile (datafile,ios::app);
    if(! dataFile )
    {
        cout<<"Error accessing the file : " << datafile;
        return;
    }
    for (const string& student : students)
    {
        dataFile << student;
        cout<<"Backing up !...\r";
    }

    dataFile.close();

    string number = "Number_Of_Students.txt";
    ofstream numberFile (number);
    if(!numberFile)
    {
        cout<<"Error accessing the file : " << datafile;
        return;
    }
    else
    {
        numberFile<<Student::number_of_students;
    }
    numberFile.close();
}
int main ()
{
    int choice=63;
    vector <string> students ;
    vector <string> total_students=initialize();
    vector <string> database;
    for (int i =0 ; i<students.size();i++)
    {
        database.push_back(students[i]);
    }
    for (int i =0 ;i< total_students.size();i++)
    {   
        database.push_back(total_students[i]);
    }

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
                string data=s.toString();
                students.push_back(data);
                database.push_back(data);   

            }

                cout<<"Succesfully added the student !\n";
                break;
            
            case 2 :
                {
                    int option1=0;
                    cout<<"1-Search by ID\n";
                    cout<<"2-Search by Name\n";
                    cout<<"Choose an option : ";
                    cin>>option1;

                    if (option1==1)
                    {
                        string id;
                        cout<<"Enter the Student's ID : ";
                        cin>>id;
                        bool isFound=false;

                        for (const string& student : database)
                        {
                            if(student.find(id) != string::npos)
                            {
                                isFound=true;
                                cout<<"Found Student : \n";
                                cout<<student;
                                cout<<"\n";
                            }
                        }
                        if(!isFound)
                        {
                            cout<<"No student found of the ID : "<<id<<" :(\n";   
                        }

                    }
                    else if (option1== 2)
                    {
                        string name;
                        cout<<"Enter the Student's Name : ";
                        cin.ignore();
                        getline(cin,name);
                        bool isFound=false;

                        for (const string& student : database)
                        {
                            if(student.find(name) != string::npos)
                            {
                                isFound=true;
                                cout<<"Found Student : \n";
                                cout<<student;
                                cout<<"\n";
                            }

                        }
                        if(!isFound)
                        {
                            cout<<"No student found of the ID : "<<name<<" :(\n";   
                        }

                    }
                    else
                    {
                        cout<<"Choose a valid option plz :)";
                    }
                }


                break;

            case 3 : 
                int option2;
                cout<<"1-Review the Students added in this session .\n";
                cout<<"2-Review all Students\n";
                cout<<"Choose an option : ";
                cin>>option2;
                if(option2==1)
                {
                    cout<<"=================STUDENTS ADDED IN THIS SESSION=================\n";
                    for (string s : students)
                    {
                        cout<<s;
                    }
                    cout<<"================================================================\n";
                }
                else if (option2==2)
                {
                    cout<<"=================TOTAL STUDENTS ADDED THROUGHOUT THE SESSIONS=================\n";
                    for (string s : database)
                    {
                        cout<<s;
                    }
                    cout<<"==============================================================================\n";
                }
                else
                {
                    cout<<"Choose a valid option :)\n";
                    break;
                }

                

                break;
            case 4 :
                backup(students);
                cout<<"Back-up done !";
                break;

            case 5 :
                cout<<"Total Students : "<<Student::number_of_students<<endl;
                break;

            case 0 :
                backup(students);
                cout<<"The data has been backed-up to the Students_Data.txt\n";
                cout<<"Thank you for using the program !\n";
                break;

            default : 
                cout<<"Please Enter a valid choice !\n";
                break;

                
                



        }
    }
}
