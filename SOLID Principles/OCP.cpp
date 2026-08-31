/*OCP means software should be open for extension but
 closed for modification. For example, instead of using 
 if-else for every payment type, I can create a PaymentMethod 
 interface and create separate classes for UPI, Card, and 
 PayPal. Adding PayPal doesn't require changing existing payment
  logic.*/
  //❌BAD design
#include<bits/stdc++.h>
using namespace std;
class payment{
    public:
    void pay(string type){
        if(type=="UPI"){
        //upi payment
        }
else if(type=="CARD"){
    //card payment
}
    }

};
//for add more payment method we have to modify the class each time things will get messy

// Better design, create an abstraction
class payment{
    public:
   virtual void pay()=0;
   virtual ~payment()=default;
};
class UPI : public payment{
    public :
    void pay() override{
        //upi payment
    }
};
class Card : public payment{
    public :
    void pay() override{
        //card payment
    }
};

class payPal : public payment{
    public :
    void pay() override{
        //paypal payment
    }
};
//we can add more mthod without modifying payment class