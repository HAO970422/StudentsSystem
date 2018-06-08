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
    string sName; //学生姓名
    string sNo; //学生学号
    string sType; //学生类型（本科生or研究生）
    
public:
    list <Course> sChoice; //该学生所选课程
    
    Student();
    Student(string name, string no, string type);
    string getsName() const;
    string getsNo() const;
    string getsType() const;
    virtual string SaveFile() = 0; //纯虚函数，Student类作为抽象类不能直接定义对象
    ~Student();
};

//本科生
class UGStudent : public Student
{
private:
    string Instructor;
public:
    UGStudent();
    UGStudent(string name, string no, string type, string ins);
    ~UGStudent();
    string getsInstructor() const; //常成员函数
    string SaveFile();
    
};

//研究生
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
