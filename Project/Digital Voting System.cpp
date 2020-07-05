#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;

struct node
{
    string name;
    string NID;
    string DoB;
    string fathers_name;
    string mothers_name;

    string name1;
    string NID1;
    string DoB1;
    string fathers_name1;
    string mothers_name1;

    string candidate;
    struct node *next;
};
struct node *head=NULL, *curr,  *tail, *temp, *temp1;
struct node *head2=NULL, *curr2, *tail2, *temp_a, *temp_a2;
int votecount=0;
int totalsize=21;
/// ----------- FILE USE ------------
void ins1()
{
    system("cls");
    string i,n,d,f,m;
    fstream infile;
    infile.open("new.txt", ios::in);
    while(infile.eof()==false)
    {
        for(int in=0; in<21; in++)
        {
            getline(infile, i);
            getline(infile, n);
            getline(infile, d);
            getline(infile, f);
            getline(infile, m);
                curr2=new node;
                curr2->name1=n;
                curr2->NID1=i;
                curr2->DoB1=d;
                curr2->fathers_name1=f;
                curr2->mothers_name1=m;
                curr2->next=NULL;
                if(head2==NULL)
                {
                    head2=curr2;
                    tail2=curr2;
                }
                else
                {
                    tail2->next=curr2;
                    tail2=curr2;
                }

        }
    }
    infile.close();
}
///----------------------- Voter List
 void voterlist()
 {
     system("cls");
     int i=0;
    curr2=head2;
    while(curr2!=NULL)
    {
        cout<<"\t [ "<<i+1<<" ] "<<endl;
        cout<<"\t Name : "<<curr2->name1<<endl;
        cout<<"\t NID : "<<curr2->NID1<<endl;
        cout<<"\t Date of Birth : "<<curr2->DoB1<<endl;
        cout<<"\t Father's Name : "<<curr2->fathers_name1<<endl;
        cout<<"\t Mother's Name : "<<curr2->mothers_name1<<endl;
        cout<<endl<<endl;
        curr2=curr2->next;
        i++;
    }
    cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl;
 }
 ///--------- ----------INSERTION


void insert_voter()
{
    string id;
    system("cls");
    cout<<endl;
    Sleep(300);
    cout<<"\t\t\t\t[][][][][][][][][][][][][][][[][][][][]"<<endl;
    cout<<"\t\t\t\t\t ENTER YOUR INFORMATION "<<endl;
    cout<<"\t\t\t\t[][][][][][][][][][][][][][][[][][][][]"<<endl<<endl<<endl;
    Sleep(300);
    cout<<"\t\t\t\tENTER YOUR NATIONAL ID NUMBER   "<<endl<<endl;
    cout<<"\t\t\t\t";
    cin>>id;
    temp_a=head2;
        while(temp_a!=NULL)
        {
            if(temp_a->NID1==id)
            {
                curr=new node;
                curr->NID=id;
                curr->name=temp_a->name1;
                curr->DoB=temp_a->DoB1;
                curr->fathers_name=temp_a->fathers_name1;
                curr->mothers_name=temp_a->mothers_name;
                cout<<endl<<endl;
                Sleep(200);
                cout<<"\t\t\t\t NID NUMBER : "<<temp_a->NID1<<endl;
                cout<<"\t\t\t\t NAME : "<<temp_a->name1<<endl;
                cout<<"\t\t\t\t DATE OF BIRTH : "<<temp_a->DoB1<<endl;
                cout<<"\t\t\t\t FATHER'S NAME : "<<temp_a->fathers_name1<<endl;
                cout<<"\t\t\t\t MOTHER'S NAME : "<<temp_a->mothers_name1<<endl;

                cout<<endl<<endl<<endl<<endl;
                Sleep(500);

                cout<<"\t\t\t\t  *** LIST OF CANDIDATES***       "<<endl<<endl<<endl;

                cout<<"\t\t\t\tNAME\t\t\t\t\t\t SYMBOL         "<<endl<<endl;
                cout<<"\t\t\t\t1. DONAL DUCK\t\t\t\t\t DOEL        "<<endl<<endl;
                cout<<"\t\t\t\t2. MICKEY MOUSE \t\t\t\t TIGER         "<<endl<<endl;
                cout<<"\t\t\t\t2. TOM & JERRY \t\t\t\t\t ROSE        "<<endl<<endl;
                cout<<"\t\t\t\t PLEASE WRITE SYMBOLE NAME TO VOTE"<<endl<<endl;
                cout<<"\t\t\t\t";
                cin>>curr->candidate;
                curr->next=NULL;
                if(head==NULL)
                {
                    head=curr;
                    tail=curr;
                }
                else
                {
                    tail->next=curr;
                    tail=curr;
                }
                votecount++;
            }

            temp_a=temp_a->next;
        }
    }

