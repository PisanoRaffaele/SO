#include <stdio.h>

typedef void (*ActionPtrFn)(char c);

ActionPtrFn currentState;

void s1(char c);
void s2(char c);
void s3(char c);
void s4(char c);
void s4R(char c);
void s5(char c);

char s4Arg;

void s1(char c)
{
	printf("s1\n");
	if(c != 'a')
		currentState = s1;
	else if(c == 'a')
		currentState = s2;
}

void s2(char c)
{
	printf("s2\n");
	if(c != 'U')
		currentState = s1;
	else if(c == 'U')
		currentState = s3;
}

void s3(char c)
{
	printf("s3\n");
	currentState = s4;
}

void s4(char c)
{
	printf("s4\n");
	int count = 0;
	currentState = s4R;
	s4Arg = c;
}

void s4R(char c)
{
	s4Arg--;
	if (s4Arg <= 0)
	{
		printf("s4\n");
		currentState = s5;
	}
	else
		currentState = s4R;
}

void s5(char c)
{
	printf("s5\n");
	if(c != 'a')
		currentState = s1;
	else if(c == 'a')
		currentState = s2;
}


int main(int argc, char** argv) {
  currentState = s1;
  char input;
  while(1) {
	scanf("%c", &input);
	getchar();
	fflush(NULL);
    (*currentState)(input);
  }
}

