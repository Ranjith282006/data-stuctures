#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

char stack[SIZE];
int top = -1;
void push(char ele){
 if(top >= SIZE-1){
    printf("stack overflow");
    return;
 }
stack[++top] = ele;
}

int pop(){
if(top == -1){
    printf("stack underflow");
    return '\0';
}
return stack[top--];
}

int pre(char sym){
if(sym == '^'){
    return (3);
}
else if(sym == '*' || sym == '/'){
    return (2);
}
else if(sym == '+'|| sym == '-'){
    return (1);
}
else{
    return (0);
}
}

int main(){
char infix[50],postfix[50];
char ch,elem;
int i = 0, j= 0;
printf("enter infix expression:  ");
scanf("%s",infix);

push('#');
while ((ch = infix[i++])!= '\0'){
    if(ch == '('){
        push(ch);
    }
    else if(isalnum(ch)){
        postfix[j++] = ch;
    }
    else if (ch == ')'){
        while(stack[top]!='(')
            postfix[j++]= pop();
        elem = pop();


    }
    else{
      while(pre(stack[top]) >= pre(ch))
        postfix[j++] = pop();
      push(ch);
    }
}
while (stack[top]!= '#')
    postfix[j++] = pop();
postfix[j] = '\0';
printf("\n postfix expression = %s\n", postfix);
return 0;

}
