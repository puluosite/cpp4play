#include <iostream>

using namespace std;


class Base {
public:
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
	Derive d;
	d.healthVal();
	Base b;
	b.healthVal();
	return 0;
}