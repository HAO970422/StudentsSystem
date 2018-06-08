//
//  System.cpp
//  StudentsSystem
//
//  Created by 张昊 on 16/11/9.
//  Copyright © 2016年 张昊. All rights reserved.
//

#include "System.h"

System::System(string Stufilename, string Courfilename)
{
    ReadFromStuFile(Stufilename);
    ReadFromCourFile(Courfilename);
    cout<<"Init Successfully"<<endl;
}

System::~System()
{
    
}

void System::ReadFromStuFile(string filename)
{
    ifstream StuFile(filename);
    if(!StuFile.is_open())
    {
        cout<<"ReadStuFile: Student File Not Found!"<<endl;
        exit(-1);
    }
    string line;
    while(!StuFile.eof())
    {
        getline(StuFile, line); //得到文本的一行
        vector<string> token;
        //以空格分割
        auto split_pos = line.find(" ");
        while(split_pos <= line.length())
        {
            token.push_back(line.substr(0, split_pos));
            line.erase(0, split_pos+1);
            split_pos = line.find(" ");
        }
        token.push_back(line);
        //string name = line.substr(0, split_pos);
        //string no = line.substr(split_pos+1);
        if(token[2] == "UG")
        {
            Student* newStu = new UGStudent(token[0], token[1], token[2], token[3]);
            S.push_back(newStu);
        }
        else if(token[2] == "G")
        {
            Student* newStu = new GStudent(token[0], token[1], token[2], token[3], token[4]);
            S.push_back(newStu);
        }
    }
    StuFile.close();
    cout<<"Init StuFile Successfully"<<endl;
}

void System::ReadFromCourFile(string filename)
{
    ifstream CourFile(filename);
    if(!CourFile.is_open())
    {
        cout<<"ReadCourFile: Courses File Not Found!"<<endl;
        exit(-1);
    }
    string line;
    while(!CourFile.eof())
    {
        getline(CourFile, line);
        vector<string> token;
        
        auto split_pos = line.find(" ");
        while(split_pos <= line.length())
        {
            token.push_back(line.substr(0, split_pos));
            line.erase(0, split_pos+1);
            split_pos = line.find(" ");
        }
        token.push_back(line);
        //string name = line.substr(0, split_pos);
        //int score = stoi(line.substr(split_pos+1));
        int score = stoi(token[1]);
        Course newCour(token[0], score);
        C.push_back(newCour);
    }
    CourFile.close();
    cout<<"Init CourFile Successfully"<<endl;
}

//For Student
void System::SaveStudents(string filename)
{
    ofstream outfile(filename, ios::out);
    if(!outfile)
    {
        cout<<"SaveStu: can't open file"<<endl;
        return;
    }

    for(auto i = S.begin(); i != S.end(); i++)
    {
        outfile<<(*i)->SaveFile(); // save学生信息
        // save学生的选课信息
        for(auto j = (*i)->sChoice.begin(); j != (*i)->sChoice.end(); j++)
        {
            outfile<<(*j).getcName()<<" ";
        }
        outfile<<endl; //换行
        //if((*i)->getsType() == "UG")
        //    outfile<<(*i)->SaveFile();
        //else if((*i)->getsType() == "G")
        //    outfile<<(*i)->SaveFile();
    }
    outfile.close();
    cout<<"Save Stu Successfully"<<endl;
}

void System::AddStudent(string na, string no, string ty, string ins)
{
    for(auto i = S.begin(); i != S.end(); i++)
    {
        if((*i)->getsNo() == no)
        {
            cout<<"AddStu: Student Already Existed"<<endl;
            return;
        }
    }
    Student *newStu = new UGStudent(na, no, ty, ins);
    S.push_back(newStu);
    cout<<"Add Stu Successfully"<<endl;
}
void System::AddStudent(string na, string no, string ty, string mentor, string field)
{
    for(auto i = S.begin(); i != S.end(); i++)
    {
        if((*i)->getsNo() == no)
        {
            cout<<"AddStu: Student Already Existed"<<endl;
            return;
        }
    }
    Student *newStu = new GStudent(na, no, ty, mentor, field);
    S.push_back(newStu);
    cout<<"Add Stu Successfully"<<endl;
}
void System::DelStudent(string no)
{
    auto i = S.begin();
    for( ;i != S.end(); i++)
    {
        if((*i)->getsNo() == no)
        {
            break;
        }
    }
    if(i == S.end())
    {
        cout<<"DelStu: Student Not Existed"<<endl;
        return;
    }
    else
    {
        S.erase(i);
    }
    cout<<"Del Stu Successfully"<<endl;
}

