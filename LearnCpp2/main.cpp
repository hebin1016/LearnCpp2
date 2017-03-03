//
//  main.cpp
//  LearnCpp2
//
//  Created by hebin on 2017/2/8.
//  Copyright © 2017年 hebin. All rights reserved.
//

#include <iostream>
using namespace std;

/*
//构造函数的属性初始化列表
//student teacher 构造函数，析构函数执行顺序：越晚创建越早析构
class Teacher{
    private:
    char *name;
    public:
    Teacher(char* name){
        this->name=name;
        cout<<"teacher有参构造函数"<<endl;
    }
    ~Teacher(){
        cout<<"teacher析构函数"<<endl;
    }
    char* getName(){
        return name;
    }
};

class Student{
private:
    int id;
    //属性对象赋值
    Teacher t1;
    public:
    Student(int id,char *t1_n):t1(t1_n){
        cout<<"student有参构造函数"<<endl;
        this->id=id;
    }
    ~Student(){
        cout<<"student析构函数"<<endl;
    }
public:
    void myprint(){
        cout<<t1.getName()<<endl;
    }
};

int main(int argc, const char * argv[]) {
    
    Student stu(10,"hank");
    stu.myprint();
//    Student stu1(10,"hello","hi");
//    stu1.myprint();
//    
    
    return 0;
}
*/

/*
//c++ 通过new(delete)动态内存分配
class Teacher{
    private:
    char *name;
    public:
    Teacher(char* name){
        this->name=name;
        cout<<"teacher有参构造函数"<<endl;
    }
    ~Teacher(){
        cout<<"teacher析构函数"<<endl;
    }
    char* getName(){
        return name;
    }
    void setName(char *name){
        this->name=name;
    }
};

void func(){
    //c++
    //new创建堆内存地址指针
    Teacher *t1=new Teacher("fuck");
    cout<<t1->getName()<<endl;
    //释放
    delete(t1);
    
    //c:不会调用构造析构函数
    Teacher* t2=(Teacher*)malloc(sizeof(Teacher));
    t2->setName("sky");
    cout<<t2->getName()<<endl;
    free(t2);
}


int main(){
    func();
    
    //数组类型
    //c
    int *list=(int*)malloc(sizeof(int)*10);
    list[0]=20;
    free(list);
    
    //c++
    int *list1=new int[10];
    list1[0]=89;
    delete[] list;//释放数组
    
    return 0;
}
*/

/*
//static关键字:静态属性和函数
class Teacher{
    public:
    char *name;
    //计数器
    static int total;
    public:
    Teacher(char* name){
        this->name=name;
        cout<<"teacher有参构造函数"<<endl;
    }
    ~Teacher(){
        cout<<"teacher析构函数"<<endl;
    }
    char* getName(){
        return name;
    }
    void setName(char *name){
        this->name=name;
    }
    //静态函数不能访问非静态属性
    static void count(){
        total++;
        //cout<<total<<endl;
    }
};
//静态属性初始化赋值放在全局位置
int Teacher::total=30;

int main(){
    Teacher::total++;
    //直接通过类名访问
    Teacher::count();
    
    Teacher t1("juicy");
    t1.count();
    cout<<Teacher::total<<endl;
    
    return 0;
}
*/


/*
//类的大小
class  A{
    public:
    int i;
    int j;
    int k;
};
class B{
    public:
    int i;
    int j;
    int k;
    void myprint(){
        cout<<"打印"<<endl;
    }
};

int main(){
    cout<<sizeof(A)<<endl;
    cout<<sizeof(B)<<endl;

    //c/c++ 内存分区：栈，堆，全局（静态，全局），常量区（字符串），程序代码区（函数）
    //普通属性与结构体相同的内存布局（普通属性才算类的大小）
    
    
    return 0;
}
*/

/*
//this指针
//函数存在程序代码区，是共享的，必须要有能够标示当前对象是谁的方法
class Teacher{
    private:
    char *name;
    int age;
    public:
    Teacher(char* name,int age){
        this->name=name;
        this->age=age;
        cout<<"teacher有参构造函数"<<endl;
        printf("this:%p\n",this);
    }
    ~Teacher(){
        cout<<"teacher析构函数"<<endl;
    }
    char* getName(){
        return name;
    }
    void setName(char *name){
        this->name=name;
    }
    //常函数，修饰的是this指针，该函数内不能修改属性的值，和this的值
    //即不能改变指针的值，也不能改变指针指向的内容
    void myprint() const{
        cout<<this->name<<","<<this->age<<endl;
    }
    
    void myprint2(){
        cout<<this->name<<","<<this->age<<endl;
    }
};

int main(){
    Teacher t1("jack",20);
    printf("t1:%p\n",&t1);
    const Teacher t2("jack1",25);
    printf("t2:%p\n",&t2);
    t1.myprint();
    //常函数，防止数据成员被非法访问
    //常量对象不能调用非常量函数，非常量对象可以调用常量函数和非常量函数
    //t2.myprint2();
    return 0;
}
*/

/*
//友元函数
class A{
    private:
    int i;
    public:
    A(int i){
        this->i=i;
    }
    void myprint(){
        cout<<i<<endl;
    }
    //友元函数
    friend void modify_i(A*p,int i);
};
//友元函数的实现，在友元函数中可以访问私有属性
void modify_i(A*p,int i){
    p->i=i;
};

int main(){
    
    A* a=new A(20);
    modify_i(a, 50);
    a->myprint();
    delete a;

    return 0;
}
 */

/*
//友元类
class A{
    //友元类
    friend class B;
    private:
    int i;
    public:
    A(int i){
        this->i=i;
    }
    void myprint(){
        cout<<i<<endl;
    }
    
};

class B{
    public:
    //B这个友元类可以访问A的所有成员
    void accessAny(){
        a.i=20;
    }
    private:
    A a;
};
int main(){
    return 0;
}
*/

/*
//运算符重载
class Point{
    public:
    int x;
    int y;
    public:
    Point(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }
    void myprint(){
        cout<<this->x<<","<<this->y<<endl;
    }
};

//重载+号
Point operator+(Point &p1,Point &p2){
    Point p3((p1.x+p2.x),(p1.y+p2.y));
    return p3;
}

int main(){
    Point p1(10,20);
    Point p2(10,20);
    Point p3=p1+p2;
    p3.myprint();
    return 0;
}
*/

/*
//成员函数运算符重载
class Point{
    public:
    int x;
    int y;
    public:
    Point(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }
    void myprint(){
        cout<<this->x<<","<<this->y<<endl;
    }
    //成员函数重载+号
    Point operator+(Point &p2){
        Point p3((this->x+p2.x),(this->y+p2.y));
        return p3;
    }
};



int main(){
    Point p1(10,20);
    Point p2(10,20);
    
    //运算符重载，本质还是函数调用
    Point p3=p1+p2;
    p3.myprint();
    return 0;
}
*/

//当属性私有时，通过友元函数完成运算符重载
class Point{
    friend Point operator+(Point &p1,Point &p2);
    private:
    int x;
    int y;
    public:
    Point(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }
    void myprint(){
        cout<<this->x<<","<<this->y<<endl;
    }
    
};

//成员函数重载+号
Point operator+(Point &p1,Point &p2){
    Point p3((p1.x+p2.x),(p1.y+p2.y));
    return p3;
}

int main(){
    Point p1(10,20);
    Point p2(10,20);
    
    //运算符重载，本质还是函数调用
    Point p3=p1+p2;
    p3.myprint();
    return 0;
}
