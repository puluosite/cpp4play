#include <iostream>
#include <memory>

#include "cpp11test.h"

using namespace std;


class Base {
public:
	virtual ~Base() {cout<<"base dtor"<<endl;}

	int healthVal() const {
		cout<<"base pre"<<endl;
		int a = healthValImp();
		cout<<"base post"<<endl;
		return a;
	}
	

protected:
	virtual int healthValImp() const {
		cout<<"base health val imp"<<endl;
		return 1;
	}
};

class Derive: public Base {
public:
	virtual ~Derive() {cout<<"derive dtor"<<endl;}

	int healthVal() const {
		cout<<"derive pre"<<endl;
		int a = Base::healthValImp();
		//int a = Base::healthVal();
		cout<<"derive post"<<endl;
		return a;
	}
	

protected:
	virtual int healthValImp() const {
		cout<<"derive health val imp"<<endl;
		return 2;
	}
	
};

int main() {
	/*
	Derive d;
	d.healthVal();
	Base b;
	b.healthVal();
	*/

	
	shared_ptr<Base> pb1(new Derive());
	shared_ptr<Base> pb2(new Base());

	if (shared_ptr<Derive>pt = dynamic_pointer_cast<Derive>(pb1)) {
		cout<<"pb1 is a base pointer point to DERIVE class"<<endl;
	} else {
		cout<<"pb1 is a base pointer point to BASE class"<<endl;
	}

	if (shared_ptr<Derive>pt = dynamic_pointer_cast<Derive>(pb2)) {
		cout<<"pb2 is a base pointer point to DERIVE class"<<endl;
	} else {
		cout<<"pb2 is a base pointer point to BASE class"<<endl;
	}




	/*
	Base* pb1 = new Derive();
	Base* pb2 = new Base();

	if (Derive* pd = dynamic_cast<Derive*>(pb1)) {
		cout<<"pb1 is a base pointer point to DERIVE class"<<endl;
	} else {
		cout<<"pb1 is a base pointer point to BASE class"<<endl;
	}

	if (Derive* pd = dynamic_cast<Derive*>(pb2)) {
		cout<<"pb2 is a base pointer point to DERIVE class"<<endl;
	} else {
		cout<<"pb2 is a base pointer point to BASE class"<<endl;
	}

	
	delete pb1;
	delete pb2;
	*/


	Cpp11test c;
	c.runAuto();
	

	

	return 0;
}