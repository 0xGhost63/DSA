

void Menu()
{
    cout<<"=======================CHOOSE AN OPTION=======================\n";
    cout<<"1-Push to Front\n";
    cout<<"2-Push to Rear\n";
    cout<<"3-Push At Random Position\n";
    cout<<"0-EXIT\n";
    cout<<"Enter the Option : ";

}
int main ()
{
    LinkList list;

    int choice=1;


    while (choice!=0)
    {
        Menu();
        cin>>choice;
        if (choice==1)
        {
            int value;
            cout<<"Enter the value : ";
            cin>>value;
            list.push_to_front(value);

        }
        else if (choice==2)
        {
            int value;
            cout<<"Enter the value : ";
            cin>>value;
            list.push_to_rear(value);
        }
        else if (choice==3)
        {
            int value=0;
            int pos=0;
            cout<<"Enter the value : ";
            cin>>value;
            cout<<"Add after which value ? : ";
            cin>>pos;

            list.push_to_randomly(pos,value);

        }
        else
        {
            cout<<"Enter a valid choice !!! :)\n";
        }
    }

    return 0;
}