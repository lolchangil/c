//16진수 입력시 아스키코드로 출력
//ex)0x67616c662f706d742f ->  galf/pmt
//포너블할때 쉬우라고 만듬
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void ascii(char * str) {
	char ascii = 0x00;
	int i = 0;
	while(1){
		if (str[i * 2 + 2] == '\n' || str[i * 2 + 2] == '\0') {
			break;
		}
		str[i * 2 + 2] = (str[i * 2 + 2] > '9') ? str[i * 2 + 2] - 'a' + 10 : str[i * 2 + 2] - '0';
		str[i * 2 + 3] = (str[i * 2 + 3] > '9') ? str[i * 2 + 3] - 'a' + 10 : str[i * 2 + 3] - '0';
		str[i*2+2] = str[i * 2 + 2] << 4;
		ascii = ascii | str[i * 2 + 2];
		ascii = ascii | str[i * 2 + 3];
		putc(ascii, stdout);
		ascii = 0x00;
		i++;
	}
}
int main(void) {
	char str[19];
	fgets(str, sizeof(str), stdin);
	ascii(str);
	return 0;
}