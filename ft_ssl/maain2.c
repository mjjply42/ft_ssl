#include <stdio.h>

void show_mem_rep(char *start, int n)  
{ 
    int i; 
    for (i = 0; i < n; i++) 
         printf(" %.2x", start[i]); 
    printf("\n"); 
} 

int tobig_end(int a)
{
	int b;

	b = (((a & 0xFF) << 24)
		| ((a & 0xFF00) << 8)
		| ((a & 0xFF0000) >> 8)
		| ((a & 0xFF000000) >> 24));
	return (b);	
}
/*Main function to call above function for 0x01234567*/
int main() 
{ 
   int i = 0x01234567; 
   show_mem_rep((char *)&i, sizeof(i));
   i = tobig_end(i);
   show_mem_rep((char *)&i, sizeof(i));
   printf("I is now %#x\n", i);
   return 0; 
}
