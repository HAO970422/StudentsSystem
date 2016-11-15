//
//  Course.cpp
//  StudentsSystem
//
//  Created by 张昊 on 16/11/9.
//  Copyright © 2016年 张昊. All rights reserved.
//

#include "Course.h"

Course::Course()
{
    
}

Course::Course(string name, int score)
{
    cName = name;
    cScore = score;
    Grade = 0;
}

Course::~Course()
{
    
}

string Course::getcName() const
{
    return cName;
}

int Course::getcScore() const
{
    return cScore;
}

int Course::getGrade() const
{
    return Grade;
}

void Course::setGrade(int g)
{
    Grade = g;
}
