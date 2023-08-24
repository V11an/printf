#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int charCount = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            
            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    charCount++;
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        charCount++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    charCount++;
                    break;
                }
                default: {
                    // Ignore unsupported format specifiers
                    break;
                }
            }
        } else {
            putchar(*format);
            charCount++;
        }

        format++;
    }

    va_end(args);
    return charCount;
}

int main() {
    _printf("Hello, %s! My favorite character is %c%%.\n", "Alice", 'A');
    return 0;
}

