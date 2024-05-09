#include"math_lib.h"


inc_byte(unsigned char byte){
	if byte == 0xff //max value
		carry = 1;
		byte = 0x00;
	else
		for each bit (from LSb to MSb) //find the LS zero bit and make it one, zero all ones in preceding LSbits
			if(bit == 0)
				bit <- 1;
				carry 0;
				break;
			else
				bit <- 0;
}

void operator = (Number N){ //override automatic copy

		if(size != N.size){
			data = (char *)realloc(data, N.size);
		}
		size = N.size;
	
		if(data && N.data)
			memcpy(data, N.data, size);
		else
			printf("no memory copied\n");
			//exception
}

void operator = (int n){ 
		//tmp = big_endian(n); //we use big_endian
		//memcpy(data, tmp, size);
		*data = n;
}
	
Number::operator ++(int){
	
	for each byte (or while carry == 1 (or true) )
		add byte to 1
		if carry == 1 (or true)
			
}

Number::Number operator + (Number N2){

	while N2.data != 0 //TODO: overload != operator (is it implicitly overloaded when == is overloaded?)
		increment(this) //increment N1 (caller)
		decrement(N2)	//TODO: overload -- decrement operator


}

Number::Number operator - (Number N2){

	add N1 (this) to two's complement of N2 //TODO: check plan
}