bool SortNo(const Student* n1, const Student* n2)
{
    return n1->getsNo() < n2->getsNo();
}

void System::SortByNo()
{
    S.sort(SortNo);
    cout<<"Sort Stu No. Successfully"<<endl;
}

bool SortName(const Student* n1, const Student* n2)
{
    if(n1->getsName() < n2->getsName())
        return true;
    else if(n1->getsName() > n2->getsName())
        return false;
    else
        return (n1->getsNo() < n2->getsNo());
}

void System::SortByName()
{
    S.sort(SortName);
    cout<<"Sort Stu Name Successfully"<<endl;
}
void System::SetGrade(string sNo, string cName, int g)
{
    //判断这名学生是否存在与学生信息表中，理想情况是存在的
    auto i = S.begin();
    for(; i!= S.end(); i++)
    {
        if((*i)->getsNo() == sNo)
            break;
    }
    if(i == S.end())
    {
        cout<<"TakeCour: Student Not Existed"<<endl;
        return;
    }
    //判断这门课程是否已经存在于这名学生的选课表中，理想情况存在
    auto j = (*i)->sChoice.begin();
    for(; j != (*i)->sChoice.end(); j++)
    {
        if((*j).getcName() == cName)
            break;
    }
    if(j == (*i)->sChoice.end())
    {
        cout<<"SetGrade: Course Not Existed In Student's Choice"<<endl;
        return;
    }
    else
    {
        (*j).setGrade(g);
    }
    cout<<"Set Grade Successfully"<<endl;
    /*for(auto temp : (*i).sChoice)
     cout<<temp.getcName()<<endl;*/
}

void System::CalAchieve(string sNo)
{
    auto i = S.begin();
    for(; i!= S.end(); i++)
    {
        if((*i)->getsNo() == sNo)
            break;
    }
    if(i == S.end())
    {
        cout<<"CalAchieve: Student Not Existed"<<endl;
        return;
    }
    double Ach = 0.0;
    double SumofGrade = 0.0;
    double SumofScore = 0.0;
    for(auto j = (*i)->sChoice.begin(); j != (*i)->sChoice.end(); j++)
    {
        cout<<(*j).getcName()<<" "<<(*j).getGrade()<<" "<<endl;
        SumofScore += (*j).getcScore();
        SumofGrade += (*j).getGrade() * (*j).getcScore();
    }
    Ach = SumofGrade/SumofScore;
    cout<<"Achieve is "<<Ach/20<<endl;
}
//For Course
void System::SaveCourse(string filename)
{
    ofstream outfile(filename, ios::out);
    if(!outfile)
    {
        cout<<"SaveCour: can't open file"<<endl;
        return;
    }
    for(auto i = C.begin(); i != C.end(); i++)
    {
        outfile<<(*i).getcName()<<" "<<(*i).getcScore()<<endl;
    }
    outfile.close();
    cout<<"Save Cour Successfully"<<endl;
}

void System::AddCourse(string na, int cs)
{
    for(auto i = C.begin(); i != C.end(); i++)
    {
        if((*i).getcName() == na)
        {
            cout<<"AddCour: Course Already Existed"<<endl;
            return;
        }
    }
    Course newCour(na, cs);
    C.push_back(newCour);
    cout<<"Add Cour Successfully"<<endl;
}

void System::DelCourse(string na)
{
    auto i = C.begin();
    for( ;i != C.end(); i++)
    {
        if((*i).getcName() == na)
        {
            break;
        }
    }
    if(i == C.end())
    {
        cout<<"DelCour: Course Not Existed"<<endl;
        return;
    }
    else
    {
        C.erase(i);
    }
    cout<<"Del Cour Successfully"<<endl;
}

