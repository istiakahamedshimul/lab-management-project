
/*A simple lab management project with c++.
Author:Istiak Ahmed Shimul
*/

#include<iostream>
#include<string>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<iomanip>
#include<conio.h>
#define MAX 100
using namespace std;
//global Declear start:
int StudnetNumber=0,i;
int DefaultStudent;  //to indicate the current student logged in the system.


//global Declear End:
class admin;      // decleared for the friend class

class Lab        // Parent class for student and admin
{

public:
    string StudentName;
    string Dept;
    int BlockedID;
    char* StartTime="EMPTY ";
    char* EndtTime="EMPTY ";
    void option();
};


class student: public Lab

{

private:
    int id;
    char s_pass[15];
public:


    int GetId();        //for geting value of id
    void SetId();      //for taking value of id
    string GetPass(); //for geting value of password
    void SetPass();  //for taking value of password
    void Register(int); //for registering a new student account
    void ParticularInformation(); //displaying particular student information
    void modify();
    friend class admin;

};

class admin: public Lab
{
private:
    char pass[15]= {"NULL"}; //Default Value
public:
    void SetPass();
    string GetPass();
    void Smodify(student &s);
    void DisplayStudentDetails(student);
    void ActiveStudentList(student);
    void Search_Student(student);

};

//Global Funcrion Declaration:


void RegValidator(student s[]);  //validating is it  Existing user or not.

int StudentCredentialCheck(student stu[],int iid,string pass); //Cheking the user credential and returning value based on  information.

void StudentPanel();  // there will be two option Register and login as well as nested function for the all fuctions belongos to students.

void StudentLoginPage();  //This function will Check the return StudentCredentialCheck and makes decison the credential right or wrong and give next step access

void StudentManue();   //Manue interface for student
void AdminManue();

void StoreStartTime(int id); //storing time  when user get logged in the system

void StoreEndTime(int idd); //storing time  when user get logged out from system

int idvalidator(int idv); //to check the inserted id is registered or  not

void StudentLogout(int id, char pass[15]);// it will use for loggin out from the system
int GetPosition(int);  //Get the stident index by id
void passcheking();  //simple animatoin to check password
//global function for admin class for making the program efficient

void AdminLogin();       // it will check pass equalt to null or not if null will go for new pass word rather will go for login.
void StudentDetails();   //Display all student list
void ActiveStudent();    //display logged in student list in lab
void SearchStudent();   //To search indivisual student information  admin class.
void StudentModify();
void BlockedStudent(); //blocked student list and action for block/unblock
// END ADMIN

student students[MAX];  // Declearing Student ojb as global  to avoid passing the obj multiple time one function to aonther
admin SystemAdmin;      // declearing admin object globally to avoid passing the obj multiple time one function to aonther

/* Start Of Main function*/

int main()
{
again:
    system("cls");
    int Choose;
    cout<<"\t\t\t=============================================================================="<<endl;
    cout<<"\t\t\t                          IUBAT PRACTICE LAB                         "<<endl;
    cout<<"\t\t\t=============================================================================="<<endl<<endl;
    cout<<"                                      1.Administrator"<<endl<<endl;
    cout<<"                                      2.Student"<<endl<<endl;
    cout<<"                                      Choose one:";
    cin>>Choose;
    if(Choose==1)
    {
        AdminLogin();
    }
    else if(Choose==2)
    {
        StudentPanel();
    }
    else
    {
        cout<<"Wrong Input"<<endl;
        goto again;
    }
}

/* End Of Main function*/


// student Sction start:


void student::SetId()
{
    cin>>id;
}

string student::GetPass()
{
    return s_pass;
}

void student::SetPass()
{
    cin>>s_pass;
}

int student::GetId()
{
    return id;
}
void student::Register(int ID)  //registering student information....
{
    id=ID;
    cout<<"Enter Your Name:";
    cin>>StudentName;
    cout<<"\nEnter Your Password:";
    cin>>s_pass;
    cout<<"\nEnter Your Department:";
    cin>>Dept;
    cout<<"\n\nSuccessfuly Created.";
    BlockedID=0;
    StudnetNumber++;
    sleep(1);
    StudentPanel();
}


