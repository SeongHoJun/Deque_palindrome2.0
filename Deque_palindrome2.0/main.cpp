#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_QUEUE_SIZE 50

char data[MAX_QUEUE_SIZE];
int front = 0;
int rear = 1;
int count = 0;

void add_front(char c);
void add_rear(char c);
char delete_front(void);
char delete_rear(void);
int is_empty(void);
int is_palindrome(char *string);

int main() 
{
	int check = 0;
	
	while (1)
	{
		// get input
		char string[MAX_SIZE];
		printf("Enter a string (or input 'exit'): ");
		gets_s(string, sizeof(string));
		if (strcmp(string, "exit") == 0)
			return 0;
		// print output
		if (is_palindrome(string) == 1)
		{
			printf("%s is a palindrome.\n", string);
		}
		else
		{
			printf("%s is not a palindrome\n",string);
		}
		front = 0;
		rear = 1;
	}
}

int is_palindrome(char *string) 
{
	// 덱에 스트링 추가
	int i = 0;
	char c = string[i++];
	while (c != NULL) 
	{
		if (isalpha(c)) 
		{
			add_front(tolower(c));
		}
		c = string[i++];
	}

	// 덱으로 회문 검사
	while (!(is_empty() || count == 1)) 
	{
		int a = delete_front();
		int b = delete_rear();

		if (a != b)
			return 0;
	}
	return 1;
}

void add_front(char c) 
{
	data[front] = c;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	count++;
}
void add_rear(char c) 
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = c;
	count++;
}

char delete_front(void) 
{
	front = (front + 1) % MAX_QUEUE_SIZE;
	char c = data[front];
	count--;
	return c;
}

char delete_rear(void) 
{
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	char c = data[rear];
	count--;
	return c;
}

int is_empty(void) 
{
	if (count == 0) 
	{
		return 1;
	}
	return 0;
}