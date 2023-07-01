#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50

int top;
char infix[MAX], postfix[MAX], stack[MAX];
void push(char);
char pop();
int precedence(char);//Returns priority of an operator
void convert();
int evaluate();

int main()
{
	top=-1;
	printf("Enter the infix equation ");
	fflush(stdin);
	scanf("%[^\n]s",infix);
	convert();
	printf("\nThe postfix expression is %s",postfix);
	printf("\nThe result is %d", evaluate() );
	return 0;
}

void convert()
{
	int p=0,pre,i,len,p1,p2;
	char n;

	for(i=0;infix[i]!='\0';i++)
	{
		switch(infix[i])
		{
			case '(':
				push(infix[i]);//push('(')
				break;
			case ')':
				while(1)
				{
					n=pop();
					if(n=='(')
						break;
					postfix[p]=n;
					p++;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while(1)
				{
					if(top==-1 || stack[top]=='(')
					{
						push(infix[i]);
						break;
					}

					else
					{
						p1=precedence(infix[i]);//Precedence of current operator
						p2=precedence(stack[top]);//Precedence of operator on top of stack
						if(p1>p2)
						{
							push(infix[i]);
							break;
						}

						else
						{
							postfix[p]=pop();
							p++;
						}
					}
				}//End of the infinite loop
				break;

			default://When the character is an operand
				postfix[p]=infix[i];
				p++;
				//break;
		}	//End of switch
	}	//End of for loop

	while(top!=-1)
		postfix[p++]=pop();
	postfix[p]='\0';
}

void push(char s)
{
	top++;
	stack[top]=s;
}

char pop()
{
	char a;
	if(top==-1)
		printf("Stack underflow");

	else
	{
		a=stack[top];
		top--;
		return a;
	}
}

int precedence(char s)
{
	switch(s)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
}

int evaluate ()
{
	int i,a,b,temp,result;

	for(i=0;postfix[i]!='\0';i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			push(postfix[i]-48);
		
        else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+':
					temp=b+a;
					break;
				case '-':
					temp=b-a;
					break;
				case '*':
					temp=b*a;
					break;
				case '/':
					temp=b/a;
					break;
				case '^':
					temp=pow(b, a);
					break;
			}	//End of switch
			push(temp);
		}	//End of else
	}	//End of for 
	
    result=pop();

	return result;
}

