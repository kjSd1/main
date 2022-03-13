#ifndef VSE_STRING__H
#define VSE_STRING__H

#include <stdlib.h>
#include <ctype.h>

/* Возвращает количество символов в строке */
size_t strLen(const char *s);

/* Возвращает указатель на первый элемент с кодом ch,
 * расположенным на ленте памяти между адресами begin и end не включая end.
 * Если символ не найден, возвращается адрес end */
char* find(char *begin, const char *end, int ch);

/* Возвращает указатель на первый символ, отличный от пробельных, или на первый ноль-символ,
 * расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом. */
char* findNonSpace(const char *begin);

/* Возвращает указатель на первый пробельный символ или на первый ноль-символ,
 * расположенный на ленте памяти начиная с адреса begin */
char* findSpace(const char *begin);

/* Возвращает указатель на первый справа символ, отличный от пробельных,
 * расположенный на ленте памяти, начиная с rBegin (последний символ строки, за которым следует ноль-символ)
 * и заканчивая rEnd (адрес символа перед началом строки)
 * Если символ не найден, возвращается адрес rEnd */
char* findNonSpaceReverse(char *rBegin, const char *rEnd);

/* Возвращает указатель на первый пробельный символ справа,
 * расположенный на ленте памяти, начиная с rBegin и заканчивая rend.
 * Если символ не найден, возвращается адрес rEnd */
char* findSpaceReverse(char *rBegin, const char *rEnd);

#endif //VSE_STRING__H
