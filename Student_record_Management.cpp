#include<bits/stdc++.h>
using namespace std;
class studentnode
{
    public:
    int Id;
    string Name;
    double gpa;
    long long int ph;
    studentnode* next;
    public:
    studentnode(int Id1, string Name1, double gpa1, long long int ph1, studentnode* next1)
    {
        Id = Id1;
        Name = Name1;
        gpa = gpa1;
        ph = ph1;
        next = next1;
    }
    studentnode(int Id1, string Name1, double gpa1, long long int ph1)
    {
        Id = Id1;
        Name = Name1;
        gpa = gpa1;
        ph = ph1;
        next = nullptr;
    }
};

studentnode* insertion(int Id, string Name, double gpa, long long int ph, studentnode* head)       //inserting data into LL
{
    studentnode* newnode = new studentnode(Id,Name,gpa,ph);
    if(head==NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        studentnode* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void display(studentnode* head)             //displaying data of students
{
    studentnode* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->Id<<" "<<temp->Name<<" "<<temp->gpa<<" "<<temp->ph<<endl;
        cout<<endl;
        temp=temp->next;
    }
}

void check(string name,studentnode* head)       //checking the data wrt to name
{
    studentnode* temp = head;
    while(temp!=NULL)
    {
        if(temp->Name == name){
            cout<<temp->Id<<" "<<temp->Name<<" "<<temp->gpa<<" "<<temp->ph<<endl;
            cout<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Student of name : "<<name<<" not found"<<endl;
    cout<<endl;
}

void check(int id,studentnode* head)        //checking the data wrt to Id
{
    studentnode* temp = head;
    while(temp!=NULL)
    {
        if(temp->Id == id){
            cout<<temp->Id<<" "<<temp->Name<<" "<<temp->gpa<<" "<<temp->ph<<endl;
            cout<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Student of Id : "<<id<<" not found"<<endl;
    cout<<endl;
}

void check(long long int phn,studentnode* head)         //checking the data wrt to phone number
{
    studentnode* temp = head;
    while(temp!=NULL)
    {
        if(temp->ph == phn){
            cout<<temp->Id<<" "<<temp->Name<<" "<<temp->gpa<<" "<<temp->ph<<endl;
            cout<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Student of phone number : "<<phn<<" not found"<<endl;
    cout<<endl;
}

studentnode* Delete(int id, studentnode* head)      //deleting the data wrt to Id
{
    if(head==NULL)
        return NULL;
    
    studentnode* temp = head;
    if(temp->Id == id)
    {
        //studentnode* dummy = head;
        //studentnode* temp = head;
        //dummy = dummy->next;
        head = temp->next;
        free(temp);
        cout<<"Student with "<<id<<" deleted successfully"<<endl;
        cout<<endl;
        return head;
    }
    // studentnode* temp = head;
    studentnode* prev = nullptr;
    while(temp!=NULL)
    {
        if(temp->Id == id)
        {
            prev->next = temp->next;
            free(temp);
            cout<<"Student with "<<id<<" deleted successfully"<<endl;
            cout<<endl;
            return head;
        }
        prev = temp;
        temp=temp->next;
    }
    cout<<"Student "<<id<<" is not not found"<<endl;
    return head;
}

studentnode* Delete(string name, studentnode* head)         //deleting the data wrt to name
{
    if(head==NULL)
        return NULL;
    if(head->Name == name)
    {
        studentnode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    studentnode* temp = head;
    studentnode* prev = nullptr;
    while(temp!=NULL)
    {
        if(temp->Name == name)
        {
            prev->next = temp->next;
            free(temp);
            cout<<"Student with "<<name<<" Deleted successfully"<<endl;
            cout<<endl;
            return head;
        }
        prev = temp;
        temp=temp->next;
    }
    cout<<"Student "<<name<<" not found"<<endl;
    cout<<endl;
    return head;
}

studentnode* Delete(long long int phn, studentnode* head)       //deleting the data wrt to phone number
{
    if(head==NULL)
        return NULL;
    if(head->ph == phn)
    {
        studentnode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    studentnode* temp = head;
    studentnode* prev = nullptr;
    while(temp!=NULL)
    {
        if(temp->ph == phn)
        {
            prev->next = temp->next;
            free(temp);
            cout<<"Student with phone number "<<phn<<" Deleted successfully"<<endl;
            cout<<endl;
            return head;
        }
        prev = temp;
        temp=temp->next;
    }
    cout<<"Student with phone number "<<phn<<" not found"<<endl;
    cout<<endl;
    return head;
}

int main()
{
    studentnode* head = new studentnode(1, "Avinash", 9.3, 7731987063);
    head->next = NULL;
    cout<<endl;
    insertion(2,"Raju",9.2,9949441768,head);
    insertion(3,"Shyam",8.3,7730996630,head);
    insertion(4,"Krishn",7.6,9059068500,head);
    insertion(5,"Radha",6.4,9490780064,head);
    insertion(6,"Arjun",8.2,7036936550,head);
    insertion(7,"Bishma",7.6,9490780064,head);
    insertion(8,"Bheem",7.5,9347076925,head);
    insertion(9,"Nakul",6.9,9059012963,head);
    insertion(10,"Sahadev",7.3,6281235274,head);
    insertion(11,"Ashvathama",9.8,9156010704,head);
    insertion(12,"Kishore",9.4,9989119075,head);
    insertion(13,"Abhimanyu",6.7,9390737183,head);
    insertion(14,"Ekalavya",7.3,9948843108,head);
    insertion(15,"Karn",6.7,7075545700,head);
    insertion(16,"Saathwik",5.3,9912243703,head);
    insertion(17,"Yudhistir",8.4,6303025306,head);
    // check(6,head);
    // check("k",head);
    // check(7731987065,head);
    while(1)
    {
        cout<<"1. Search"<<endl;
        cout<<"2. Display Records"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<endl;
        int ch;
        cout<<"Enter your choice :- ";
        cin>>ch;
        
        if(ch==1)
        {   
            cout<<endl;
            cout<<"Choose searching method"<<endl;
            cout<<endl;
            cout<<"1. Search by Id"<<endl;
            cout<<"2. Search by Name"<<endl;
            cout<<"3. Search by phone number"<<endl;
            int n;
            cin>>n;
            switch(n)
            {
                case 1: 
                {
                    int id;
                    cout<<"Enter Id : - ";
                    cin>>id;
                    cout<<endl;
                    check(id,head);
                    break;
                }
                case 2: 
                {
                    string name;
                    cout<<"Enter  name : - ";
                    cin>>name;
                    cout<<endl;
                    check(name,head);
                    break;
                }
                case 3: 
                {
                    long long int phn;
                    cout<<"Enter phone number :- ";
                    cin>>phn;
                    cout<<endl;
                    check(phn,head);
                    break;
                }
                default: cout<<"Choose name/id/phn"<<endl;
            }
        }
        else if(ch==2)
        {
            display(head);
        }
        else if(ch==3)
        {
            cout<<endl;
            cout<<"Choose delete option "<<endl;
            cout<<endl;
            cout<<"1. Delete by id"<<endl;
            cout<<"2. Delete by name"<<endl;
            cout<<"3. Delete by phone number"<<endl;
            int ch;
            cout<<"Enter your choice :- ";
            cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    int id;
                    cout<<"Enter id to be deleted :- ";
                    cin>>id;
                     cout<<endl;
                    Delete(id,head);
                    break;
                }
                case 2:
                {
                    string name;
                    cout<<"Enter name to be deleted :- ";
                    cin>>name;
                     cout<<endl;
                    Delete(name,head);
                    break;
                }
                case 3:
                {
                    long long int phn;
                    cout<<"Enter phone number to be deleted :- ";
                    cin>>phn;
                     cout<<endl;
                    Delete(phn,head);
                    break;
                }
                default: cout<<"Choose name/id/phn"<<endl;
            }
        }
        else if(ch==4)
        {
            break;
        }
    }
    cout<<endl;
}