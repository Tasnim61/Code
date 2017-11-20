#include <iostream>
using namespace std;

class Person{
    int age;
    char* pName;
 public:	 
    Person(): age(0), pName(0) {}
    Person(char* pName, int age): age(age), pName(pName) {}
	~Person() {}

    void Display() {
        printf("Name = %s Age = %d \n", pName, age);
    }
        
	void Shout() {
        printf("Ooooooooooooooooo");
    } 
};

//template <typename T>
template <class T>
class SP{
	T* ptr;
	int* refCount;

	void remove()
	{
		(*refCount)--;

		if(*refCount==0)
		{
			delete ptr;
			delete refCount;

			ptr = nullptr;
			refCount = 0;
		}
	}

	void copy(const SP<T>& obj)
	{
		ptr = obj.ptr;
		refCount = obj.refCount;
		++*refCount;
	}
public:
	
	SP(): ptr(0), refCount(nullptr) {}

	//constructor
	SP(T* ptrData) {
		ptr = ptrData;
		refCount = new int();
		*refCount = 1;
	}	

	//destructor
	~SP(){
		remove();
	}

	//copy constructor
	SP(const SP<T>& obj)
	{
		copy(obj);
	}

	//assignment operator
	SP<T>& operator=(const SP<T>& obj)
	{
		if(this == &obj)
			return *this;

		//delete first the existing pointers and then rassign those pointers
		if(refCount != nullptr)
			remove();

		copy(obj);

		return *this;
	}

	T* operator->() {
		return ptr;
	}

	T& operator*() {
		return *ptr;
	}	
};

int main()
{
	//no problem of dangling pointer
	char ch[]="Scott";
	SP<Person> p(new Person(ch, 25));
    p->Display();
    {
		//call copy constructor 
        SP<Person> q = p;
        q->Display();
        // Destructor of Q will be called here..

		//call assignment operator
		SP<Person> r;
		r = p;
        q->Display();
		//Destructor called for r
    }
    p->Display();
	return 0;
}

//source link:
//http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c
