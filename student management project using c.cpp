/* Author=> Coding Warriors Team.
   Project=> Student Management System
   Assign Date=> 17/09/2023
   Submission Date=> 21/09/2023
*/
#include <windows.h> // Using for clearscreen
#include <unistd.h> // Crosss Platform 
#include <stdio.h>
#include<conio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> //exit()

struct StudentInfo
{
    char ID[10];
    char Name[20];
    char Email[30];
    char Phone[20];
    char NameOfCourse[20];
    int fees;
};
struct StudentInfo Students[100];
int i,j;
int TotalStudents = 0;
char StudentID[10];
bool IsRunning = true;
void Menu();
void AddStudent();
void ShowAllStudents();
int  SearchStudent(char StudentID[10]);
void EditStudent(int StudentFoundIndex);
void DeleteStudent(int StudentIndex);
void DeleteAllStudents();
int  IsAlreadyExists(char GivenLine[30],char InfoType, char StudentID[300]);
void ErrorAndRestart(char *Error[100]);
void DeleteCourseByIndex(int CourseIndex);
void DeleteStudentByIndex(int CourseIndex);
void UserGuideline();
void AboutUs();
void developer();
void GoBackOrExit();
void Exit();
void DataSeed();
void authentication();
//****************************Main Function**********************
int main()
{
	authentication();
	int StudentFoundIndex;
	int DeleteStudentFoundIndex;
	char Divya[100];
	 while(IsRunning)
    {
        char abhay1[100]     = "\n\t\t This Function is developed by Abhay \n";
	    for(i=0; i<strlen(abhay1); i++)
	    {
	        printf("%c",abhay1[i]);
	        Sleep(60);
	    }
		Menu();
		int option;
		scanf("%d",&option);
		switch(option)
		{
			case 0:
				system("cls");
				Exit();
				break;
			case 1:
				system("cls");
	            printf("\n\t\t **** Add A New Student ****\n\n");
				AddStudent();
				GoBackOrExit();
				break;
			case 2:
				system("cls");
	            printf("\n\t\t ****Show All Students ****\n\n");
				ShowAllStudents();
				GoBackOrExit();
				break;
			case 3:
            {
            	
	            system("cls");
	            printf("\n\t\t **** Search Students ****\n\n");
	            char Shruti[100]     = "\t\tThis Function is Developed By Shruti.\n";
				    for(i=0; i<strlen(Shruti); i++)
				    {
				        printf("%c",Shruti[i]);
				        Sleep(40);
				    }
	            printf("\t\t| Enter The Student ID: ");
	            scanf("%s",StudentID);
	            int IsFound = SearchStudent(StudentID);
	            if(IsFound<0)
	            
            {
                printf(" No Student Found\n\n");
            }
            
	            printf("\n");
	            GoBackOrExit();
	            break;
            }
            
            case 4:
	            system("cls");
	            printf("\n\t\t **** Edit a Student ****\n\n");
	            printf("\n\t\t This function Is created By Divya\n");
	            printf(" Enter The Student ID: ");
	            scanf("%s",StudentID);
	            StudentFoundIndex= SearchStudent(StudentID);
	
	            if(StudentFoundIndex>=0)
	            {
	                EditStudent(StudentFoundIndex);
	            }
	            else
	            {
	                printf(" No Student Found\n\n");
	            }
	            GoBackOrExit();
	            break;  
            
            case 5:
			    system("cls");
			    printf("\n\t\t **** Delete a Student ****\n\n");
			    printf(" Enter The Student ID: ");
			    scanf("%s", StudentID);
			
			    DeleteStudentFoundIndex = SearchStudent(StudentID);
			
			    if (DeleteStudentFoundIndex >= 0) {
			        char Sure = 'N';
			        getchar();
			        printf("\n\n");
			        printf(" Are you sure want to delete this student? (Y/N): ");
			        scanf("%c", &Sure);
			
			        if (Sure == 'Y' || Sure == 'y') {
			            DeleteStudent(DeleteStudentFoundIndex);
			        }
			        else {
			            printf(" Your Data is Safe.\n\n");
			            GoBackOrExit();
			        }
			    }
			    else {
			        printf(" No Student Found\n\n");
			        GoBackOrExit();
			    }
			    break;
			    
			case 6:
	            {
	            char Sure = 'N';
	            getchar();
	            system("cls");
	            printf("\n\t\t **** Delete ALL Students ****\n\n");
	            char welcome[100]     = "\t\t This Function is Developed by Abhishek. \n\n";
				    for(i=0; i<strlen(welcome); i++)
				    {
				        printf("%c",welcome[i]);
				        Sleep(60);
				    }

	            printf("\t\t Are you sure want to delete all the students? (Y/N): ");
	            scanf("%c",&Sure);
	            if(Sure == 'Y' || Sure == 'y')
	            {
	                DeleteAllStudents();
	            }
	            else
	            {
	                printf(" Your Data is Safe.\n\n");
	                GoBackOrExit();
	            }
	            break;
	            }
	        case 7:
	            system("cls");
	            UserGuideline();
	            GoBackOrExit();
	            break;
	        case 8:
	            system("cls");
	            AboutUs();
	            GoBackOrExit();
	            break;
	        case 9:
	        	system("cls");
	        	developer();
	        	GoBackOrExit();
	        	break;

		}
	}
}

