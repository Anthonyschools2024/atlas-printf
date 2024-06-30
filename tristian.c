#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int print_char(int c)	/* this is used to print characters */
						/* it's just the same as putchar */
{
	return write(1, &c, 1);
}

int print_int(int num)
{
	if (num >= 0 && num <= 9)
	{
		return (num + '0');
	}
	else
	{
		return (0);
	}
}

int print_string(char *str)	/*prints a string*/
{
	int index = 0;

	while (str[index] != '\0')
	{
		print_char(str[index]);
		index++;
	}
	return (0);
}

int print_any(char find, va_list arglist)	/* this function is where we will
put all the cases of what we need to print. */
{
	int count;

	count = 0;

	if (find == 'c')	/* so if find finds c, which is a char, it will print the character */
		count += print_char(va_arg(arglist, int));
	if (find == 's')	/*finds s it prints a string */
		count += print_string(va_arg(arglist, char*));
	if (find == 'i' || find == 'd')
		count += print_int(va_arg(arglist, int));
	if (find == '%')
		count++;
			if (find == '%')
			print_char('%');
			print_char('\n');
			count++;
	return (count);
}

int _printf(const char *format, ...)	/* printf function*/
{
	int count;

	va_list arglist;	/*list holding the arguments*/

	va_start(arglist, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')	/*if it finds a % symbol, it will move to the print_any function and check what comes next*/
			count += print_any(*(++format), arglist);
		else	/*if its not % */
			count += write(1, format, 1);	/*it will write 1-standard output, store in format, 1-byte*/
		++format;	/*then move to the next*/
	}
	return (count);
}

int main()
{
	char string[] = "I ate tacos for lunch";

	_printf("I have to %c", 'P');	/* printf "I have to P" */
	_printf("%s", string);
	_printf("Need to print a %%");
	_printf("I had %i tacos, and pooped %d tamales", 5, 875);
}
