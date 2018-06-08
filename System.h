//
//  System.hpp
//
//  Created by 张昊 on 16/11/9.
//  Copyright © 2016年 张昊. All rights reserved.
//

#ifndef System_h
#define System_h

#include "Student.h"
#include "Course.h"
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class System
{
private:
    list<Student*> S;
    list<Course> C;
public:
    System(string Stufilename, string Courfilename);
    ~System();
    void ReadFromStuFile(string filename);
    void ReadFromCourFile(string filename);
    //For Student
    void SaveStudents(string filename);
    void AddStudent(string na, string no, string ty, string ins);
    void AddStudent(string na, string no, string ty, string mentor, string field);
    void DelStudent(string no);
    void SortByName();
    void SortByNo();
    void SetGrade(string sNo, string cName, int g);
    void CalAchieve(string sNo);
    //For Course
    void SaveCourse(string filename);
    void AddCourse(string na, int cs);
    void DelCourse(string na);
    //For Choice
    void TakeCourse(string sName, string courseName);
    void ExitCourse(string sName, string courseName);
    void SearchCourse(string stuName); //查找学生的对应课程
    void SearchStudent(string courseName); //查找修读某门课程的学生
    
    void DisplayStu();
    void DisplayCour();
};
#endif /* System_h */