void Menu()
{
	char welcome[100]     = "\n\t\t WELCOME TO STUDENTS MANAGEMENTS SYSTEM.. ";
    for(i=0; i<strlen(welcome); i++)
    {
        printf("%c",welcome[i]);
        Sleep(60);
    }
	printf("\n\n\t\t==============================================\n");
	printf("\t\t|    PM- Abhay          |    TL- Shruti      |\n");
	printf("\t\t==============================================\n");
    printf("\n\n\t\tStudent Management System Using C\n");
    printf("\t\t----------------------------------\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t----------------------------------\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show All students.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] Edit A student.\n");
    printf("\t\t[5] Delete A student.\n");
    printf("\t\t[6] Delete All students.\n");
    printf("\t\t[7] User Guideline.\n");
    printf("\t\t[8] About Project.\n");
    printf("\t\t[9] Developer Details.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t----------------------------------\n");
    printf("\t\tEnter The Choice: ");
} 
// end menu

void Exit()
{
    system("cls");
    int i;
    char ThankYou[100]     = "\n\n\t\t<========= Thank You =========>";
    char SeeYouSoon[100]   = "\n\n\t\t<========= See You Soon ======>\n";
    for(i=0; i<strlen(ThankYou); i++)
    {
        printf("%c",ThankYou[i]);
        Sleep(30);
    }
    for(i=0; i<strlen(SeeYouSoon); i++)
    {
        printf("%c",SeeYouSoon[i]);
        Sleep(30);
    }
    exit(0); // This function is used to Exit.
}
void AddStudent()  // function for adding student
{
    char StudentID[300];
    char Name[300];
    char Phone[300];
    char Email[300];
    char NameOfCourse[20];
    int fees;
    int i;
    char Akash[100]     = "\t\t<========= This Function is Developed By Akash. =========>\n";
    for(i=0; i<strlen(Akash); i++)
    {
        printf("%c",Akash[i]);
        Sleep(40);
    }

    int IsValidID = 0;
    while(!IsValidID)
    {
        printf("\t\t| Enter The ID: ");
        scanf("%s",&StudentID);
        if(IsAlreadyExists(StudentID,'i',StudentID) > 0)
        {
            printf("\t\tError: This ID is already exists.\n\n");
            IsValidID = 0;
        }
        else if(strlen(StudentID) > 10)
        {
            printf("\t\tError: ID can not be more than 10 characters.\n\n");
            IsValidID = 0;
        }
        else if(strlen(StudentID) <= 0)
        {
            printf("\t\tError: ID can not be empty.\n\n");
            IsValidID = 0;
        }
        else
        {
            IsValidID = 1;
        }
    }

    int IsValidName = 0;
    while(!IsValidName)
    {
        printf("\t\t| Enter The Name: ");
        scanf(" %[^\n]s",&Name);
        if(strlen(Name) > 20)
        {
            printf("\t\tError: Name can not be more than 20 characters.\n\n");
            IsValidName = 0;
        }
        if(strlen(Name) <= 0)
        {
            printf("\t\tError: Name can not be empty.\n\n");
            IsValidName = 0;
        }
        else
        {
            IsValidName = 1;
        }
    }

    int IsValidEmail = 0;
    while(!IsValidEmail)
    {
        printf("\t\t| Enter The Email: ");
        scanf("%s",&Email);
        if(IsAlreadyExists(Email,'e',StudentID) > 0)
        {
            printf("\t\tThis Email is Already Exists.\n");
            IsValidEmail = 0;
        }
        else if(strlen(Email) > 30)
        {
            printf("\t\tError: Email can not be more than 30 characters.\n\n");
            IsValidEmail = 0;
        }
        else if(strlen(Email) <= 0)
        {
            printf("\t\tError: Email can not be empty.\n\n");
            IsValidEmail = 0;
        }
        else
        {
            IsValidEmail = 1;
        }
    }

    int IsValidPhone = 0;
    while(!IsValidPhone)
    {
        printf("\t\t| Enter The Phone: ");
        scanf("%s",&Phone);
        if(IsAlreadyExists(Phone,'p',StudentID) > 0)
        {
            printf("\t\tThis Phone Number is Already Exists\n");
            IsValidPhone = 0;
        }
        else if(strlen(Phone) > 20)
        {
            printf("\t\tError: Phone can not be more than 20 characters.\n\n");
            IsValidPhone = 0;
        }
        else if(strlen(Phone) <= 0)
        {
            printf("\t\tError: Phone can not be empty.\n\n");
            IsValidPhone = 0;
        }
        else
        {
            IsValidPhone = 1;
        }
    }

   int IsValidCourse = 0;
    while(!IsValidCourse)
    {
        printf("\t\t| Enter The Name of Course: ");
        scanf(" %s",&NameOfCourse);
        if(strlen(NameOfCourse) > 20)
        {
            printf("\t\tError: Name can not be more than 20 characters.\n\n");
            IsValidCourse = 0;
        }
        if(strlen(NameOfCourse) <= 0)
        {
            printf("\t\tError: Name can not be empty.\n\n");
            IsValidCourse = 0;
        }
        else
        {
           IsValidCourse = 1;
        }
    }
    
    int IsValidfees = 0;
    while(!IsValidfees)
    {
        printf("\t\t| Enter the fees: ");
        scanf(" %d",&fees);
        if(fees<10000)
        {
            printf("\t\tError:Please Enter Atleaste half fees.\n\n");
            IsValidfees = 0;
        }else if(fees>20000)
        {
        	printf("\t\tError:Please deposit only 20000 Rupee or Half of total Fees.\n\n");
            IsValidfees = 0;
		}
        else
        {
            IsValidfees = 1;
        }
    }

    strcpy(Students[TotalStudents].ID,StudentID);
    strcpy(Students[TotalStudents].Name,Name);
    strcpy(Students[TotalStudents].Phone,Phone);
    strcpy(Students[TotalStudents].Email,Email);
    strcpy(Students[TotalStudents].NameOfCourse,NameOfCourse);
    Students[TotalStudents].fees = fees;
    TotalStudents++;
    printf("\t\t----------------------------------\n");
    char Add[100]     = "\t\t<========= Student Added Succesfully. =========>\n";
    for(i=0; i<strlen(Add); i++)
    {
        printf("%c",Add[i]);
        Sleep(50);
    }

}

