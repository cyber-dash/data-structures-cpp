#ifndef CYBER_DASH_LEI_PERSON_H
#define CYBER_DASH_LEI_PERSON_H

#include <iostream>

using namespace std;

class person {
public:
	person(long id, string name) : ID_number(id), Name(name) {}

	person& operator = (long k1) {
		ID_number = k1; 
		return *this;
	}

	friend bool operator < (const person &ptr, long int k1) {
		return ptr.ID_number < k1 ? true : false;
	}

	friend bool operator == (const person &ptr, long int k1) {
		return ptr.ID_number == k1 ? true : false;
	}

	friend bool operator > (const person &ptr, long int k1) {
		return ptr.ID_number > k1 ? true : false;
	}

	friend bool operator < (long int k1, const person &ptr) {
		return k1 < ptr.ID_number ? true : false;
	}

	friend bool operator == (long int k1, const person &ptr) {
		return k1 == ptr.ID_number ? true : false;
	}

	friend bool operator > (long int k1, const person &ptr) {
		return k1 > ptr.ID_number ? true : false;
	}

	friend bool operator < (const person &ptr1, const person &ptr2){
		return (ptr1.ID_number < ptr2.ID_number);
	}

	friend bool operator > (const person &ptr1, const person &ptr2){
		return (ptr1.ID_number > ptr2.ID_number);
	}

	friend bool operator == (const person &ptr1, const person &ptr2){
		return (ptr1.ID_number == ptr2.ID_number);
	}

	long getKey(void) {
		return ID_number;
	}

	long getIDNumber(void) {
		return ID_number;
	}

	void setIDNumber(long k1) {
		ID_number = k1;
	}

	string getName(void) {
		return Name;
	}

	void setName(string value) {
		Name = value;
	}

        friend ostream& operator << (ostream &out, person &p){
                out << "ID: " << p.ID_number << " name:" << p.Name;
                return out;
        }

private:
	long int ID_number;
	string Name;
};

#endif //CYBER_DASH_LEI_PERSON_H
