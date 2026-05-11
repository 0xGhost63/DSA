/*
    REG # SP25-BSE-118
    DATE : April 2,2026
*/

#include <iostream>
using namespace std;
#define MAX_ATTEMPTS 10 
#define WINSIZE 5
class Stack
{
    public :
    //Variable & array related to the Stack
    int top=-1;
    int arr[MAX_ATTEMPTS];
    int last_value;


    //Variables Related to the game logic
    int attempts_made=0; 
    int score = 0;
    int stack_size=0;
    bool game_over=false;
    

    //Metods of the Stack---->I modified them to meeet the requirements of the Game !
    bool isEmpty()
    {
        return top==-1;
    }

        
    //Method returning the top element of the Stack--->the element on the corner/edge of the array
    int peek ()
    {
        if (!isEmpty())
            return arr[top];
        else
        {
            return -63;
        }
    }


    //PUSHING THE VALUES TO THE STACK--->MODIFIED TO MEET THE REQUIREMENTS OF THE GAME !
    void push(int val)
    {
        if (top==MAX_ATTEMPTS-1) 
        {
            cout<<"Stack Overflow !";
        }
        else if (isEmpty())
        {
            top++;
            score+=2;
            attempts_made++;
            stack_size++;
            arr[top]=val;
            last_value=val;

        }
        else if (val<=arr[top])
        {
            top++;
            arr[top]=val;
            last_value=val;
            score+=2;
            attempts_made++;
            stack_size++;
            
        }
        else
        {
            last_value=val;
            game_over=true;
        }
    }

    //POPPING THE VALUES FROM THE STACK--->MODIFIED TO MEET THE REQUIREMENTS OF THE GAME !
    void pop()
    {
        if (isEmpty())
        {
            cout<<"Stack is empty,nothing to delete !\n";
        }
        else
        {
            //Instead of rewriting the value at the top of the stack...im just decrementing the top 
            top--;
            attempts_made++;
            score--;
            stack_size--;
        }
    }



    //METHOD TO DISPLAY THE STATE OF THE STACK etc.
    void display()
    {
        cout<<"---------------------------------------CURRENT PROGRESS-------------------------------------------------------------\n";
        cout<<"|Score : "<<score<<"|     |Attempts Made : "<<attempts_made<<"|    |Attempts Left : "<<MAX_ATTEMPTS-attempts_made<<" |"<<endl;
        if(!isEmpty())
        {
            cout<<"Plate's Stack : \n";
            for (int i=top;i>=0;i--)
            {
                if (i==top)
                    cout<<arr[i]<<"<--- TOP\n";
                else
                    cout<<arr[i]<<"\n";
            }
        }
        else
        {
            cout<<"The Stack is empty yet,nothing to display :(\n";
        }
        cout<<"--------------------------------------------------------------------------------------------------------------------\n";
    }

    //Mhod added to reset the state of the game variables for test cases run !
    void reset()
    {
        top = -1;
        attempts_made = 0;
        score = 0;
        stack_size = 0;
        game_over = false;
    }

};

