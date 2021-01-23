#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}
void solve(char* str,int nums1,int nums2,int nums3,int number)
{
        while(*str != '\0')
    {
        if(isdigit(*str))
        {
            number = *str - 48;
            push(number);
        }
        else
        {
            nums1 = pop();
            nums2 = pop();
            switch(*str)
            {
            case '+':
            {
                nums3 = nums1 + nums2;
                break;
            }
            case '-':
            {
                nums3 = nums2 - nums1;
                break;
            }
            case '*':
            {
                nums3 = nums1 * nums2;
                break;
            }
            case '/':
            {
                nums3 = nums2 / nums1;
                break;
            }
            }
            push(nums3);
        }
        str++;
    }
}
int main()
{
    char exp[20];
    char *str;
    int nums1,nums2,nums3,number;
    printf("Enter the expression : ");
    scanf("%s",exp);
    str = exp;
    solve(str,nums1,nums2,nums3,number);
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