///-------- DISPLAY

void show()
{
    Sleep(300);
    system("cls");
    cout<<"\t\t\t\t\t\t\t\t ADMIN PANNEL"<<endl;
    cout<<endl<<endl;
    int i=0;
    curr=head;
    while(curr!=NULL)
    {
        Sleep(300);
        cout<<endl;
        cout<<"\t [ "<<i+1<<" ] "<<endl;
        cout<<"\t Name : "<<curr->name<<endl;
        cout<<"\t NID : "<<curr->NID<<endl;
        cout<<"\t Date of Birth : "<<curr->DoB<<endl;
        cout<<"\t Father's Name : "<<curr->fathers_name<<endl;
        cout<<"\t Mother's Name : "<<curr->mothers_name<<endl;
        cout<<"\t Candidate Choose : "<<curr->candidate<<endl;
        curr=curr->next;
        i++;
    }
    cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK"<<endl<<endl;
}

///------Winner-------

void winner()
{
    Sleep(500);
    system("cls");
    cout<<"\t\t\t\t\t\t\t\t ADMIN PANNEL"<<endl;
    int doel=0, tiger=0, rose=0;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->candidate=="DOEL"||temp->candidate=="doel")
        {
            doel++;
        }
        if(temp->candidate=="TIGER"||temp->candidate=="tiger")
        {
            tiger++;
        }
        if(temp->candidate=="ROSE"||temp->candidate=="rose")
        {
            rose++;
        }
        temp=temp->next;
    }
   cout<<endl<<endl<<endl<<endl;
   cout<<"\t\t\t DOEL GOT ---  [ "<<doel<<" ] VOTE "<<endl<<endl;
   cout<<"\t\t\t TIGER GOT --- [ "<<tiger<<" ] VOTE "<<endl<<endl;
   cout<<"\t\t\t ROSE GOT ---  [ "<<rose<<" ] VOTE "<<endl<<endl;

    if(doel>tiger&&doel>rose)
    {
        cout<<endl<<endl<<"\t\t\t\tWINNER IS DOEL AND GOT [ "<<doel<<" ] VOTE "<<endl;
    }
    if(tiger>doel&&tiger>rose)
    {
        cout<<endl<<endl<<"\t\t\t\tWINNER IS TIGER  GOT [ "<<tiger<<" ] VOTE "<<endl;
    }
    if(rose>tiger&&rose>doel)
    {
        cout<<endl<<endl<<"\t\t\t\tWINNER IS ROSE GOT [ "<<rose<<" ] VOTE "<<endl;
    }
    cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl<<endl;
}

