#ifndef VSE_STRING__H
#define VSE_STRING__H

#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end;   // позиция первого символа, после последнего символа слова
}WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
}BagOfWords;

static char stringBuffer[MAX_STRING_SIZE + 1];
static BagOfWords bag;
static BagOfWords bag2;

void assertString(const char *expected, char *got, char const *funcName, int line);

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

/* Возвращает отрицательное значение, если lhs располагается до rhs в лексикографическом порядке (как в словаре),
 * значение 0, если lhs и rhs равны,
 * иначе – положительное значение. */
int strcmp_(const char *lhs, const char *rhs);

/* Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource не включительно.
 * Возвращает указатель на следующий свободный фрагмент памяти в beginDestination */
char* copy(const char *beginSource, const char *endSource, char *beginDestination);

/* Записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource не включительно,
 * удовлетворяющие функции-предикату f.
 * Функция возвращает указатель на следующий свободный для записи фрагмент в памяти. */
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

/* Записывает по адресу beginDestination элементы из фрагмента памяти начиная с rBeginSource заканчивая rEndSource(rBegin >= rEnd),
 * удовлетворяющие функции-предикату f.
 * Функция возвращает значение beginDestination по окончанию работы функции. */
char* copyIfReverse(char *rBeginSource, const char *rEndSource, char *beginDestination, int (*f)(int));

/* Возвращает указатель на конец строки */
char* getEndOfString(char *s);

/* Сохраняет первое найденное слово в строке beginSearch по адресу word */
int getWord(char *beginSearch, WordDescriptor *word);

/* Сохраняет первое найденное слово с конца в строке начиная с rBeginSearch по rEndSource по адресу word,
 * (Не включительно)rEndSource <- rBeginSource */
int getWordBack(char *rBeginSource, const char *rEndSource, WordDescriptor *word);

/* Возвращает отрицательное число, если leftWord располагается до rightWord в лексикографическом порядке (как в словаре)
 * значение 0, если leftWord и rightWord равны,
 * иначе - положительное значение. */
int wordCmp(WordDescriptor leftWord, WordDescriptor rightWord);

/* Заполняет bagWord словами из строки s */
void getBagOfWords(BagOfWords *bagWords, char *s);

/* Возвращает 'истина' - если слово word является палиндромом,
 * иначе - 'ложь' */
int isPalindrome(WordDescriptor word);

/* Вывод слова word */
void outputWord(WordDescriptor word);

/* Записывает слово word по адресу destination */
void wordDescriptorToString(WordDescriptor word, char *destination);

#endif //VSE_STRING__H