void student::ParticularInformation()
{

    system("cls");
    cout<<"=============================================================================="<<endl;
    cout<<"                         STUDENT INFORMATION                       "<<endl;
    cout<<"=============================================================================="<<endl<<endl;
    cout<<"Name        :"<<StudentName<<endl<<endl;
    cout<<"ID          :"<<id<<endl<<endl;
    cout<<"Department  :"<<Dept<<endl<<endl;
    cout<<"Enter Time  :"<<StartTime<<endl<<endl;
    cout<<"End Time    :"<<EndtTime<<endl<<endl;

}
void student::modify()
{
    int ch,TempId;
    system("cls");

    while(1)
    {
        system("cls");
        cout<<setw(20)<<right<<"Modify Student Information"<<endl;
        cout<<setw(20)<<right<<"---------------------------"<<endl;

        cout<<"1.Name:\n2.Dept\n3.ID\n4.Password\n5.Back to Manue\nChoose:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"New Name :";
            cin>>StudentName;
            modify();
            break;
        case 2:
            cout<<"New Dept :";
            cin>>Dept;
            modify();
            break;
        case 3:


            cout<<"New ID :";
            cin>>TempId;
            if(idvalidator(TempId)==1)
            {
                id=TempId;
            }
            else
            {
                cout<<"This id already exist!"<<endl;
                sleep(1);
            }
            modify();
            break;
        case 4:

            cout<<"Enter Your New Password"<<endl;
            cin>>s_pass;
            modify();
        case 5:
            goto baack_manue;
            break;
        default:
            cout<<"\n\nWrong Input";
            modify();
        }
baack_manue:
        break;
    }
}
// student Sction End:


// Admin Sction start:
void admin::SetPass()
{
    cin>>pass;
}
string admin::GetPass()
{
    return pass;
}
void admin::Smodify(student &s)
{
    s.modify();
}
void admin::DisplayStudentDetails(student st)
{
    cout.setf(ios::left);
    cout<<setw(15)<<st.StudentName;
    cout<<setw(15)<<st.id;
    cout<<setw(15)<<st.Dept;
}

void admin::ActiveStudentList(student ss)
{
    cout << left << setw(12) << ss.StudentName
         << setw(10) << ss.id
         << setw(20) << ss.EndtTime
         << setw(25) << ss.StartTime; // Adjust the width as per your requirement
}

void admin::Search_Student(student stud)
{
    stud.ParticularInformation();
}
// Admin Sction End:

//Lab Sction start:


// Lab Sction End:


/*Global function Start */