void current_winner()
{
    Sleep(500);
    system("cls");
    cout<<"\t\t\t\t\t\t\t\t CURRENT WINNER"<<endl;
     int doel=0, tiger=0, rose=0;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->candidate=="DOEL"||temp->candidate=="doel")
        {
            doel++;
        }
        if(temp->candidate=="TIGER"||temp->candidate=="tiger")
        {
            tiger++;
        }
        if(temp->candidate=="ROSE"||temp->candidate=="rose")
        {
            rose++;
        }
        temp=temp->next;
    }
      if(doel>tiger&&doel>rose)
    {
        cout<<endl<<endl<<"\t\t\t\t CURRENT WINNER IS DOEL "<<endl;
    }
    if(tiger>doel&&tiger>rose)
    {
        cout<<endl<<endl<<"\t\t\t\t CURRENT WINNER IS TIGER "<<endl;
    }
    if(rose>tiger&&rose>doel)
    {
        cout<<endl<<endl<<"\t\t\t\t CURRENT WINNER IS ROSE "<<endl;
    }
    cout<<endl<<endl<<"\t\t\t\t PRESS ENTER TO BACK "<<endl;
}
///------ DELETE------------
void delete_voter()
{
    Sleep(500);
    system("cls");
    cout<<"\t\t\t\t\t\t\t\t ADMIN PANNEL"<<endl;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t ENTER VOTER NID NUMBER TO DELETE VOTER "<<endl;
    string id;
    cout<<"\t\t\t\t";
    cin>>id;
    temp_a=head2;
    if(temp_a->NID1==id)
    {
        cout<<"\t\t\t\t Name : "<<temp_a->name1<<endl;
        cout<<"\t\t\t\t Father's Name : "<<temp_a->fathers_name1<<endl;
        cout<<"\t\t\t\t Mother's Name : "<<temp_a->mothers_name1<<endl;
        cout<<endl<<endl;
        temp_a2=head2;
        head2=temp_a2->next;
        free(temp_a2);
        totalsize--;
    }
   else
   {
        while(temp_a->NID1!=id)
        {
                temp_a2=temp_a;
                temp_a=temp_a->next;
        }
        temp_a2->next=temp_a->next;
        cout<<"\t\t\t\t Name : "<<temp_a->name1<<endl;
        cout<<"\t\t\t\t Father's Name : "<<temp_a->fathers_name1<<endl;
        cout<<"\t\t\t\t Mother's Name : "<<temp_a->mothers_name1<<endl;
        cout<<endl<<endl;
        free(temp_a);
        totalsize--;
   }
   Sleep(200);
    cout<<"\t\t\t\t VOTER DELETED . . . . . . . . . . .  "<<endl;
}

///----------VOTE CAST --------
void vote_cast()
{
    Sleep(200);
    system("cls");
    cout<<"\t\t\t\t\t\t\t\t ADMIN PANNEL"<<endl;
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t TOTAL VOTE : [ "<<votecount<<" ] "<<endl<<endl;
    float cast= (votecount*100)/totalsize;
    cout<<endl<<endl;
    cout<<"\t\t\t\t VOTE CAST : [ "<<cast<<"% ] "<<endl<<endl;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t PRESS ENTER TO BACK "<<endl<<endl;
}

///-------- ADMIN PANNEL---------
void admin()
{
    Sleep(300);
    system("cls");
    cout<<"\t\t\t\t\t\t\t\t ADMIN PANNEL"<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t ENTER PASSWORD TO ENTER ADMIN PANNEL "<<endl<<endl<<endl;
    string password;
    cout<<"\t\t\t\t\t";
    cin>>password;
    if(password=="admin1234")
    {
        while(1)
        {
            Sleep(300);
            system("cls");
            cout<<"\t\t\t\t\t\t\t\t ADMIN PANNEL"<<endl;
            cout<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t [1] PRESS ONE (1) TO SHOW ALL LIST (WITH CANDIDATE SELECTION)"<<endl<<endl;
            cout<<"\t\t\t\t [2] PRESS TWO (2) TO SHOW RESULT AND WINNER "<<endl<<endl;
            cout<<"\t\t\t\t [3] PRESS THREE (3) TO SHOW ALL VOTER LIST "<<endl<<endl;
            cout<<"\t\t\t\t [4] PRESS FOUR (4) TO DELETE A VOTER FROM VOTER LIST "<<endl<<endl;
            cout<<"\t\t\t\t [5] PRESS FIVE (5) TO SEE VOTE CAST "<<endl<<endl;
            cout<<"\t\t\t\t [6] PRESS SIX (6) TO  EXIT ADMIN PANNEL "<<endl<<endl;

            int n;
            cout<<"\t\t\t\t ENTER YOUR CHOICE : ";
            cin>>n;
            if(n==1)
            {
                show();
                getch();
            }
            if(n==2)
            {
                winner();
                getch();
            }
            if(n==4)
            {
                delete_voter();
                getch();
            }
            if(n==5)
            {
                vote_cast();
                getch();
            }
            if(n==3)
            {
                voterlist();
                getch();
            }
            if(n==6)
            {
                break;
            }
        }
    }
    else
    {
        Sleep(100);
        cout<<endl<<endl<<"\t\t\t WRONG PASSWORD"<<endl;
    }
    cout<<endl<<endl<<"\t\t\t PRESS ENTER TO BACK "<<endl;
}

