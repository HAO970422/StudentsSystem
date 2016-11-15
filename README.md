# SelectClassSystem
目录：1、实验要求
     2、需求分析：
     3、实验功能
     4、代码文件解析
     5、操作说明
     6、遇到的困难及解决方案
     7、注意事项

1、实验要求：本次实验要求实现一个学生选课管理系统，完成课程信息管理、学生信息以及所选课程管理等相关功能。

2、需求分析: （1）学生的管理需要设计一个学生类，包括学生信息（里面有选修课程的一个列表）和相应功能操作。对于学生类，还可以采用继承机制将学生分为本科生和研究生（已实现）；（2）课程的管理需要一个课程类，包括课程名、学分等信息和相应成员函数，对于课程我没有设置子类，因为要考虑到计算学分绩，而如果按照老师的建议设置成要求的三种子类，不容易计算学分绩，故舍弃老师建议的方案；（3）对于选课来说，应该设计一个主控类来实现，主控类包括一个学生列表和课程列表，在主控类中实现学生选课的功能以及其他的输出操作。

3、实验功能：
（1）对于学生，个人信息有姓名、学号、类型（本科生or研究生）、导师、选修的课程表，对于研究生还有其研究领域。实现的功能有从文件中读取学生、保存学生信息到文件、添加学生、删除学生、按照姓名排序、按照学号排序。（注：学号作为关键字具有唯一性）
（2）对于课程：一门课程包括课程名、学分、成绩（默认为0）三个信息，功能操作有从文件中读取课程、保存课程信息到文件、添加课程、删除课程。
（3）对于选课：有按照学生姓名和课程名选修某门课、按照学生学号退选某门课、查询某名学生的选修课程、查询选修某门课的所有学生、计算某名学生的学分绩。
（4）另外实现的功能有打印学生信息，打印课程信息。

4、代码文件解析：Student.h和Student.cpp文件为学生类的定义和实现，包括其子类的定义实现；Course.h和Course.cpp文件是课程类的定义和实现；System.h和System.cpp是主控类，main.cpp不用解释

5、操作说明：User Command As Follows: 
	addStu [Name] [No.] [Type] [Instructor]: Add a UGStudent
	addStu [Name] [No.] [Type] [Mentor] [Field]: Add a GStudent
	delStu [No.]: Delete a student
	saveStu [Filename]: Save Students to File
	sortStuName: Sort Student by Name
	sortStuNo: Sort Student by No.
	addCour [Name] [Score]: Add a Course
	delCour [Name]: Delete a Course
	saveCour [Filename]: Save Courses to File
	takeCour [SName] [CName]: Take a Course For the Studnet
	exitCour [SName] [CName]: Exit a Course For the Student
	printCour [SName]: Display the student's courses
	printStu [CName]: Display students who take the course
	quit: Quit System
	displatStu: Display Students's Data
	displayCour: Display Courses's Data
	setGrade: Set a student's grade
	calAchieve: Calculate a Student's School Achieve
	man: Display User Command Mannal

6、遇到的困难：(1)对于要求里提到的把选课类设为学生类的继承子类不是很理解，认为这个虽可以设置成子类，但是不利于逻辑的结构的理解，并且程序没有较好的扩展性，所以把选课的列表加入学生类，这样虽然可能访问有点繁琐，但有利于理解。（2）有返回值的虚函数在基类Student中是否要实现，怎么实现？方案一：实现子类的虚函数，此程序中运行证明无法实现动态绑定。方案二：设置成无需实现的虚函数，即纯虚函数。但是我要定义一个Student对象为元素的数组，而虚函数无法创建对象。综上所述，我陷入了困境。在此，感谢张晨浩的帮助和提醒，将数组设成以Student＊为元素。（3）以基类指针为对象的数组如何添加新建的派生类对象的元素。这一点借鉴了上次Assignment4文献管理作业中老师提供的代码。

7、注意：检查代码时，读取文件的路径还需您再次设置，两个示例格式的文件我已上传，请照此修改，谢谢。