//METHOD TO DISPLAY THE GAME MENU !
void menu()
{
    cout<<"=====================CHOOSE AN OPTION=====================\n";
    cout<<"0-RUN TESTS\n1-Push the Plate\n2-Pop the Plate\n3-Peek the top\n4-Display the overall Stack\n9-Exit\n";
    cout<<"==========================================================\n";

}
void testCase1_NormalWin(Stack &stack);
void testCase2_StackCollapse(Stack &stack);
void testCase3_OutOfAttempts(Stack &stack);
void testCase4_WinWithPops(Stack &stack);
void testCase5_EqualWeights(Stack &stack);
void testCase6_PeekEmptyStack(Stack &stack);
void testCase7_PopEmptyStack(Stack &stack);
void testCase8_CollapseOnFirstPush(Stack &stack);
int main()
{
    // Variables for the game loop
    Stack stack;
    int choice;
    

    //GAME LOOP !
        //Stack Collapsed    // Player won (5 plates stacked)     //Player reached max number of attempts
    while(!stack.game_over && stack.stack_size!=WINSIZE && stack.attempts_made<MAX_ATTEMPTS)
   {
        menu();
        cout<<"Enter your choice: ";
        cin>>choice;

        
        switch(choice)
        {
            case 1:
                int val;
                cout<<"Enter weight of the plate to be pushed : ";
                cin>>val;
                stack.push(val);
                if (!stack.game_over)
                    stack.display();
                break;
            case 2:
                stack.pop();
                stack.display();
                break;
            case 3:
            {
                int top_value=stack.peek();
                if (top_value!=-63)
                    cout<<"The weight of the plate on top is : "<<top_value<<endl;
                else
                    cout<<"The stack is empty\n";
            }
                break;
            case 4:
                stack.display();
                break;
            case 0:
            {
                int testchoice;
                cout<<"1-NORMAL WIN\n2-COLLAPSE\n3-OUT OF ATTEMPTS\n4-WIN WITH POPS\n5-EQUAL WEIGHTS\n6-PEEK EMPTY STACK\n7-POP EMPTY STACK\n8-COLLAPSE ON FIRST PUSH\n";
                cout<<"CHOOSE THE TEST METHOD THAT YOU WANT TO RUN : ";
                cin>>testchoice;
                switch(testchoice)
                {
                    case 1: testCase1_NormalWin(stack);          break;
                    case 2: testCase2_StackCollapse(stack);      break;
                    case 3: testCase3_OutOfAttempts(stack);      break;
                    case 4: testCase4_WinWithPops(stack);        break;
                    case 5: testCase5_EqualWeights(stack);       break;
                    case 6: testCase6_PeekEmptyStack(stack);     break;
                    case 7: testCase7_PopEmptyStack(stack);      break;
                    case 8: testCase8_CollapseOnFirstPush(stack);break;
                    default: cout << "Invalid test case!\n";     break;
                }
                break;
            }
            case 9:
                cout<<"Thank you for playing ! :) ...\n";
                return 0;
            default:
                cout<<"Please Enter a valid choice !\n";
                break;
        }
    }
    // DIFFERENT GAME-ENDINGS BASED ON THE BOOLEANS & VARIABLE'S STATE

    //This boolean value becomes true in the case user places a heavier plate over the lighter one in the stack
    if (stack.game_over)
    {
        cout<<"Oh No ! The stack of plates shattered,Game Over :(\n";
        cout<<"The plate with weight "<<stack.last_value<<" was heavier than the "<<stack.arr[stack.top]<<" and caused the all damage !\n";
        stack.display();
    }
    //This condition becomes true in the case user stacks 5 plates successfully... 
    else if (stack.stack_size==WINSIZE)
    {
        cout<<"YOU WON,with a score of "<<stack.score<<" !!\n";
        stack.display();

    }
    //This ending will display in case the user run out of attempts 
    else if (stack.attempts_made==MAX_ATTEMPTS)
    {
        cout<<"You ran out of attempts,Better Luck Next Time !\n";
        stack.display();

    }
    
    return 0;
}

// TEST CASES METHODS BELOW !!





void testCase1_NormalWin(Stack &stack)
{
    // Push 5 plates in descending order to win
    // Expected: WIN with score = 10
    stack.reset();
    stack.push(50);
    stack.push(40);
    stack.push(30);
    stack.push(20);
    stack.push(10);
}

void testCase2_StackCollapse(Stack &stack)
{
    //Push a heavier plate on a lighter one to collapse the stack
    //Expected: GAME OVER(game_over=true)
    stack.reset();
    stack.push(30);
    stack.push(20);
    stack.push(50); 
}

void testCase3_OutOfAttempts(Stack &stack)
{
    //Keep pushing and popping to finish all 10 attempts without winning
    // Expected: OUT OF ATTEMPT
    stack.reset();
    stack.push(50); 
    stack.pop();    
    stack.push(40); 
    stack.pop();    
    stack.push(30); 
    stack.pop();    
    stack.push(20); 
    stack.pop();    
    stack.push(10); 
    stack.pop();    
}

void testCase4_WinWithPops(Stack &stack)
{
    //Push wrong plate,pop it,then recover and win
    //Expected : WIN with reduced score (pops deduct points)
    stack.reset();
    stack.push(50); 
    stack.push(30); 
    stack.pop();    
    stack.push(30); 
    stack.push(20); 
    stack.push(10); 
    stack.push(5);  
}

void testCase5_EqualWeights(Stack &stack)
{
    //Push plates of equal weight (should be allowed, val <= top)
    //Expected:- WIN with score = 1
    stack.reset();
    stack.push(20);
    stack.push(20);
    stack.push(20);
    stack.push(20);
    stack.push(20);
}

void testCase6_PeekEmptyStack(Stack &stack)
{
    // Peek on an empty stack
    // Expected: peek() returns -63 (empty sentinel)
    stack.reset();
    int result = stack.peek();
    if (result == -63)
        cout << "CORRECT : peek() on empty stack returned -63 correctly.\n";
    else
        cout << "ERROR TOOK PLACE!\n";
}

void testCase7_PopEmptyStack(Stack &stack)
{
    // Pop on an empty stack
    // Expected: prints "Stack is empty, nothing to delete!" and state unchanged
    stack.reset();
    int attempts_before = stack.attempts_made;
    int score_before = stack.score;
    stack.pop();
    if (stack.attempts_made == attempts_before && stack.score == score_before)
        cout << "PASS:pop() on empty stack did not change state.\n";
    else
        cout << "ERROR !!\n";

}

void testCase8_CollapseOnFirstPush(Stack &stack)
{
    // Only one plate pushed, then an immediately heavier one collapses it
    // Expected: GAME OVER after just 2 pushes
    stack.reset();
    stack.push(10);
    stack.push(99); 
}