//For Choice
void System::TakeCourse(string sName, string cName)
{
    //判断这门课程是否存在于课程信息表中
    auto k = C.begin();
    int cSore;
    for(; k != C.end(); k++)
    {
        if((*k).getcName() == cName)
            break;
    }
    if(k == C.end())
    {
        cout<<"TakeCour: Course Not Existed"<<endl;
        return;
    }
    else
    {
        cSore = (*k).getcScore();
    }
    Course c(cName,cSore);
    //判断这名学生是否存在与学生信息表中，理想情况是存在的
    auto i = S.begin();
    for(; i!= S.end(); i++)
    {
        if((*i)->getsName() == sName)
            break;
    }
    if(i == S.end())
    {
        cout<<"TakeCour: Student Not Existed"<<endl;
        return;
    }
    //判断这门课程是否已经存在于这名学生的选课表中，理想情况不存在
    auto j = (*i)->sChoice.begin();
    for(; j != (*i)->sChoice.end(); j++)
    {
        if((*j).getcName() == cName)
            break;
    }
    if(j != (*i)->sChoice.end())
    {
        cout<<"TakeCour: Course Already Existed In Student's Choice"<<endl;
        return;
    }
    else
    {
        (*i)->sChoice.push_back(c);
    }
    cout<<"Take Cour Successfully"<<endl;
    /*for(auto temp : (*i).sChoice)
        cout<<temp.getcName()<<endl;*/
}

void System::ExitCourse(string sName,string cName)
{
    //判断这名学生是否存在与学生信息表中，理想情况是存在的
    auto i = S.begin();
    for(; i!= S.end(); i++)
    {
        if((*i)->getsName() == sName)
            break;
    }
    if(i == S.end())
    {
        cout<<"ExitCour: Student Not Existed"<<endl;
        return;
    }
    //判断这门课程是否已经存在于这名学生的选课表中，理想情况是存在的
    auto j = (*i)->sChoice.begin();
    for(; j != (*i)->sChoice.end(); j++)
    {
        if((*j).getcName() == cName)
            break;
    }
    if(j == (*i)->sChoice.end())
    {
        cout<<"ExitCourse: The Course Not Existed in Student's Chioce"<<endl;
        return;
    }
    else
    {
        (*i)->sChoice.erase(j);
    }
    cout<<"Exit Cour Successfully"<<endl;
}

void System::SearchCourse(string sName) //查找学生的对应课程
{
    //判断这名学生是否存在与学生信息表中，理想情况是存在的
    auto i = S.begin();
    for(; i!= S.end(); i++)
    {
        if((*i)->getsName() == sName)
            break;
    }
    if(i == S.end())
    {
        cout<<"Print Cour: Student Not Existed"<<endl;
        return;
    }
    
    for(auto j = (*i)->sChoice.begin(); j != (*i)->sChoice.end(); j++)
        cout<<(*j).getcName()<<"; ";
    cout<<endl;
    cout<<"Print Cour Successfully"<<endl;
}

void System::SearchStudent(string cName) //查找修读某门课程的学生
{
    for(auto i = S.begin(); i != S.end(); i++)
    {
        for(auto j = (*i)->sChoice.begin(); j != (*i)->sChoice.end(); j++)
        {
            if((*j).getcName() == cName)
            {
                cout<<(*i)->getsName()<<"; "<<endl;
                break;
            }
        }
    }
    cout<<"Print Stu Successfully"<<endl;
}
void System::DisplayCour()
{
    cout<<"For Courses: "<<endl;
    for (auto i = C.begin(); i != C.end(); i++)
    {
        cout<<(*i).getcName()<<" "<<(*i).getcScore()<<endl;
    }
    cout<<"Display Successfully"<<endl;
}
void System::DisplayStu()
{
    cout<<"For Students: "<<endl;
    for(auto i = S.begin(); i != S.end(); i++)
    {
        cout<<(*i)->SaveFile();
        for(auto j = (*i)->sChoice.begin(); j != (*i)->sChoice.end(); j++)
        {
            cout<<(*j).getcName()<<" "<<(*j).getGrade();
        }
        cout<<endl;
    }
    cout<<"Display Successfully"<<endl;
}
