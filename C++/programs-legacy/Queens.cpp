#include <stdio.h>
#include <stdlib.h>
 
#define max 8
 
 
int queen[max], sum=0;
 
void show()
{
    int i;
    for(i = 0; i < max; i++)
    {
         printf("(%d,%d) ", i, queen[i]);
    }
    printf("\n");
    sum++;
}
 
int check(int n)
{
    int i;
    for(i = 0; i < n; i++) 
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
        {
            return 1;
        }
    }
    return 0;
}
 
void put(int n)
{
    int i;
    for(i = 0; i < max; i++)
    {       
        queen[n] = i; 
        if(!check(n))
        {           
            if(n == max - 1)
            {
                show(); 
            }         
            else
            {
                put(n + 1);
            }
        }
    }
}

 
int main()
{
    put(0); 
    printf("%d", sum);
    system("pause");
    return 0;
}
