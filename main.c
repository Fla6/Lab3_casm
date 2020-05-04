#include<stdio.h>
#include<stdlib.h>
#include<time.h>

extern void _delarr(int n, int k, int l);

int k,l;
enum num { n = 5 };
int mas[n][n];

void delarr(int n, int k, int l)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = l; j < n-1 ; j++)
        {
            mas[i][j] = mas[i][j+1];
        }
    }
 
    for(int i = k; i < n-1 ; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            mas[i][j] = mas[i+1][j];
        }
    }
}

int main(void)

{
    
printf("_____________________________________________\n");

printf("Enter the number of row: ");
scanf("%d", &k);

printf("Enter the number of сolumn: ");
scanf("%d", &l);


srand(time(0));
for (int i = 0; i < n; i++) 
{
    for (int j = 0; j < n; j++) 
    {
        mas[i][j] = rand() % 20;
    }
        
}
  

printf("The generated array:\n");
for (int i = 0; i < n; i++) 
{
    for (int j = 0; j < n; j++) 
    {
       printf("%d ", mas[i][j]);
    }
    putchar('\n');
}
       
printf("_____________________________________________\n");

//вот функция?
// delarr(n, k, l);
_delarr(n, k, l);
    
printf("The new array:\n");

for (int i = 0; i < n-1; i++) 
{
    for (int j = 0; j < n-1; j++)
    { 
       printf("%d ", mas[i][j]);
    }
    putchar('\n');
}
return 0;

}