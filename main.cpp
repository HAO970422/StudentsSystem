//
//  main.cpp
//  StudentsSystem
//
//  Created by 张昊 on 16/11/9.
//  Copyright © 2016年 张昊. All rights reserved.
//

#include "System.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    System sys("/Users/zhao/Vscode/C++/StudentsSystem/ReadStu.txt", "/Users/zhao/Vscode/C++/StudentsSystem/ReadCour.txt");
    
    while(1)
    {
        cout<<"@User Command$ ";
        string command;
        getline(cin, command);
        vector<string> token;
        string::size_type begin = command.find_first_of(" ");
        while(begin <= command.length())
        {
            token.push_back( command.substr(0, begin) );
            command.erase(0, begin+1);
            begin = command.find_first_of(" ");
        }
        token.push_back(command);
        //for(auto i : token)
        //    cout<<i<<endl;
        
        if(token[0] == "addStu")
        {
            if(token[3] == "UG")
                sys.AddStudent(token[1], token[2], token[3],token[4]);
            else if(token[3] == "G")
                sys.AddStudent(token[1], token[2], token[3],token[4], token[5]);
            continue;
        }
        else if(token[0] == "delStu")
        {
            sys.DelStudent(token[1]);
            continue;
        }
        else if(token[0] == "saveStu")
        {
            sys.SaveStudents(token[1]);
            continue;
        }
        else if(token[0] == "sortStuName")
        {
            sys.SortByName();
            continue;
        }
        else if(token[0] == "sortStuNo")
        {
            sys.SortByNo();
            continue;
        }
        else if(token[0] == "addCour")
        {
            sys.AddCourse(token[1], stoi(token[2]));
            continue;
        }
        else if(token[0] == "delCour")
        {
            sys.DelCourse(token[1]);
            continue;
        }
        else if(token[0] == "saveCour")
        {
            sys.SaveCourse(token[1]);
            continue;
        }
        else if(token[0] == "takeCour")
        {
            sys.TakeCourse(token[1], token[2]);
            continue;
        }
        else if(token[0] == "exitCour")
        {
            sys.ExitCourse(token[1], token[2]);
            continue;
        }
        else if(token[0] == "printCour")
        {
            sys.SearchCourse(token[1]);
            continue;
        }
        else if(token[0] == "printStu")
        {
            sys.SearchStudent(token[1]);
            continue;
        }
        else if(token[0] == "displayStu")
        {
            sys.DisplayStu();
            continue;
        }
        else if(token[0] == "displayCour")
        {
            sys.DisplayCour();
            continue;
        }
        else if(token[0] == "quit")
        {
            break;
        }
        else if(token[0] == "man")
        {
            cout<<"User Command As Follows: "<<endl;
            cout<<"     addStu [Name] [No.] [Type] [Instructor]: Add a UGStudent"<<endl;
            cout<<"     addStu [Name] [No.] [Type] [Mentor] [Field]: Add a GStudent"<<endl;
            cout<<"     delStu [No.]: Delete a student"<<endl;
            cout<<"     saveStu [Filename]: Save Students to File"<<endl;
            cout<<"     sortStuName: Sort Student by Name"<<endl;
            cout<<"     sortStuNo: Sort Student by No."<<endl;
            cout<<"     addCour [Name] [Score]: Add a Course"<<endl;
            cout<<"     delCour [Name]: Delete a Course"<<endl;
            cout<<"     saveCour [Filename]: Save Courses to File"<<endl;
            cout<<"     takeCour [SName] [CName]: Take a Course For the Studnet"<<endl;
            cout<<"     exitCour [SName] [CName]: Exit a Course For the Student"<<endl;
            cout<<"     printCour [SName]: Display the student's courses"<<endl;
            cout<<"     printStu [CName]: Display students who take the course"<<endl;
            cout<<"     man: Display User Command Mannal"<<endl;
            cout<<"     quit: Quit System"<<endl;
            cout<<"     displatStu: Display Students's Data"<<endl;
            cout<<"     displayCour: Display Courses's Data"<<endl;
            cout<<"     setGrade: Set a student's grade"<<endl;
            cout<<"     calAchieve: Calculate a Student's School Achieve"<<endl;
        }
        else if(token[0] == "setGrade")
        {
            sys.SetGrade(token[1], token[2], stoi(token[3]));
        }
        else if(token[0] == "calAchieve")
        {
            sys.CalAchieve(token[1]);
        }
        else
        {
            cout<<"Command: command not valid"<<endl;
            continue;
        }
    }
    return 0;
}
