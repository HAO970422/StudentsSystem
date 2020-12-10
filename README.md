# StudentsSystem

C++ 入门小项目: 学生选课管理系统，完成课程信息管理、学生信息管理以及选课管理等功能。

## 分析
1. 学生管理需要设计一个学生类，包括学生信息 (内含选修课程的一个列表) 和相应功能操作。对于学生类，还可采用继承机制将学生分为本科生和研究生。
2. 课程管理需要一个课程类，包括课程名、学分等信息和相应成员函数。
3. 对选课来说，应该设计一个主控类来实现，主控类包括一个学生列表和课程列表，在主控类中实现学生选课的功能以及其他的输出操作。

## 功能
1. 对于学生，个人信息有姓名、学号、类型(本科生or研究生)、导师、选修的课程表，对于研究生还有其研究领域。实现的功能有从文件中读取学生、保存学生信息到文件、添加学生、删除学生、按照姓名排序、按照学号排序。（注：学号作为关键字具有唯一性） 
2. 对于课程，一门课程包括课程名、学分、成绩（默认为0）三个信息，功能操作有从文件中读取课程、保存课程信息到文件、添加课程、删除课程。
3. 对于选课，有按照学生姓名和课程名选修某门课、按照学生学号退选某门课、查询某名学生的选修课程、查询选修某门课的所有学生、计算某名学生的学分绩。
4. 另外实现的功能有打印学生信息，打印课程信息。

## 代码文件
1. Student.h和Student.cpp文件为学生类的定义和实现，包括其子类的定义实现； 
2. Course.h和Course.cpp文件是课程类的定义和实现；
3. System.h和System.cpp是主控类；
4. main.cpp不解释

## 操作说明
User Command As Follows:
1. addStu [Name] [No.] [Type] [Instructor]: Add a UGStudent
2. addStu [Name] [No.] [Type] [Mentor] [Field]: Add a GStudent 
3. delStu [No.]: Delete a student 
4. saveStu [Filename]: Save Students to File 
5. sortStuName: Sort Student by Name 
6. sortStuNo: Sort Student by No. 
7. addCour [Name] [Score]: Add a Course 
8. delCour [Name]: Delete a Course 
9. saveCour [Filename]: Save Courses to File 
10. takeCour [SName] [CName]: Take a Course For the Student 
11. exitCour [SName] [CName]: Exit a Course For the Student 
12. printCour [SName]: Display the student's courses 
13. printStu [CName]: Display students who take the course 
14. quit: Quit System 
15. displatStu: Display Students's Data 
16. displayCour: Display Courses's Data 
17. setGrade: Set a student's grade 
18. calAchieve: Calculate a Student's School Achieve 
19. man: Display User Command Mannal 

## 注意
读取文件的路径需自己设置，两个示例格式的文件已上传。
