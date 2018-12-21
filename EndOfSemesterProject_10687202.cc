#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <iomanip>


using namespace std;

int i=0, j=0;
char choice;
string finder, designer(90, '*'), searcher;

struct student
{
    string fullname, DOB, idNumber, level;
    string guardName, guardAddress, guardNumber, gender;
}pupil;

struct staff
{
    string fullname, DOB, idNumber, gender;
    string address, cellphone, next_of_Kin, kinPhoneNumber;
}teacher;

struct courses
{
    string courseCODE, courseName;
}subject;

int main()
{
    int i, j;
    char choice;
    string finder, searcher;

    while (1)//outer loop
    {
        system("cls");

        cout << "\n*****************************************************************************************";
        cout << "\n\n\t\t\tSCHOOL MANAGEMENT SYSTEM\n\n";
        cout << "*****************************************************************************************" << endl;
        cout << "\n\n\t\t\t    MAIN SCREEN\n\n";
        cout << "\n 1) Student's information." << " 2) Staff information." << " 3) Courses information." << " 4) Exit program.\n" << endl;
        cout << " Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice)//first switching
        {
            case '1'://Student Information
            {
                while (1) //inner loop - 1.
                {
                    system("cls");
                    cout << "\n*****************************************************************************************";
                    cout << "\n\n\t\t\tSTUDENT'S INFORMATION SECTION\n\n";
                    cout << "*****************************************************************************************\n\n\n";
                    cout << " 1) Create new entry" << " 2) Find and display" << " 3) Delete record" << " 4) Return to Main Screen";
                    cout << "\n\n Enter your choice: ";
                    cin >> choice;
                    system("cls");

                    switch (choice)//second switching
                    {
                        case '3':
                        {
                            system("cls");

                            string idnum;
                            bool flag = false;
                            int index;

                            ifstream in_file;
                            in_file.open("C:\\Users\\User\\Documents\\C++ Projects\\SchoolManagementProgram\\students.txt");
                            if (!in_file)
                                cout << "\nFile NOT Found!";

                            ofstream out_file;
                            out_file.open("temp.txt", ios::binary);

                            cout << "\n\n" << designer << "\n\t\t\tDELETE A STUDENT RECORD\n" << designer;
                            cout << "\n\n\nEnter the ID Number of student to be deleted: ";
                            cin >> idnum;

                            for(i=0; (!in_file.eof()); i++)
                            {
                                getline(in_file, pupil.idNumber);
                                if (pupil.idNumber != idnum)
                                {
                                    out_file << pupil.idNumber << endl;
                                    out_file << pupil.fullname << endl;
                                    out_file << pupil.gender << endl;
                                    out_file << pupil.DOB << endl;
                                    out_file << pupil.level << endl;
                                    out_file << pupil.guardName << endl;
                                    out_file << pupil.guardAddress << endl;
                                    out_file << pupil.guardNumber << endl;
                                }
                            }
                            in_file.close();
                            out_file.close();

                            remove("students.txt");
                            rename("temp.txt", "students.txt");

                            cout << "\n\n" << designer << "\n\t\t\tDELETE SUCCESSFUL\n" << designer << endl;
                            cout << "\n\n Press any key two times to proceed";
                            getch();
                            getch();
                        }
                        continue;

                        case '1'://create new entry
                        {
                            cout << "\n\n" << designer << "\n\t\t\tStudent Data Entry\n" << designer
                            << "\n\n";

                            ofstream out_file ("students.txt", ios::app);
                            for (j=0; choice != 'n'; j++)
                            {
                                if (choice == 'y' || choice == 'Y' || choice == '1')
                                {
                                    cout << "Enter student's ID Number: ";
                                    cin >> pupil.idNumber;

                                    cout << "Enter Full Name of Student, ending with a \"!\" mark: ";
                                    getline(cin, pupil.fullname, '!');

                                    cout << "Enter student's Gender (\"Male\" or \"Female\"): ";
                                    cin >> pupil.gender;

                                    cout << "Enter student's Date of Birth: ";
                                    cin >> pupil.DOB;

                                    cout << "Enter Level of student: ";
                                    cin >> pupil.level;

                                    cout << "Enter Full Name of student's Guardian, ending with a \"!\" mark: ";
                                    getline(cin, pupil.guardName, '!');

                                    cout << "Enter Guardian's address, ending with a \"!\" mark: ";
                                    getline(cin, pupil.guardAddress, '!');

                                    cout << "Enter Guardian contact Number, ending with a \"!\" mark: ";
                                    getline(cin, pupil.guardNumber, '!');

                                    out_file << pupil.idNumber << endl;
                                    out_file << pupil.fullname << endl;
                                    out_file << pupil.gender << endl;
                                    out_file << pupil.DOB << endl;
                                    out_file << pupil.level << endl;
                                    out_file << pupil.guardName << endl;
                                    out_file << pupil.guardAddress << endl;
                                    out_file << pupil.guardNumber << endl;

                                    cout << "\n\n Do you want to enter data for another student?";
                                    cout << "\n Press \"Y\" to enter new data for another student " << "or \"N\" to finish:  ";
                                    cin >> choice;
                                    system("cls");
                                }
                            }
                            out_file.close();
                        }
                        continue;//control back to inner loop - 1
                        case '2'://Find and display Student information
                        {
                            int found = 0;
                            ifstream in_file("C:\\Users\\User\\Documents\\C++ Projects\\SchoolManagementProgram\\students.txt");
                            if (!in_file)
                                cout << "\n\n File DOES NOT exist!";

                            cout << " Enter student's ID Number: ";
                            cin >> finder;
                            cout << endl;

                            for(j=0;(!in_file.eof());j++)
                            {
                                getline(in_file, pupil.idNumber);
                                if (pupil.idNumber == finder)
                                {
                                    found = 1;

                                    in_file.ignore(250, '\n');
                                    getline(in_file, pupil.fullname);
                                    getline(in_file, pupil.gender);
                                    getline(in_file, pupil.DOB);
                                    getline(in_file, pupil.level);
                                    in_file.ignore(250, '\n');
                                    getline(in_file, pupil.guardName);
                                    in_file.ignore(250, '\n');
                                    getline(in_file, pupil.guardAddress);
                                    in_file.ignore(250, '\n');
                                    getline(in_file, pupil.guardNumber);

                                    cout << "idNumber: " << pupil.idNumber << endl;
                                    cout << "Full Name: " << pupil.fullname <<endl;
                                    cout << "Gender: " << pupil.gender << endl;
                                    cout << "Date of Birth: " << pupil.DOB << endl;
                                    cout << "Student is in Level: " << pupil.level << endl;
                                    cout << "Guardian's name: " << pupil.guardName << endl;
                                    cout << "Guardian Address: " << pupil.guardAddress << endl;
                                    cout << "Guardian's Contact: " << pupil.guardNumber << endl;
                                }
                            }
                            if (found == 0)
                                cout << " No Record Found" << endl;

                            in_file.close();
                            cout << "\n\n Press any key two times to proceed";
                            getch();
                            getch();
                        }
                        continue;//control back to inner loop - 1

                        case '4':
                        {
                            break;//inner switching break
                        }
                    }break;//inner loop - 1 break
                }continue;//control passed to first loop
            }
            case '2'://Teachers Information
            {
                    while (1)//inner loop - 2
                    {
                        system("cls");//clear screen.
                        cout << "\n\n" << designer;
                        cout << "\n\t\t\tTEACHERS INFORMATION SECTION\n";
                        cout << designer << "\n\n\n";

                        cout << " 1) Create new entry " << " 2) Find and display " << " 3) Delete Teacher" << " 4) Return to main\n\n";
                        cout << " Enter your choice: ";
                        cin >> choice;
                        //system("cls");

                        switch (choice)//second switching
                        {
                            case '3'://DELETE TEACHER INFORMATION
                            {
                            system("cls");

                            string idnum;
                            bool flag = false;
                            int index;

                            ifstream in_file;
                            in_file.open("C:\\Users\\User\\Documents\\C++ Projects\\SchoolManagementProgram\\teachers.txt");
                            if (!in_file)
                                cout << "\nFile NOT Found!";

                            ofstream out_file;
                            out_file.open("temporary.txt", ios::binary);

                            cout << "\n\n" << designer << "\n\t\t\tDELETE TEACHER INFORMATION\n" << designer;
                            cout << "\n\n\nEnter the ID Number of Teacher to be deleted: ";
                            cin >> idnum;

                            for(i=0; (!in_file.eof()); i++)
                            {
                                getline(in_file, teacher.idNumber);
                                if (teacher.idNumber != idnum)
                                {
                                    out_file << teacher.idNumber << endl;
                                    out_file << teacher.fullname << endl;
                                    out_file << teacher.gender << endl;
                                    out_file << teacher.DOB << endl;
                                    out_file << teacher.address << endl;
                                    out_file << teacher.cellphone << endl;
                                    out_file << teacher.next_of_Kin << endl;
                                    out_file << teacher.kinPhoneNumber << endl;
                                }
                            }
                            in_file.close();
                            out_file.close();

                            remove("teachers.txt");
                            rename("temporary.txt", "teachers.txt");

                            cout << "\n\n" << designer << "\n\t\t\tDELETE SUCCESSFUL\n" << designer << endl;
                            cout << "\n\n Press any key two times to proceed";
                            getch();
                            getch();
                        }
                        continue;

                        case '1'://create new entry
                        {
                            system("cls");
                            cout << "\n\n" << designer << "\n\t\t\tTEACHER INFORMATION ENTRY\n" << designer
                            << "\n\n";

                            ofstream out_file ("teachers.txt", ios::app);
                            for (j=0; choice != 'n'; j++)
                            {
                                if (choice == 'y' || choice == 'Y' || choice == '1')
                                {
                                    cout << "Enter Teacher's ID Number[Digits ONLY!]: ";
                                    cin >> teacher.idNumber;

                                    cout << "Enter Full Name of Teacher, Type \"!\" mark to indicate END OF ENTRY: ";
                                    getline(cin, teacher.fullname, '!');

                                    cout << "Enter Teacher's Gender (\"Male\" or \"Female\"): ";
                                    cin >> teacher.gender;

                                    cout << "Enter Teacher's Date of Birth in this format [DDMMYYYY]: ";
                                    cin >> teacher.DOB;

                                    cout << "Enter Teacher's address, TYPE a \"!\" mark to indicate END OF ENTRY: ";
                                    getline(cin, teacher.address, '!');

                                    cout << "Enter Teacher's Cellphone Number in this format[+233123456789]: ";
                                    cin >> teacher.cellphone;

                                    cout << "Enter Full Name of Teacher's Next-of-Kin, TYPE a \"!\" mark to indicate END OF ENTRY: ";
                                    getline(cin, teacher.next_of_Kin, '!');

                                    cout << "Enter Next-of-Kin contact Number in this format [+233123456789]: ";
                                    cin >> teacher.kinPhoneNumber;

                                    out_file << teacher.idNumber << endl;
                                    out_file << teacher.fullname << endl;
                                    out_file << teacher.gender << endl;
                                    out_file << teacher.DOB << endl;
                                    out_file << teacher.address << endl;
                                    out_file << teacher.cellphone << endl;
                                    out_file << teacher.next_of_Kin << endl;
                                    out_file << teacher.kinPhoneNumber << endl;

                                    cout << "\n\n Do you want to enter data for another Teacher?";
                                    cout << "\n Press \"Y\" to enter new data for another Teacher " << "or \"N\" to finish:  ";
                                    cin >> choice;
                                    system("cls");
                                }
                            }
                            out_file.close();
                        }
                        continue;//control back to inner loop - 1
                        case '2'://Find and display Teacher information
                        {
                            system("cls");
                            int found = 0;
                            ifstream in_file("C:\\Users\\User\\Documents\\C++ Projects\\SchoolManagementProgram\\teachers.txt");
                            if (!in_file)
                                cout << "\n\n File DOES NOT exist!";

                            cout << " Enter teacher's ID Number[Digits ONLY; NO SPACE]: ";
                            cin >> finder;
                            cout << endl;

                            for(j=0;(!in_file.eof());j++)
                            {
                                getline(in_file, teacher.idNumber);
                                if (teacher.idNumber == finder)
                                {
                                    found = 1;

                                    in_file.ignore(250, '\n');
                                    getline(in_file, teacher.fullname);
                                    getline(in_file, teacher.gender);
                                    getline(in_file, teacher.DOB);
                                    in_file.ignore(250, '\n');
                                    getline(in_file, teacher.address);
                                    getline(in_file, teacher.cellphone);
                                    in_file.ignore(250, '\n');
                                    getline(in_file, teacher.next_of_Kin);
                                    //in_file.ignore(250, '\n');
                                    getline(in_file, teacher.kinPhoneNumber);

                                    cout << "idNumber: " << teacher.idNumber << endl;
                                    cout << "Full Name: " << teacher.fullname <<endl;
                                    cout << "Gender: " << teacher.gender << endl;
                                    cout << "Date of Birth: " << teacher.DOB << endl;
                                    cout << "Address: " << teacher.address << endl;
                                    cout << "Cellphone: " << teacher.cellphone << endl;
                                    cout << "Next-of-Kin: " << teacher.next_of_Kin << endl;
                                    cout << "Next-of-Kin's Contact: " << teacher.kinPhoneNumber << endl;
                                }
                            }
                            if (found == 0)
                                cout << " No Record Found" << endl;

                            in_file.close();
                            cout << "\n\n Press any key two times to proceed";
                            getch();
                            getch();
                        }
                        continue;//control back to inner loop - 1

                        case '4':
                        {
                            break;//inner switching break
                        }
                    }break;
                }continue;
            }
            case '3'://Courses information.
            {
                while (1) //inner loop - 1.
                {
                    system("cls");
                    cout << "\n\n" << designer;
                    cout << "\n\t\t\tCOURSES'S INFORMATION SECTION\n";
                    cout << designer << "\n\n\n";
                    cout << " 1) Create new entry" << " 2) Find and display" << " 3) Delete course" << " 4) Return to Main Screen";
                    cout << "\n\n Enter your choice: ";
                    cin >> choice;
                    system("cls");

                    switch (choice)//second switching
                    {
                        case '3'://Delete Course
                        {
                            system("cls");

                            string idnum;
                            bool flag = false;
                            int index;

                            ifstream in_file;
                            in_file.open("C:\\Users\\User\\Documents\\C++ Projects\\SchoolManagementProgram\\courses.txt");
                            if (!in_file)
                                cout << "\nFile NOT Found!";

                            ofstream out_file;
                            out_file.open("tempCourse.txt", ios::binary);

                            cout << "\n\n" << designer << "\n\t\t\tDELETE A COURSE\n" << designer;
                            cout << "\n\n\nEnter the Course Code to delete Course: ";
                            cin >> idnum;

                            for(i=0; (!in_file.eof()); i++)
                            {
                                getline(in_file, subject.courseCODE);
                                if (subject.courseCODE != idnum)
                                {
                                    out_file << subject.courseCODE << endl;
                                    out_file << subject.courseName << endl;
                                }
                            }
                            in_file.close();
                            out_file.close();

                            remove("courses.txt");
                            rename("tempCourse.txt", "courses.txt");

                            cout << "\n\n" << designer << "\n\t\t\tDELETE SUCCESSFUL\n" << designer << endl;
                            cout << "\n\n Press any key two times to proceed";
                            getch();
                            getch();
                        }
                        continue;

                        case '1'://create new entry
                        {
                            cout << "\n\n" << designer << "\n\t\t\tNew Course Entry\n" << designer << "\n\n";

                            ofstream out_file ("courses.txt", ios::app);
                            for (j=0; choice != 'n'; j++)
                            {
                                if (choice == 'y' || choice == 'Y' || choice == '1')
                                {
                                    cout << "Enter Course CODE, DO NOT LEAVE ANY SPACE: ";
                                    cin >> subject.courseCODE;

                                    cout << "Enter Full Course Title, TYPE a \"!\" mark to indicate END OF ENTRY: ";
                                    getline(cin, subject.courseName, '!');

                                    out_file << subject.courseCODE << endl;
                                    out_file << subject.courseName << endl;

                                    cout << "\n\n Do you want to enter data for another Course?";
                                    cout << "\n Press \"Y\" to enter new data for another Course " << "or \"N\" to finish:  ";
                                    cin >> choice;
                                    system("cls");
                                }
                            }
                            out_file.close();
                        }
                        continue;//control back to inner loop - 1
                        case '2'://Find and display Course information
                        {
                            int found = 0;
                            ifstream in_file("C:\\Users\\User\\Documents\\C++ Projects\\SchoolManagementProgram\\courses.txt");
                            if (!in_file)
                                cout << "\n\n File DOES NOT exist!";

                            cout << " Enter the Course CODE. DO NOT LEAVE ANY SPACE: ";
                            cin >> finder;
                            system("cls");
                            cout << endl;

                            for(j=0;(!in_file.eof());j++)
                            {
                                getline(in_file, subject.courseCODE);
                                if (subject.courseCODE == finder)
                                {
                                    found = 1;

                                    in_file.ignore(250, '\n');
                                    getline(in_file, subject.courseName);

                                    cout << "Course CODE: " << subject.courseCODE << endl;
                                    cout << "TITLE OF COURSE: " << subject.courseName <<endl;
                                }
                            }
                            if (found == 0)
                                cout << " No Record Found" << endl;

                            in_file.close();
                            cout << "\n\n Press any key two times to proceed";
                            getch();
                            getch();
                        }
                        continue;//control back to inner loop - 1

                        case '4':
                        {
                            break;//inner switching break
                        }
                    }break;//inner loop - 1 break
                }continue;//control passed to first loop
            }
            case '4':
            {
                cout << "\n Thank you! Program exiting." << endl;
                exit(0);
            }
        }
    }

    return 0;
}