// Add student end here

//Check Wether details Exist or not
int IsAlreadyExists(char GivenLine[300],char InfoType, char StudentID[300])
{
    int EmailExists = 0;
    int PhoneExists = 0;
    int IDExists = 0;
    int ep;

    for(ep=0; ep<TotalStudents; ep++)
    {
        if(strcmp(GivenLine,Students[ep].ID) == 0)
        {
            IDExists++;
        }
        if(strcmp(GivenLine,Students[ep].Email) == 0 && strcmp(StudentID,Students[ep].ID) != 0 )
        {
            EmailExists++;
        }
        if(strcmp(GivenLine,Students[ep].Phone) == 0 && strcmp(StudentID,Students[ep].ID) != 0)
        {
            PhoneExists++;
        }

    }

    if(InfoType == 'i')
    {
        return IDExists;
    }
    else if(InfoType == 'e')
    {
        return EmailExists;
    }
    else if(InfoType == 'p')
    {
        return PhoneExists;
    }
    else
    {
        return 0;
    }
}
// Show all Stduent Details
void ShowAllStudents()
{
	char welcome[100]     = "\t\t This Function is Developed by Dhruv Saini. \n\n";
    for(i=0; i<strlen(welcome); i++)
    {
        printf("%c",welcome[i]);
        Sleep(60);
    }
    printf("|==========|====================|==============================|====================|=============|==========|\n");
    printf("|    ID    |        Name        |            Email             |       Phone        |   Course    |  Fees    |\n");
    printf("|==========|====================|==============================|====================|=============|==========|\n");
    for(i=0; i<TotalStudents; i++)
    {
        printf("|");
        printf("%s",Students[i].ID);
        for(j=0; j < (10-strlen(Students[i].ID)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",Students[i].Name);
        for(j=0; j < (20-strlen(Students[i].Name)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",Students[i].Email);
        for(j=0; j < (30-strlen(Students[i].Email)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",Students[i].Phone);
        for(j=0; j < (20-strlen(Students[i].Phone)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",Students[i].NameOfCourse);
        for(j=0; j < (13-strlen(Students[i].NameOfCourse)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%d",Students[i].fees);
        for(j=0; j<5; j++)
        {
            printf(" ");
        }
        printf("|\n");
        printf("|----------|--------------------|------------------------------|--------------------|-------------|----------|\n");

    }
    printf("\n");
}

void GoBackOrExit()
{
    getchar();
    char Option;
    printf("\t\tGo back(b)? or Exit(0)?: ");
    scanf("%c",&Option);
    if(Option == '0')
    {
        Exit();
    }
    else
    {
        system("cls");
    }
}

// Search Student
int SearchStudent(char StudentID[10])
{
    system("cls");
    int StudentFoundIndex = -1;

    int i;
    for(i=0; i<TotalStudents; i++)
    {
        if(strcmp(StudentID,Students[i].ID) == 0)
        {
            StudentFoundIndex = i;
            printf("\t\t\n| One Student Found for ID: %s\n\n",StudentID);
            printf("\t\t| Student Informations\n");
            printf("\t\t-------------------------\n");

            printf("\t\t| ID:    %s\n",Students[i].ID);
            printf("\t\t| Name:  %s\n",Students[i].Name);
            printf("\t\t| Email: %s\n",Students[i].Email);
            printf("\t\t| Phone: %s\n",Students[i].Phone);
            printf("\t\t| Course: %s\n",Students[i].NameOfCourse);
            printf("\t\t| Total Fees: 20000.\n");
            printf("\t\t| Deposit Fees: %d\n",Students[i].fees);
            if(Students[i].fees>20000)
            {
            	printf("\t\t| Remaining Fees: 0\n");
			}else
			{
				printf("\t\t| Remaining Fees: %d\n",(20000-Students[i].fees));
			}
        }
    }
    return StudentFoundIndex;
}

// Modify Details
void EditStudent(int StudentFoundIndex)
{
    printf("\n\t\t **** Update The New Student ****\n\n");

    char NewName[300];
    char NewPhone[300];
    char NewEmail[300];
    char NewNameOfCourse[100];
    int Newfees;
    char StudentID[300];
    strcpy(StudentID, Students[StudentFoundIndex].ID);
    int Oldfees = Students[StudentFoundIndex].fees;

    int IsValidName = 0;
    while(!IsValidName)
    {
        printf(" Enter The New Name(0 for skip): ");
        scanf(" %[^\n]s",&NewName);
        if(strlen(NewName) > 20)
        {
            printf(" Error: Name can not be more than 20 characters.\n\n");
            IsValidName = 0;
        }
        else if(strlen(NewName) <= 0)
        {
            printf(" Error: Name can not be empty.\n\n");
            IsValidName = 0;
        }
        else
        {
            IsValidName = 1;
        }
    }

    int IsValidEmail = 0;
    while(!IsValidEmail)
    {
        printf(" Enter The New Email(0 for skip): ");
        scanf("%s",&NewEmail);

        if(strlen(NewEmail) > 30)
        {
            printf(" Error: Email can not be more than 30 characters.\n\n");
            IsValidEmail = 0;
        }
        else if(strlen(NewEmail) <= 0)
        {
            printf(" Error: Email can not be empty.\n\n");
            IsValidEmail = 0;
        }
        else if(IsAlreadyExists(NewEmail,'e',StudentID) > 0)
        {
            printf(" Error: This Email Already Exists.\n\n");
            IsValidEmail = 0;
        }
        else
        {
            IsValidEmail = 1;
        }
    }

    int IsValidPhone = 0;
    while(!IsValidPhone)
    {
        printf(" Enter The New Phone(0 for skip): ");
        scanf("%s",&NewPhone);

        if(strlen(NewPhone) > 20)
        {
            printf(" Error: Phone can not be more than 20 characters.\n\n");
            IsValidPhone = 0;
        }
        else if(strlen(NewPhone) <= 0)
        {
            printf(" Error: Phone can not be empty.\n\n");
            IsValidPhone = 0;
        }
        else if(IsAlreadyExists(NewPhone,'p',StudentID) > 0)
        {
            printf(" Error: This Phone Number is Already Exists.\n\n");
            IsValidPhone = 0;
        }
        else
        {
            IsValidPhone = 1;
        }
    }

     int IsValidCourse = 0;
    while(!IsValidCourse)
    {
        printf(" Enter The New Course(0 for skip): ");
        scanf(" %[^\n]s",&NewNameOfCourse);
        if(strlen(NewNameOfCourse) > 20)
        {
            printf(" Error: Course can not be more than 20 characters.\n\n");
            IsValidCourse = 0;
        }
        if(strlen(NewNameOfCourse) <= 0)
        {
            printf(" Error:Course can not be empty.\n\n");
            IsValidCourse = 0;
        }
        else
        {
           IsValidCourse = 1;
        }
    }
    int IsValidfees = 0;
    while(!IsValidfees)
    {
         printf(" Enter The New fees(0 for skip): ");
        scanf(" %d",&Newfees);
        if(Newfees<10000)
        {
            printf(" Error:Please Enter Atleaste half fees.\n\n");
            IsValidfees = 0;
        }else if(Newfees>20000)
        {
        	printf(" Error:Please deposit only 20000 Rupee or Half of total Fees.\n\n");
            IsValidfees = 0;
		}
        else
        {
            IsValidfees = 1;
        }
    }

    if(strcmp(NewName,"0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Name,NewName);
    }

    if(strcmp(NewEmail,"0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Email,NewEmail);
    }

    if(strcmp(NewPhone,"0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Phone,NewPhone);
    }
    if(strcmp(NewNameOfCourse,"0") != 0)
    {
        strcpy(Students[StudentFoundIndex].NameOfCourse,NewNameOfCourse);
    }
    if(strcmp(NewNameOfCourse,"0") != 0)
    {
        strcpy(Students[StudentFoundIndex].NameOfCourse,NewNameOfCourse);
    }
    if(Newfees != 0)
    {
        int Oldfees = Students[StudentFoundIndex].fees;
        Students[StudentFoundIndex].fees = Newfees;
    }

    printf(" Student Updated Successfully.\n\n");

}

// Delete a Student
void DeleteStudent(int StudentIndex)
{
	char welcome[100]     = "\t\t\t\t This Function is Developed by Prashant & Pradeep. \n\n";
    for(i=0; i<strlen(welcome); i++)
    {
        printf("%c",welcome[i]);
        Sleep(60);
    }

    DeleteStudentByIndex(StudentIndex);
    printf(" Student Deleted Successfully.\n\n");
    GoBackOrExit();
}
void DeleteStudentByIndex(int CourseIndex)
{
    int s;
    for(s=0; s<TotalStudents-1; s++)
    {
        if(s>=CourseIndex)
        {
            Students[s] = Students[s+1];
        }
    }
    TotalStudents--;
}

//Delete All Student
void DeleteAllStudents()
{
    TotalStudents = 0;
    printf("\t\tAll Students Deleted Successfully.\n\n");
    GoBackOrExit();
}

// UserGuideline
void UserGuideline()
{
	char welcome[100]     = "\t\t\t\t This Function is Developed by Abhay. \n\n";
    for(i=0; i<strlen(welcome); i++)
    {
        printf("%c",welcome[i]);
        Sleep(60);
    }
    printf("\n\t\t **** How it Works? ****\n\n");
    printf(" -> You will only able to store the Student's ID, Name, Email, Phone, Course, Fees.\n");
    printf(" -> Student ID can be maximum 10 characters long and unique for every students.\n");
    printf(" -> Student Name can be maximum 20 characters long.\n");
    printf(" -> Student Email can be maximum 30 characters long and unique for every students.\n");
    printf(" -> Student Phone can be maximum 20 characters long and unique for every students.\n");
    printf(" -> Fees must be half of total fees (Total Fees=20000).\n");
    printf(" -> Course Name can be maximum 20 characters long.\n\n");
}

// About Us
void AboutUs()
{
    printf("\n\t\t **** About US? ****\n\n");
    char welcome[100]     = "\t\t\t\t This Function is Developed by Vikrant Singh. \n\n";
    for(i=0; i<strlen(welcome); i++)
    {
        printf("%c",welcome[i]);
        Sleep(60);
    }
    printf("\t\t\t\t\tAbout This Project.\n\n");
    printf("\t\t\t -> This is a simple student management system project.\n");
    printf("\t\t\t -> This can be use for manage student details At one place.\n");
    printf("\t\t\t -> Add, edit, and delete student records.\n");
    printf("\t\t\t -> Store student ID, name, email, phone, and course information.\n");
    printf("\t\t\t -> Ability to search for students by ID.\n");
    printf("\t\t\t -> User-friendly menu-driven interface.\n");
    printf("\t\t\t -> Data validation for student information.\n");
    printf("\t\t\t -> Option to delete individual students or clear all student records.\n");
    printf("\t\t\t -> Provides user guidelines and information about the project.\n");
    printf("\t\t\t -> Ability to seed dummy data for testing purposes.\n");
    printf("\t\t\t -> Offers an About Project section for project information.\n");
    printf("\t\t\t -> Graceful exit and restart options.\n\n");
}

// 
void ErrorAndRestart(char *error[100])
{
    printf("%s\n",error);
    int i = 0;
    printf("Restarting the program: ");
    for(i=0; i<10; i++)
    {
        printf(".");
        Sleep(500);
    }
    system("cls");
    main();
}

void developer()
{
	printf("\n\n\t\t\t\t\t*************************************************\n");         
	printf("\t\t\t\t\t*                                               *\n");
	printf("\t\t\t\t\t*       -----------------------------           *\n");
	printf("\t\t\t\t\t*      =>   Enter developer details   <=        *\n");
	printf("\t\t\t\t\t*       -----------------------------           *\n");
	printf("\t\t\t\t\t*                                               *\n");
	printf("\t\t\t\t\t*************************************************\n\n\n");
	char welcome[100]     = "\t\t\t\t This Function is Developed by Ankit Singh. \n\n";
    for(i=0; i<strlen(welcome); i++)
    {
        printf("%c",welcome[i]);
        Sleep(60);
    }

printf("\n\t******************************************************************************************************************************************\n");
  printf("\t| S.No  |             Name           |       MobileNo     |       College       |   Enrollment No.   |    Course   |    Page Developer   |\n  ");
printf("\t******************************************************************************************************************************************");
        printf("\n        |   1   |      Abhay Kumar Upadhyay  |      8081756410    |   MJP GP Kaushambi  |     KSS/AP2313     |    Diploma  |    Project Manager  |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");      
        printf("        |   2   |      Shruti Rai            |      7275078509    |    GGP Varanasi     |     KSS/AP2366     |    Diploma  |       Search        |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");      
        printf("        |   3   |      Akash Yadav           |      9569212098    |   MJP GP Kaushambi  |     KSS/AP2314     |    Diploma  |      Add Student    |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");             
        printf("        |   4   |      Ankit Singh           |      8917037239    |    KCNIT Banda      |     KSS/AP2352     |    B.tech   |    Developer Page   |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");            
        printf("        |   5   |      Narayan Das Tiwari    |      7992078570    |   MGCGV Chitrakoot  |     KSS/AP2342     |    Bsc(cs)  |     Login Page      |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");            
        printf("        |   6   |      Vikrant Singh         |      8957534384    |    GP Mahoba        |     KSS/AP2337     |    IT(cs)   |      About Us       |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");            
        printf("        |   7   |      Pradeep Kumar Soni    |      9721022189    |   SICS Chitrakoot   |     KSS/AP2350     |    Bca      |   Delete Student    |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");           
        printf("        |   8   |      Dhruv Saini           |      8604515407    |   SICS Chitrakoot   |     KSS/AP2341     |    Bca      |   Show All Students |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");            
        printf("        |   9   |      Divya Namdev          |      6387425241    |   SICS Chitrakoot   |     KSS/AP2347     |    MSC(cs)  |   Update Records    |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");           
        printf("        |  10   |      Prashant              |      7518835347    |   SICS Chitrakoot   |     KSS/AP2315     |    Bca      |   Delete Student    |");
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("        |  11   |    Abhishek Panday         |      7388413299    |   GPPP Pratapgarh   |     KSS/AP2375     |    Diploma  |  Delete All Records |"); 
printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");           
                
printf("\n\n\t\t\t\t\t*************************************************\n");         
	printf("\t\t\t\t\t*                                               *\n");
	printf("\t\t\t\t\t*   ------------------------------------------  *\n");
	printf("\t\t\t\t\t*   |                                        |  *\n");
	printf("\t\t\t\t\t*   | Project Manager => Abhay Kumar Upadhyay|  *\n");
	printf("\t\t\t\t\t*   |  Project Leader => Shruti Rai          |  *\n");
	printf("\t\t\t\t\t*   ------------------------------------------  *\n");
	printf("\t\t\t\t\t*                                               *\n");
	printf("\t\t\t\t\t*************************************************\n\n\n");
 
}
void authentication() {
	char developed[100]     = "\n\t\t This Project Developed By Coding Warrior's Warriors ";
    for(i=0; i<strlen(developed); i++)
    {
        printf("%c",developed[i]);
        Sleep(60);
    }
    printf("\n\n\t\t*************************************************\n");
    printf("\t\t*                                               *\n");
    printf("\t\t*       -----------------------------           *\n");
    printf("\t\t*      =>   STUDENTS MANAGEMENTS   <=           *\n");
    printf("\t\t*       -----------------------------           *\n");
    printf("\t\t*                                               *\n");
    printf("\t\t*************************************************\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ..CODING WARRIORS.. \xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n");
    char welcome[100]     = "\t\t This Function is Developed by Narayan Das. \n\n";
    for(i=0; i<strlen(welcome); i++)
    {
        printf("%c",welcome[i]);
        Sleep(60);
    }
    char uname[] = {"warriors"}, upass[] = {"2023"}, ename[20], epass[20];
    char ch;
    int n, x;

    printf("\n\t\t Enter your user name => ");
    gets(ename);
    printf("\n\t\t Enter your password =>  ");
    n = strlen(upass);

    for (x = 0; x < n;) {
        ch = _getch(); // Use _getch for Windows, getch for other systems

        if (ch == 13) {
            // Enter key pressed, terminate the loop
            epass[x] = '\0';
            break;
        } else if (ch == 8 && x > 0) {
            // Backspace key pressed, erase the last character
            x--;
            printf("\b \b");
        } else if (ch >= 32 && ch <= 126) {
            // Valid printable ASCII characters
            epass[x] = ch;
            x++;
            printf("*");
        }
    }

    if (strcmp(uname, ename) == 0 && strcmp(upass, epass) == 0) {
    	system("cls");
//        Menu();
    } else
        printf("\n Invalid userid or password. ");
        system("cls");
//        authentication();

}
