//#include<stdlib.h>
#include"libft.h"
void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n--)
	{
		*c = '\0';
		c++;
	}
}

/*
#include <stdio.h>  //Для printf
#include <string.h>   //Для memset

int main (void)
{
   // Исходный массив
   unsigned char src[15]="1234567890";
 
   // Заполняем массив символом ‘1’
   //ft_memset (src, '1', 10);
   bzero(&src[4], 3);

   // Вывод массива src на консоль
   printf ("src: %s\n",src);

   return 0;
}
*/