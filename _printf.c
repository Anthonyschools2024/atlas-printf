#include "main.h"
#include <stddef.h>
#include <stdarg.h>

int _print(const char *format, ...)
{
    va_list ap;
    int char_len = 0;

    va_start (ap, format);

    if (format == NULL)
        return (-1);

    while (*format != '\0')
    {
       if (*format == '%')
       {
           format++;
           len += output_cases(format, ap);
       }
       else
           len += write(STDOUT_FILENO, &(*format), :);
       format++;
   }
   va_end(ap);
   return (char_len);

}   