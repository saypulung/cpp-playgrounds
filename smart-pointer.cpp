#include <iostream>
#include <memory> // 1 - add include memory which is include shared_ptr

using namespace std;

// 2 - define class first
class Person;
// 3 - declare custom data type for the pointer of class
typedef shared_ptr<Person> PersonPtr;

// 4 implement the class
class Person {
	private:
		int x = 0;
	public:
		void addAge() {
			x++;	
		}
		int getAge() {
			return x;
		}
};

// 7 let's see the implementation of smart pointer
// -> the actual pointer, it should declared as Person *p in the parameters
void setAge(PersonPtr p) {
	p->addAge();
}

// without pointer
void increaseAge(Person p) {
	// call twice to increase x
	p.addAge();
	p.addAge();
	p.addAge();
}

// with classic pointer
void tambahAge(Person *p){
	p->addAge();
	p->addAge();
}

int main() {
	cout<<"Using smart pointer"<<endl;
	PersonPtr p(new Person); // 5 use Person class with defined pointer
	cout<<p->getAge()<<endl; // 6 expected result: 0. The object p just declared without modification
	
	// let's modify by a procedure above with parameter PersonPtr
	setAge(p);
	cout<<p->getAge()<<endl; // 7 expected result: 1
	setAge(p);
	cout<<p->getAge()<<endl; // 8 expected result: 2
	
	// 2.1 call procedure implemented without pointer
	Person psn;
	increaseAge(psn);
	cout<<"------------------------"<<endl;
	cout<<"Without pointer: ";
	cout<<psn.getAge()<<endl; // 2.2 expected result is 0
	
	// 2.3 call procedure implemented with pointer
	tambahAge(&psn);
	cout<<"After call procedure with classic pointer: "; // 2.4 expected result: 2. Because the addAge called twice inside tambahAge
	cout<<psn.getAge()<<endl;
	return 0;
}