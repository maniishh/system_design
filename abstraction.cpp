#include<iostream>
#include<string>
using namespace std;

//real life car

class car{
    public:
    virtual void startEngine()=0; //pure virtual function
    virtual void shiftGear(int gear)=0; //pure virtual function
    virtual void accelerate()=0;    
    virtual void brake()=0; 
    virtual void stopEngine()=0; 
    virtual ~car(){}; //virtual destructor
};
class sportsCar:public car{
     public:
     string brand;
     string model;
     bool isEngineOn;
     int currentSpeed=0;
     int currentGear=0;
    sportsCar(string b,string m){
        this->brand=b;
        this->model=m;
        this->isEngineOn=false; 
        currentSpeed=0;
        currentGear=0;//neutral
    }
    void startEngine(){
        if(!isEngineOn){
            isEngineOn=true;
            cout<<"Engine started for "<<brand<<" "<<model<<endl;
        }else{
            cout<<"Engine is already on for "<<brand<<" "<<model<<endl;
        }
    }
    void shiftGear(int gear){
        if(isEngineOn){
            currentGear=gear;
            cout<<"Shifted to gear "<<currentGear<<" for "<<brand<<" "<<model<<endl;
        }else{
            cout<<"Cannot shift gear. Engine is off for "<<brand<<" "<<model<<endl;
        }
    }
    void accelerate(){
        if(isEngineOn){
            currentSpeed+=10;
            cout<<"Accelerating "<<brand<<" "<<model<<". Current speed: "<<currentSpeed<<" km/h"<<endl;
        }else{
            cout<<"Cannot accelerate. Engine is off for "<<brand<<" "<<model<<endl;
        }
    }
    void brake(){
        if(isEngineOn && currentSpeed>0){
            currentSpeed-=10;
            if(currentSpeed<0) currentSpeed=0;
            cout<<"Braking "<<brand<<" "<<model<<". Current speed: "<<currentSpeed<<" km/h"<<endl;
        }else{
            cout<<"Cannot brake. Engine is off or car is already stopped for "<<brand<<" "<<model<<endl;
        }
    }
    void stopEngine(){
        if(isEngineOn){
            isEngineOn=false;
            currentSpeed=0;
            currentGear=0;
            cout<<"Engine stopped for "<<brand<<" "<<model<<endl;
        }else{
            cout<<"Engine is already off for "<<brand<<" "<<model<<endl;
        }
    }

};
//main function to test the implementation
int main(){
    sportsCar myCar("Ferrari","488 Spider");
    myCar.startEngine();
    myCar.shiftGear(1);
    myCar.accelerate();
    myCar.accelerate();
    myCar.brake();
    myCar.stopEngine();
    return 0;
}
