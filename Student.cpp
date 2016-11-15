//
//  Student.cpp
//  StudentsSystem
//
//  Created by 张昊 on 16/11/9.
//  Copyright © 2016年 张昊. All rights reserved.
//

#include "Student.h"
//For Student
Student::Student()
{
    
}

Student::Student(string name, string no, string type)
{
    sName = name;
    sNo = no;
    sType = type;
}

Student::~Student()
{
    
}

string Student::getsName() const
{
    return sName;
}

string Student::getsNo() const
{
    return sNo;
}

string Student::getsType() const
{
    return sType;
}
/*string Student::SaveFile()
{
    return "zzz";
}*/
//For UGStudent
UGStudent::UGStudent()
{
    
}

UGStudent::~UGStudent()
{
    
}

UGStudent::UGStudent(string name, string no, string type, string ins): Student(name, no, type)
{
    Instructor = ins;
}

string UGStudent::getsInstructor() const
{
    return Instructor;
}
string UGStudent::SaveFile()
{
    string UGStu = getsName()+" "+getsNo()+" "+getsType()+" "+getsInstructor()+" ";
    return UGStu;
}
//For GStudent
GStudent::GStudent()
{
    
}
GStudent::GStudent(string name, string no, string type, string mentor, string field) : Student(name, no, type)
{
    Mentor = mentor;
    Field = field;
}
GStudent::~GStudent()
{
    
}
string GStudent::getsMentor() const
{
    return Mentor;
}
string GStudent::getsField() const
{
    return Field;
}
string GStudent::SaveFile()
{
    string UGStu = getsName()+" "+getsNo()+" "+getsType()+" "+getsMentor()+" "+getsField()+" ";
    return UGStu;
}
