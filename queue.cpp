#include<iostream>
using namespace std;

struct node
{
    string student ;
    struct node* next;
};


class Queue
{
    private:
    struct node* head;
    struct node* rare;
    public:
    Queue()
    {
        head = NULL;
        rare = NULL;
    }
   bool  isEmpty()
   {
    if(head == NULL)
    {
      return true;
    }
    else
    return false;
   }
    void Enqueue( string name)
    {
      struct node* stu = new node();
      stu ->student = name;
     
     

      if(head == NULL)
      {
        head = rare = stu;
        stu->next = rare ;
        rare -> next = head;
        
      }
      
      else
      {
        struct node* temp = getLastRecord(head);
        temp ->next = stu;
        rare = stu;

      }
      
     
    }

    string Dequeue()
    {
        if(isEmpty())
        {
            return "Empty";
        }
        if( head == rare )
        {
             struct node* temp = head;
            head = rare = NULL;
            return temp->student;

        }
        struct node* temp = head;
        head = head ->next;
        
        return temp->student;

    }

   struct node* getLastRecord( struct node* temp)
   {
    if( temp == rare )
    {
        return temp;
    }
    while ( temp != rare)
    {
        temp = temp->next;
        
    }

    return temp;
   }

   void showData()
   {
    struct node* temp = head;
    if(head == NULL)
    {
        cout << " Empty" << endl;
    }
    else if( head == rare )
      {
        cout<< head -> student << endl ;
      }
      else
      {
        while ( temp != rare)
        {
           
           cout<< temp-> student << endl;
            temp = temp -> next;
            
        }
        cout<< temp->student << endl;
      }
   }


};


int main()

{
    int opt;
    Queue q;
    while(true)
    {

    cout <<"1. Enqueue " << endl;
    cout <<"2. Dequeue " << endl;
    cout<< "3. Show all " << endl;
    cin>>opt;
    system("cls");
    if( opt == 1)
    {
        cout<<" enter student name" <<endl;
        string name;
        cin>>name;
        q.Enqueue( name );

    }
    else if( opt == 2)
    {
      string data =  q.Dequeue();
      cout << data << endl;
    }
    else if( opt == 3)
    {
        q.showData();
    }

    }
    

}