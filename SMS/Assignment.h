#pragma once
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h> 
ref class Assignment
{
public:
    void WriteMarks(System::String^ filename, System::String^ Title,
        System::String^ quiz1, System::String^ name1, System::String^ rollnum1,
        System::String^ quiz2, System::String^ name2, System::String^ rollnum2,
        System::String^ quiz3, System::String^ name3, System::String^ rollnum3,
        System::String^ quiz4, System::String^ name4, System::String^ rollnum4,
        System::String^ quiz5, System::String^ name5, System::String^ rollnum5,
        System::String^ quiz6, System::String^ name6, System::String^ rollnum6,
        System::String^ quiz7, System::String^ name7, System::String^ rollnum7) {

        std::ofstream file(msclr::interop::marshal_as<std::string>(filename), std::ios::app); 

        if (!file.is_open()) {
            System::Console::WriteLine("Error: Unable to open file.");
            return;
        }

        std::string t = msclr::interop::marshal_as<std::string>(Title);
        file << t << std::endl;
        if (name1 != "") {
            WriteStudent(file, quiz1, name1, rollnum1);
        }
        if (name2 != "") {
            WriteStudent(file, quiz2, name2, rollnum2);
        }
        if (name3 != "") {
            WriteStudent(file, quiz3, name3, rollnum3);
        }

        if (name4 != "") {
            WriteStudent(file, quiz4, name4, rollnum4);
        }
        if (name5 != "") {
            WriteStudent(file, quiz5, name5, rollnum5);
        }
        if (name6 != "") {
            WriteStudent(file, quiz6, name6, rollnum6);
        }
        if (name7 != "") {
            WriteStudent(file, quiz7, name7, rollnum7);
        }

        file.close(); 
    }

private:
    void WriteStudent(std::ofstream& file, System::String^ quiz, System::String^ name, System::String^ rollnum) {
        std::string q = msclr::interop::marshal_as<std::string>(quiz);
        std::string n = msclr::interop::marshal_as<std::string>(name);
        std::string r = msclr::interop::marshal_as<std::string>(rollnum);

        file << n << "," << r << "," << q << std::endl;
    }
};

