#include "main.h"

/**
 * _printf - custom printf function
 *
 * @format: character string
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
        int char_cnt = 0;
        va_list args;

        va_start(args, format);

        while (*format)
        {
                if (*format == '%' && format[1])
                {
                        format++;
                        if (*format == 'c' || *format == '%')
                                putchar(va_arg(args, int)), char_cnt++;
                        else if (*format == 's')
                        {
                                char *s = va_arg(args, char *);

                                while (s && *s)
                                        putchar(*s), s++, char_cnt++;
                        }
			else
                        {
                                putchar('%'), char_cnt++;
                                putchar(*format), char_cnt++;
                        }
                }
 		else
                        putchar(*format), char_cnt++;
                format++;
        }
        va_end(args);
        return (char_cnt);
}