void RegValidator()   //Defination
{
    int id,flag=0;
    system("cls");
    cout<<"\t\t\t=============================================================================="<<endl;
    cout<<"\t\t\t                          CREATE  A  ACCOUNT                       "<<endl;
    cout<<"\t\t\t=============================================================================="<<endl<<endl;
    cout<<"Enter Your ID:";
    cin>>id;

    for(i=0; i<StudnetNumber; i++)
    {
        if(students[i].GetId()==id)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {

        students[StudnetNumber].Register(id);

    }
    else
    {
        cout<<"\n\nUser Already Exist!";
        sleep(1);
        RegValidator();
    }
}


int StudentCredentialCheck(int iid,string pass) //Defination
{

    for(i=0; i<=StudnetNumber; i++)
    {
        if(students[i].GetId()==iid)
        {
            if(students[i].GetPass()==pass)
            {
                return 1;
            }

        }
    }

    return 0;
}
void StoreStartTime(int id)
{
    for(i=0; i<StudnetNumber; i++)
    {
        if(id==students[i].GetId())
        {
            time_t tim=time(NULL);
            char* stime=ctime(&tim);
            //strcpy(stime,students[i].StartTime);
            students[i].StartTime=stime;
            students[i].EndtTime="Active";
        }
    }
}

void StudentPanel()  //Defination
{
    int choose;

    system("cls");

    cout<<"\t\t\t=============================================================================="<<endl;
    cout<<"\t\t\t                          STUDENT   PANEL                          "<<endl;
    cout<<"\t\t\t=============================================================================="<<endl<<endl;
    cout<<"                                         1.Register A Account"<<endl<<endl;
    cout<<"                                         2.Login/Logout Account"<<endl<<endl;
    cout<<"                                         3.Back TO Previous Manue"<<endl<<endl;
    cout<<"                                         Choose one :";
    cin>>choose;

    switch(choose)
    {
    case 1:

        RegValidator();

        break;
    case 2:
        StudentLoginPage();
        break;
    case 3:
     main();
    default:
        cout<<"\n\nWrong Keyword";
        sleep(1);
        StudentPanel();

    }
}

void StudentLoginPage()
{

    int id;
    char pass[15];
    system("cls");
    cout<<"\t\t\t=============================================================================="<<endl;
    cout<<"\t\t\t                            STUDENT   LOGIN / LOGOUT                    "<<endl;
    cout<<"\t\t\t=============================================================================="<<endl<<endl;

    cout<<"                                                  ID:";
    cin>>id;
    cout<<"                                                  Password:";
    cin>>pass;
    int z=GetPosition(id);  //assigning the index of the given id
    if (students[z].EndtTime=="Active")
    {
        passcheking();
        StudentLogout(id,pass);
    }
    else if(students[z].BlockedID==1)
    {
        cout<<"Your are Blocked Contact With admin"<<endl;
        sleep(2);
       StudentPanel();
    }
    else if(z==-1)       //geting response from index checker if there is no index then its asking for register a new account
    {
        cout<<"\n\nDO you want to register(y/n)?";
        char ch;
        cin>>ch;
        (ch=='y' || ch=='Y')?(RegValidator()):(StudentPanel());
    }
    else
    {
        passcheking();
        if(StudentCredentialCheck(id,pass)==1)
        {
            StoreStartTime(id);
            DefaultStudent=id;
            cout<<"Successfully Logged in"<<endl;
            cout<<"Your are redirecting to StudentManue"<<endl;
            sleep(2);
            StudentManue();
        }

        else
        {
            cout<<"User or Password is wrong"<<endl;
            sleep(1);
            StudentLoginPage();
        }
    }


}

void SearchStudent() //Defination
{
    int id,index;
    cout<<"\n\nEnter Student ID:";
    cin>>id;
    index=GetPosition(id);
    if(index>=0)
    {
        SystemAdmin.Search_Student(students[index]);
    }
    else
    {
        cout<<".Try Again"<<endl;
    }

}
int idvalidator(int idv)
{
    for(i=0; i<StudnetNumber; i++)
    {
        if(students[i].GetId()==idv)
        {
            return 0;
        }
    }
    return 1;
}

void StudentManue()
{
    int  currentstudentposition,choose;

    currentstudentposition=GetPosition(DefaultStudent);
    while(1)
    {
        system("cls");
        cout<<"\t\t\t=============================================================================="<<endl;
        cout<<"\t\t\t                          STUDENT    INTERFACE                        "<<endl;
        cout<<"\t\t\t=============================================================================="<<endl;
        cout<<"                                         1.View Details"<<endl;
        cout<<"                                         2.Modify Information"<<endl;
        cout<<"                                         3.Delete Account"<<endl;
        cout<<"                                         4.Leave"<<endl;
        cout<<"                                         Choose one :";

        cin>>choose;
        switch(choose)
        {
        case 1:
            students[currentstudentposition].ParticularInformation();
            break;
        case 2:
            students[currentstudentposition].modify();
            break;
        case 3:
            // delete();
            break;
        case 4:
            StudentPanel();
            break;
        default:
            cout<<"\n\nWrong Input";
            sleep(1);
            StudentManue();

        }

        cout<<"\n\nPress Any Key To Continue";
        getch();
    }


}

void StoreEndTime(int idd)
{
    for(i=0; i<StudnetNumber; i++)
    {
        if(idd==students[i].GetId())
        {
            time_t tim=time(NULL);
            char* stime=ctime(&tim);
            students[i].EndtTime=stime;
        }
    }
}

void StudentLogout(int id, char pass[15])
{
    int flag=0;


    if(StudentCredentialCheck(id,pass)==1)
    {
        StoreEndTime(id);
        flag++;
        cout<<"\n\nSuccesfully Logged Out...."<<endl;
        sleep(1);
        StudentPanel();

    }

    if(flag==0) // if falg value ramain zero that means the person who entered his or her credential to logout, he haven't logged in yet..
    {
        cout<<"\n\nYou are not logged in the system...."<<endl;
        sleep(1);
        StudentPanel();
    }
    else
    {
        cout<<"\n\nWrong information";
        sleep(1);
        StudentPanel();
    }

}

void passcheking()
{
    cout<<"\nChecking Password";
    for(i=0; i<4; i++)
    {
        cout<<".";
        usleep(500000);
    }
    cout<<"\n\n";
}



//global Function for ADmin

void AdminLogin()
{
    char passwd[15];
    system("cls");
    if(SystemAdmin.GetPass()=="NULL")
    {

        cout<<"\t\t\t=============================================================================="<<endl;
        cout<<"\t\t\t                            CREATE ADMIN ACCOUNT                    "<<endl;
        cout<<"\t\t\t=============================================================================="<<endl<<endl;
        cout<<"                                Enter A New Password:";
        SystemAdmin.SetPass();
        AdminLogin();

    }
    else
    {

        cout<<"\t\t\t=============================================================================="<<endl;
        cout<<"\t\t\t                            ADMIN   LOGIN                     "<<endl;
        cout<<"\t\t\t=============================================================================="<<endl<<endl;
        cout<<"Enter your Password:";
        cin>>passwd;
        if(passwd==SystemAdmin.GetPass())
        {
            cout<<"Succesfully Logged In"<<endl;
            sleep(2);
            AdminManue();
        }
        else
        {
            cout<<"\n\nWrong Password";
            sleep(1);
            AdminLogin();
        }
    }
}

void AdminManue()
{
    int choose;
    while(1)
    {
        system("cls");
        cout<<"\t\t\t=============================================================================="<<endl;
        cout<<"\t\t\t                          ADMIN    INTERFACE                        "<<endl;
        cout<<"\t\t\t=============================================================================="<<endl;
        cout<<"                                         1.View ALL Student Details"<<endl;
        cout<<"                                         2.Modify Student Information"<<endl;
        cout<<"                                         3.View Active Student"<<endl;
        cout<<"                                         4.Search Student"<<endl;
        cout<<"                                         5.Block Student"<<endl;
        cout<<"                                         6.Log Out"<<endl;
        cout<<"                                         Choose one :";

        cin>>choose;
        switch(choose)
        {
        case 1:
            StudentDetails();
            break;
        case 2:
            StudentModify();
            break;
        case 3:
            ActiveStudent();
            break;
        case 4:
            SearchStudent();
            break;
        case 5:
            BlockedStudent();
            break;
        case 6:
            main();
        default:
            cout<<"\n\nWrong Input";
            sleep(1);
            AdminManue();
        }

        cout<<"\n\nPress Any Key To Continue";
        getch();
    }

}

int GetPosition(int Id)
{
    for(i=0; i<StudnetNumber; i++)
    {
        if(Id==students[i].GetId())
        {
            return i;
        }
    }

    cout<<"This user is not registered";
    return -1;
}


void StudentDetails()
{
    system("cls");
    cout<<"=============================================================================="<<endl;
    cout<<"                         ALL STUDENT LIST                        "<<endl;
    cout<<"=============================================================================="<<endl<<endl;
    cout.setf(ios::left);
    cout<<setw(15)<<"NAME";
    cout<<setw(15)<<"ID";
    cout<<setw(15)<<"DEPT";

    for(i=0; i<StudnetNumber; i++)
    {
        cout<<endl;
        SystemAdmin.DisplayStudentDetails(students[i]);

    }
}

void ActiveStudent()
{

    system("cls");
    cout<<"=============================================================================="<<endl;
    cout<<"                         ACTIVE STUDENT LIST                        "<<endl;
    cout<<"=============================================================================="<<endl<<endl;

    cout << left << setw(12) << "Name"
         << setw(10) << "ID"
         << setw(20) << "Stutus"
         << "Entrance Time" << endl;

    for(i=0; i<StudnetNumber; i++)
    {
        if(students[i].EndtTime=="Active")
        {
            cout<<endl;
            SystemAdmin.ActiveStudentList(students[i]);

        }
    }

}


void StudentModify()
{
    int id,index;
    cout<<"\n\nEnter Student ID:";
    cin>>id;
    index=GetPosition(id);
    if(index>=0)
    {
        SystemAdmin.Smodify(students[index]);
    }
    else
    {
        cout<<".Try Again"<<endl;
    }

}
void BlockedStudent()
{
    int id, TempPosition;
    char choise;
    system("cls");
    cout<<"=============================================================================="<<endl;
    cout<<"                         Blocked STUDENT LIST                        "<<endl;
    cout<<"=============================================================================="<<endl<<endl;

    cout.setf(ios::left);
    cout<<setw(15)<<"NAME";
    cout<<setw(15)<<"ID";
    cout<<setw(15)<<"DEPT"<<endl;

    for(i=0; i<StudnetNumber; i++)
    {
        if(students[i].BlockedID==1)
        {

            cout<<endl;
            SystemAdmin.DisplayStudentDetails(students[i]);
        }

    }

    cout<<"\n\nDo you want to Block/Unbock someone(y/n)"<<endl;
    cin>>choise;
    if(choise=='Y' || choise=='y')
    {
        cout<<endl<<endl<<"Block/Unbllock(Student ID) : ";
        cin>>id;

        TempPosition=GetPosition(id);
        if(TempPosition<0)
        {
            cout<<"Sorry"<<endl;
        }
        else
        {
            if(students[TempPosition].BlockedID==0)
            {
                students[TempPosition].BlockedID=1;
                cout<<"\n\nSuccessfuly Blocked The ID("<<id<<")"<<endl;
            }
            else if(students[TempPosition].BlockedID==1)
            {
                students[TempPosition].BlockedID=0;
                cout<<"\n\nSuccessfuly Unblocked The ID("<<id<<")"<<endl;

            }
        }

    }

}

/*Global function End */

