#include <Windows.h>
#include "WHO.h"
#include "Login_Student.h"
#include "Login_Admin.h"
#include "Login_Teacher.h"
#include "Attendance_Student.h"
#include "Attendance_Studentt.h"
#include "Teacher_Attendance.h"
#include "Edit_Student.h"
#include "Edit_Teacher.h"
#include "FeaturesAdmin.h"
#include "Info_Student.h"
#include "Info_Teacher.h"
#include "Remove_Student.h"
#include "Search_Student.h"
#include "Student_Home.h"
#include "Teacher_Home.h"
#include "Teacher_Marks.h"
#include "Teacher_Marks2.h"
#include "Transcript_User.h"
#include "User_Admin.h"
#include "User_Student_Admin.h"
#include "User_Teacher_Admin.h"
#include <iostream>

using namespace SMS;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    WHO^ who = gcnew WHO();
    Login_Student^ logins = gcnew Login_Student();
    Login_Admin^ logina = gcnew Login_Admin();
    Login_Teacher^ logint = gcnew Login_Teacher();
    Attendance_Student^ att = gcnew Attendance_Student();
    Attendance_Studentt^ attt = gcnew Attendance_Studentt();
    Teacher_Attendance^ attteach = gcnew Teacher_Attendance();
    Edit_Student^ edit = gcnew Edit_Student();
    Edit_Teacher^ editt = gcnew Edit_Teacher();
    FeaturesAdmin^ feat = gcnew FeaturesAdmin();
    Info_Student^ info = gcnew Info_Student();
    Info_Teacher^ infot = gcnew Info_Teacher();
    Remove_Student^ rem = gcnew Remove_Student();
    Search_Student^ search = gcnew Search_Student();
    Student_Home^ home = gcnew Student_Home();
    Teacher_Home^ homet = gcnew Teacher_Home();
    Teacher_Marks^ marks = gcnew Teacher_Marks();
    Teacher_Marks2^ marks2 = gcnew Teacher_Marks2();
    Transcript_User ^trans = gcnew Transcript_User();
    User_Admin^ user = gcnew User_Admin();
    User_Student_Admin^ userst = gcnew User_Student_Admin();
    User_Teacher_Admin^ usert = gcnew User_Teacher_Admin();




    Application::Run(who);

    
    delete who;
    delete logins;
    delete logina;
    delete logint;
    delete att;
    delete attt;
    delete attteach;
    delete edit;
    delete editt;
    delete feat;
    delete info;
    delete infot;
    delete rem;
    delete search;
    delete home;
    delete homet;
    delete marks;
    delete marks2;
    delete trans;
    delete user;
    delete userst;
    delete usert;

    return 0;
}
