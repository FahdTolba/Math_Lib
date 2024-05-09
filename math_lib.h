#ifndef __MATH_LIB_H
#define __MATH_LIB_H

#include<stdlib.h>
#include<string.h>
#include<iostream>

#include"bits.h"

using namespace std;

class Arith_Entity{
public:
	virtual void operator = (int) = 0;
//	void op ++() = 0; //how would define increment for a polynomial or Matrix??
				//	addition to the field unity element ?

//	void op ++(int) = 0;//postfix version

//	Arith_Entity op + (Arith_Entity) = 0;
//	Arith_Entity op - (Arith_Entity) = 0;
//	Arith_Entity op / (Arith_Entity) = 0;
//	Arith_Entity op * (Arith_Entity) = 0;

/*
	+= 
	-=
	*=
	/=
	==
*/
};


class Number : public Arith_Entity{

	private:

	Number(); //no ambiguity please

//	Number(Number&); // no need to disable automatic copy for now
//	Number operator = (Number N); //no need to disable automatic copy for now

	int size; //size in bytes
	char *data;	//big-endian (network-byte order)
	int tmp;

//	Number operator = (Number N); //no need to disable automatic copy for now

	
	public:


	Number(int bsize) : size(bsize){ 	printf("constructor called: size is %d\n",size);
		data = (char *)malloc(size);
		memset(data, 0, size);
	}

	void operator = (Number N);//override automatic copy

	void operator = (int n);
	
	bool operator == (int temp){
		return !memcmp(data, &temp, sizeof(temp));
	}

	bool operator == (Number N2) {
		return size == N2.size && (!memcmp(data, N2.data, size));
	}

	bool identical (Number N2){
		return *this == N2 && data == N2.data; 
	}

	Number operator ++(int);

	void print(){
		if(size > sizeof(long)){
			cout<<"print()ing numbers larger than 8 bytes currently not supported"<<endl;
			//first numbers in hexadecimal representation
			//then support decimal printing
			//Itoa(), requires modulo division,
			//which requires division and subtraction
			//so we will to define a generic version of itoa() ( Itoa() )
		}else{
			cout<<"size is "<<size<<endl;
			cout<<"data is "<<(int)host_endian(*data)<<endl;
			printf("printf(): data is %d\n", *data);
			printf("data is %p and holding value %d\n", data, *data);
		}
	}	
};





class Polynomial : public Arith_Entity{

//	op +()	//addition to the finite field's unity element
//	public:
};

//class Matrix : Arith_Entity{
//      op +()  //addition to the finite field's unity element
//};

#endif //__MATH_LIB_H
