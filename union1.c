#include<stdio.h>
typedef union data
{
	int idata;
	float fdata;
}DATA;
typedef struct twoDATA
{
	char i;
	DATA data;
}TDATA;
int main(void) {
	TDATA test;
	printf("0이면 int, 1이면 float임 > ");
	scanf("%hhd", &(test.i));
	if (test.i == 0) {
		scanf("%d", &(test.data.idata));
	}
	printf("%d", test.data.idata);
	printf("%f", test.data.fdata);
	return 0;
}
