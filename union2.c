#include<stdio.h>
typedef struct bits
{
	unsigned char bit_0 : 1;
	unsigned char bit_1 : 1;
	unsigned char bit_2 : 1;
	unsigned char bit_3 : 1;
	unsigned char bit_4 : 1;
	unsigned char bit_5 : 1;
	unsigned char bit_6 : 1;
	unsigned char bit_7 : 1; //최상위 비트
}BIT;
typedef union bitdata
{
	BIT bit_data;
	unsigned char byte_data;
}BITDATA;
int main(void){
	BITDATA i;
	i.byte_data = 0x1;
	printf("%d%d%d%d%d%d%d%d\n", i.bit_data.bit_7,i.bit_data.bit_6,i.bit_data.bit_5,i.bit_data.bit_4,i.bit_data.bit_3,i.bit_data.bit_2,i.bit_data.bit_1,i.bit_data.bit_0);
	return 0;
}