int exit_program(string password)
{
    Sleep(200);
    system("cls");
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t ENTER PASWORD TO EXIT "<<endl<<endl;
    cout<<"\t\t\t\t ";
    string pass;
    cin>>pass;
    if(pass==password)
    {
        return 1;
    }
    else
    {
        cout<<"\t\t\t WRONG PASSWORD "<<endl;
        return 0;
    }
}

///------ HOME PAGE
void home_page()
{
    while(1)
    {
        Sleep(100);
        system("cls");
        system("color B");
        cout<<endl;
        Sleep(100);
        cout<<"\t\t\t\t [][][][][][][][][][][][][][][][][][] "<<endl;
        cout<<"\t\t\t\t [][][][][][][][][][][][][][][][][][] "<<endl;
        cout<<"\t\t\t\t\t Digital Voting System "<<endl;
        cout<<"\t\t\t\t [][][][][][][][][][][][][][][][][][] "<<endl;
        cout<<"\t\t\t\t [][][][][][][][][][][][][][][][][][] "<<endl<<endl<<endl;
        Sleep(300);
        cout<<"\t\t\t\t [1] PRESS ONE (1) FOR VOTE"<<endl<<endl;
        Sleep(10);
        cout<<"\t\t\t\t [2] PRESS TWO (2) FOR ADMIN LOGIN (PASSWORD REQUIRED) "<<endl<<endl;
        Sleep(10);
        cout<<"\t\t\t\t [3] PRESS THREE (3) TO SEE CURRENT WINNER"<<endl<<endl;
        Sleep(10);
        cout<<"\t\t\t\t [4] PRESS FOUR (4) TO EXIT THE PROGRAM"<<endl<<endl;
        int choice;
        Sleep(10);
        cout<<endl<<"\t\t\t\t CHOSE YOUR OPTION : ";
        cin>>choice;
        if(choice==1)
        {
            insert_voter();
            cout<<endl;
            cout<<"\t\t\t\t\tPRESS ENTER TO SAVE "<<endl;

            getch();
        }
        if(choice==2)
        {
            admin();
            getch();
        }
        if(choice==3)
        {
            current_winner();
            getch();
        }
        if(choice==4)
        {
            int r= exit_program("admin1234");
            if(r==1)
            {
                system("cls");
                cout<<"\n\n\n\t\t\t Programmer";
                cout<<"\n\t\t\t _________________";
                cout<<"\n\n\t\t\t Tarikul Islam Zihad, EWU";
                cout<<"\n\t\t\t Ahosan Habib Moon, EWU";
                cout<<"\n\t\t\t CSE 207(Data Structure)";
                cout<<"\n\t\t\t Instructor: Tanni Mittra(Senior Lecturer, EWU)";
                cout<<"\n\t\t\t Date: 04-04-18\n";

                break;
            }
            if(r==0)
            {
                cout<< "\t\t\t PRESS ENTER TO BACK "<<endl<<endl;
                getch();
                continue;
            }
            getch();
        }
        if(choice==5)
        {
            ins1();
            getch();
        }
    }
}



int main()
{
    ins1();
    home_page();
}

