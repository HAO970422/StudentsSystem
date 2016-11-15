//
//  Student.hpp
//  StudentsSystem
//
//  Created by 张昊 on 16/11/9.
//  Copyright © 2016年 张昊. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include "Course.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;


class Student
{
protected:
    string sName;
    string sNo;
    string sType;
    
public:
    list <Course> sChoice;
    
    Student();
    Student(string name, string no, string type);
    string getsName() const;
    string getsNo() const;
    string getsType() const;
    virtual string SaveFile() = 0;
    ~Student();
};

class UGStudent : public Student
{
private:
    string Instructor;
public:
    UGStudent();
    UGStudent(string name, string no, string type, string ins);
    ~UGStudent();
    string getsInstructor() const;
    string SaveFile();
    
};

class GStudent : public Student
{
private:
    string Mentor;
    string Field;
public:
    GStudent();
    GStudent(string name, string no, string type, string mentor, string field);
    ~GStudent();
    string getsMentor() const;
    string getsField() const;
    string SaveFile();
};
#endif /* Student_h */
