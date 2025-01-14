#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef enum Stanje{code, com_s, com_l, com_b, com_e} stanje;


int main(int argc,const char **argv ) {

	FILE* in = fopen(argv[1], "r");
	FILE* out = fopen(argv[2], "w");

	if (!in)
	{
		return 1;
	}
	 
	char c;

	enum state s = code;

	while ((c = fgetc(in))!=EOF)
	{
		switch (s)
		{
			
		case code:
			if (c=='/')
			{
				s = com_s;
			}
			else
			{
				fputc(c, out);
			}
			break;
		case com_s:
			if (c=='/')
			{
				s = com_l;
			}
			else if (c=='*')
			{
				s = com_b;
			}
			else
			{
				fputc('/', out);
				fputc(c, out);
				s = code;
			}
			break;

		case com_l:
			if (c=='\n')
			{
				fputc(c, out);
				s = code;
			}
			break;
		case com_b:
			if (c=='*')
			{
				s = com_e;
			}
			break;
		case com_e:
			if (c=='/')
			{
				s = code;
			}
			else if (c!='*')
			{
				s = com_b;
			}
			break;

		}
	}

	fclose(in);
	fclose(out);

	return 0;
}