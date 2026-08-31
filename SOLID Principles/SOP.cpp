/*SRP means a class should have one responsibility and
 therefore one reason to change. For example,
  I would not put salary calculation, database operations, 
  and report generation inside the Employee class. 
  I would separate them into different classes.*/

#include<bits/stdc++.h>
using namespace std;
//❌ BAD example
class Employee{
    public:
    void calculateSalary(){
///calculate slary
    }

    void savetodatabse()
{
    //save to database
}
void generateRport(){
    //report genrate
}
};
// this class is doing 3  diffrent jobs
//if database logic changes ,Employee changes, so it has multiple reason to change

//✅ better design

class Employee{
    public:
    void calculateSalary(){
        //salary calculate
    }
};

class EmployeeRepository{
    public:
    void reportgenerate( Employee employee){
        //report generate
    }
};

class SavetoDB{
    public:
    void saveToDB( Employee employee){
        //save to database
    }
};
//now each class has one responsibility

