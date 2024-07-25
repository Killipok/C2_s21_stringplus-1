#include "../s21_string.h"

// ----- получение флагов, ширины и длины -----
const char *s21_get_flags(const char *format, TOKEN *token) {
  while (format) {
    if (*format == '-')
      token->minus = 1;
    else if (*format == '+')
      token->plus = 1;
    else if (*format == ' ')
      token->space = 1;
    else if (*format == '#')
      token->hash = 1;
    else if (*format == '0')
      token->zero = 1;
    else
      break;  // выйти из цикла
    format++;
  }

  token->space = (token->space && !token->plus);  // нельзя '+' u ' '
  token->zero = (token->zero && !token->minus);   // нельзя '0' и '-'
  return format;
}

const char *s21_get_width(const char *format, int *width, va_list *args) {
  *width = 0;

  // (buf, "%*", 14) => * =14
  if (*format == '*') {
    *width = va_arg(*args, int);  // первое числа типа int
    format++;
  }

  // (buf, "%14.6d", 148) => '1'-> 1: '1' - '0' = 1
  // 1 iter: width = 0*10 => 0+('1' - '0') == 0 + (49 - 48) => 1
  while (format) {
    if ('0' <= *format && *format <= '9') {
      *width *= 10;
      *width += *format - '0';
    } else  // встречаем .
      break;
    format++;
  }

  return format;
}

const char *s21_get_length(const char *format, TOKEN *token) {
  //(buf, "%14.Ld", 148)
  // if (*format == 'L')  // long long
  //   token->length = 'L';
  if (*format == 'l')  // long
    token->length = 'l';
  else if (*format == 'h')  // short
    token->length = 'h';

  return format;
}

const char *s21_getting(TOKEN *token, const char *format, va_list *args) {
  format = s21_get_flags(format, token);                // флаги
  format = s21_get_width(format, &token->width, args);  // ширина

  if (*format == '.') {  // точность
    token->dot = 1;
    token->zero = 0;
    format++;
    format = s21_get_width(format, &token->precision, args);
  }

  format = s21_get_length(format, token);  // длина
  if (token->length != 0) format++;

  if (token->width < 0) {  // -14 (проверка, на всякий случай)
    token->width = -token->width;
    token->minus = 1;
  }
  return format;
}

// ------ спецификатор decimal -----
s21_size_t s21_get_size_to_decimal(TOKEN *token, long int num) {
  s21_size_t size = 0;  // размер строки (количество цифр)
  long int number = num;

  if (number < 0) number = -number;

  // (buf, "%d", 145) => size = 3
  while (number > 0) {
    number /= 10;
    size++;
  }
  // num = 0 (изначально)
  if (number == 0 && size == 0 &&
      (token->precision || token->width || token->space)) {
    size++;
  }
  // (buf, "%10.6d", 0)
  if ((s21_size_t)token->width > size) size = token->width;
  if ((s21_size_t)token->precision > size) size = token->precision;
  // (buf, "%10.6d", 0)
  if (token->space || token->plus || num < 0) {
    token->flag_to_size = 1;  // наличие space, plus, minus
    size++;
  }

  // (buf, "%d", 0)
  if (size == 0 && number == 0 && !token->precision && !token->width &&
      !token->space && !token->dot) {
    size++;
  }

  return size;
}

char s21_get_num_char(int num, int upper) {
  char flag = '0';
  switch (num) {
    case 10:
      flag = (char)('a' - upper * 32);
      break;
    case 11:
      flag = (char)('b' - upper * 32);
      break;
    case 12:
      flag = (char)('c' - upper * 32);
      break;
    case 13:
      flag = (char)('d' - upper * 32);
      break;
    case 14:
      flag = (char)('e' - upper * 32);
      break;
    case 15:
      flag = (char)('f' - upper * 32);
      break;
  }

  if (0 <= num && num <= 9) flag = (char)(num + 48);  // 48 == '0'

  return flag;
}

int s21_decimal_to_string(TOKEN token, long int num, char *str_to_num,
                          s21_size_t size_to_decimal) {
  int flag = 0;

  if (num < 0) {
    flag = 1;
    num = -num;
  }

  int i = 0;
  long int number = num;

  /*----- запись числа в буферный массив -----*/

  // (если число == 0) => (buf, "%d", 0) or (buf, "%.0d", 0)
  if ((number == 0 && (token.precision || token.width || token.space)) ||
      (number == 0 && (!token.precision || !token.width || !token.space))) {
    char symbol = number % token.number_system + '0';  // 48 = '0'
    str_to_num[i] = symbol;
    i++;
    size_to_decimal--;
    number /= 10;
  }

  // если число != 0
  while (number && str_to_num && size_to_decimal) {
    // 148 % 10 == '8'
    char symbol =
        s21_get_num_char(number % token.number_system, token.upper_case);
    str_to_num[i] = symbol;
    i++;
    size_to_decimal--;
    number /= 10;
  }  // для числа 148 str_to_num = '841'

  if (flag) num = -num;  // вернуть знак

  // проверка применимости флага 0
  if (token.precision - i > 0) {
    token.precision -= i;
    token.zero = 1;
  } else
    flag = 1;
  // нет мест под нули
  if (size_to_decimal == 1 && token.zero == 1 && token.flag_to_size == 1)
    token.zero = 0;

  // обработка флага 0
  while (token.zero && str_to_num &&
         (size_to_decimal - token.flag_to_size > 0) &&
         (token.precision || flag)) {
    if (size_to_decimal == 1 && token.flag_to_size == 1) break;
    str_to_num[i] = '0';
    i++;
    size_to_decimal--;
    token.precision--;
  }

  // обработка флагов +/-/space
  if (token.space && num >= 0 && size_to_decimal) {
    str_to_num[i] = ' ';
    i++;
    size_to_decimal--;
  }
  if (num < 0 && size_to_decimal) {
    str_to_num[i] = '-';
    i++;
    size_to_decimal--;
  }
  if (num > 0 && token.plus && size_to_decimal) {
    str_to_num[i] = '+';
    i++;
    size_to_decimal--;
  }

  // обработка ситуации, когда осталось свободное место в строке
  // поставить оставшееся свободное место пробелами
  if (size_to_decimal > 0 && token.minus == 0) {
    while ((size_to_decimal - token.flag_to_size > 0) && str_to_num) {
      str_to_num[i] = ' ';
      i++;
      size_to_decimal--;
    }
  }

  return i;
}

char *s21_print_decimal(char *str, TOKEN token, va_list *args) {
  long int num = 0;

  if (token.length == 'l')
    num = (long int)va_arg(*args, long int);
  else if (token.length == 'h')
    num = (short int)va_arg(*args, int);
  else
    num = (int)va_arg(*args, int);

  s21_size_t size_to_decimal = s21_get_size_to_decimal(&token, num);
  char *str_to_num = malloc(sizeof(char) * size_to_decimal);

  if (str_to_num) {  // удалоcь ли выделить память
    int i = s21_decimal_to_string(token, num, str_to_num,
                                  size_to_decimal);  // число 148 -> 841

    for (int j = i - 1; j >= 0; j--) {
      *str = str_to_num[j];
      str++;
    }
    while (i < token.width) {  // заполнение оставщееся места пробелами
      *str = ' ';
      str++;
      i++;
    }
  }

  if (str_to_num) free(str_to_num);

  return str;
}

// ----- спецификатор u/X/x/o -----
TOKEN s21_set_number_system(TOKEN token, char format) {
  if (format == 'o')
    token.number_system = 8;
  else if (format == 'x' || format == 'X')  // 0xfff 0XFFF
    token.number_system = 16;

  if (format == 'X') token.upper_case = 1;

  return token;
}

s21_size_t s21_get_buf_size_unsigned_decimal(TOKEN *token,
                                             unsigned long int num) {
  s21_size_t size = 0;  // размер строки (количество цифр)
  unsigned long int number = num;

  // (buf, "%d", 145) => size = 3
  while (number > 0) {
    number /= token->number_system;
    size++;
  }
  // num = 0 (изначально)
  if (number == 0 && size == 0 &&
      (token->precision || token->width || token->space)) {
    size++;
  }
  // (buf, "%10.6d", 0)
  if ((s21_size_t)token->width > size) size = token->width;
  if ((s21_size_t)token->precision > size) size = token->precision;
  // (buf, "%10.6d", 0)
  if (token->space || token->plus) {
    token->flag_to_size = 1;  // наличие space, plus, minus
    size++;
  }

  // (buf, "%d", 0)
  if (size == 0 && number == 0 && !token->precision && !token->width &&
      !token->space && !token->dot) {
    size++;
  }

  return size;
}

int s21_unsigned_decimal_to_string(char *buf, TOKEN token,
                                   unsigned long int num,
                                   s21_size_t size_to_num) {
  int i = 0;
  int flag = 0;
  unsigned long int number = num;

  //(buf, "%x", 0xfa1) => fa1
  //(buf, "%#x", 0xfa1) => 0xfa1
  if (token.hash && token.number_system == 8) {
    token.flag_to_size = 1;  // зарезервировать под один символ (0)
  } else if (token.hash && token.number_system == 16) {
    token.flag_to_size = 2;  // зарезервировать под 2 символа (0x)
  }

  /*----- запись числа в буферный массив -----*/

  // (если число == 0) => (buf, "%d", 0) or (buf, "%.0d", 0)
  if ((number == 0 && (token.precision || token.width || token.space)) ||
      (number == 0 && (!token.precision || !token.width || !token.space))) {
    char symbol = number % token.number_system + '0';  // 48 = '0'
    buf[i] = symbol;
    i++;
    buf--;
    number /= token.number_system;
  }

  // если число != 0
  while (number && buf && size_to_num) {
    // 148 % 10 == '8'
    char symbol =
        s21_get_num_char(number % token.number_system, token.upper_case);
    buf[i] = symbol;
    i++;
    size_to_num--;
    number /= token.number_system;
  }  // для числа 148 str_to_num = '841'

  if (flag) num = -num;  // вернуть знак

  // проверка применимости флага 0
  if (token.precision - i > 0) {
    token.precision -= i;
    token.zero = 1;
  } else
    flag = 1;
  // нет мест под нули
  if (size_to_num == 1 && token.zero == 1 && token.flag_to_size == 1)
    token.zero = 0;

  // обработка флага 0
  while (token.zero && buf && (size_to_num - token.flag_to_size > 0) &&
         (token.precision || flag)) {
    if (size_to_num == 1 && token.flag_to_size == 1) break;
    buf[i] = '0';
    i++;
    size_to_num--;
    token.precision--;
  }

  // обработка флагов +/-/space
  // if (token.hash && token.number_system == 8) {
  //   buf[i] = '0';
  //   i++;
  //   size_to_num--;
  // } else if (token.hash && token.number_system == 16 && token.upper_case) {
  //   buf[i] = 'X';
  //   i++;
  //   size_to_num--;
  //   buf[i] = '0';
  //   i++;
  //   size_to_num--;
  // } else if (token.hash && token.number_system == 16 && !token.upper_case) {
  //   buf[i] = 'x';
  //   i++;
  //   size_to_num--;
  //   buf[i] = '0';
  //   i++;
  //   size_to_num--;
  // }

  // поставить оставшееся свободное место пробелами
  if (size_to_num > 0 && token.minus == 0) {
    while ((size_to_num - token.flag_to_size > 0) && buf) {
      buf[i] = ' ';
      i++;
      size_to_num--;
    }
  }
  return i;
}

char *s21_print_u(char *str, TOKEN token, char format, va_list *args) {
  // u/X/x/o
  unsigned long int num = 0;

  // 0213 213 0x213
  if (format == 'l')
    num = (unsigned long int)va_arg(*args, unsigned long int);
  else if (format == 'h')
    num = (unsigned short)va_arg(*args, unsigned int);
  else
    num = (unsigned int)va_arg(*args, unsigned int);

  s21_size_t size_to_num = s21_get_buf_size_unsigned_decimal(&token, num);
  char *buffer = malloc(sizeof(char) * size_to_num);

  if (buffer) {
    int i = s21_unsigned_decimal_to_string(buffer, token, num, size_to_num);
    if (i > 0) {
      for (int j = i - 1; j >= 0; j--) {
        *str = buffer[j];
        str++;
      }
      while (i < token.width &&
             *(str + 1)) {  // заполнение оставщееся места пробелами
        *str = ' ';
        str++;
      }
    }
  }

  if (buffer) free(buffer);

  return str;
}

// ------ спецификатор с ------
char *s21_print_c(char *str, TOKEN token, int symbol) {
  char *ptr = s21_NULL;
  // int i = 0;

  //(buf, "%c", q)
  while (token.width > 1 && !token.minus) {  // пробелы слева
    *str = ' ';
    str++;
    // i++;
    token.width--;
  }

  if (symbol <= 127) {  // только сиволы asci
    *str = symbol;
    str++;
    // i++;
    while (token.width > 1 && token.minus) {  // прбелы справа
      *str = ' ';
      str++;
      // i++;
      token.width--;
    }
    ptr = str;
  }

  return ptr;
}

// ------ спецификатор s ------
// char *s21_print_s(char *str, TOKEN token, va_list *args) {
//   int i = 0;
//   char *start_ptr = str;
//   char *string = va_arg(*args, char *);

//   if (string) {
//     int blank = 0;  // кол-во пробелов

//     // ----- найти количество пробелов

//     //(buf, "%2s", "world") => width = 5, blank = 0
//     // если ширина не указана или ширина меньше длины строки
//     if ((s21_size_t)token.width < s21_strlen(string))
//       token.width = s21_strlen(string);

//     //если ширина больше длины строки, то пустое место заполняем проелами
//     // blank - количество пробелов
//     //(buf, "%7s", "world") => 2 пробела
//     blank = token.width - s21_strlen(string);

//     //если точность не указана
//     //(buf, "%7s", "world")
//     if (token.precision == 0) token.precision = token.width;

//     //если точность меньше изначальной ширины
//     //(buf, "%7.6s", "world")
//     if (token.precision != 0 && token.precision < token.width)
//       blank = token.width - token.precision;

//     // ----- заполняем пробелы слева (если нет флага -)
//     while (blank > 0 && !token.minus) {
//       *str = ' ';
//       str++;
//       i++;
//       blank--;
//     }

//     // ----- запишем строку int->char
//     while (*str != '\0' && token.precision != 0 && *(str + 1)) {
//       *str = *string;
//       str++;
//       string++;
//       i++;
//       token.precision--;
//     }

//     // если флаг - (заполняем пробелами справа)
//     while (blank > 0 && token.minus) {
//       *str = ' ';
//       str++;
//       i++;
//       blank--;
//     }
//   } else {  // не удолось считать строку
//     //(buf, "Hello 7s", 14) => "Hello (null)"
//     str = s21_memcpy(str, "(null)", 6);
//     str += 6;
//     i += 6;
//   }

//   return start_ptr + i;
// }

char *s21_parser(char *str, char *src, const char *format, TOKEN token,
                 va_list *args) {
  if (*format == 'd' || *format == 'i') {
    str = s21_print_decimal(str, token, args);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    token = s21_set_number_system(token, *format);
    str = s21_print_u(str, token, *(format - 1), args);
  } else if (*format == 'c') {
    int symbol = va_arg(*args, int);  // (int)'s'
    str = s21_print_c(str, token, symbol);
    // } else if (*format == 's') {
    //   str = s21_print_s(str, token, args);
  } else if (*format == '%') {
    str = s21_print_c(str, token, '%');
  }

  if (!str) *src = '\0';

  return str;
}

// format = %[flags][width][.precision][length]specifier
int s21_sprintf(char *str, const char *format, ...) {
  char specifiers[] = "cdifsugGeExXop%";
  char *src = str;
  int result = 0;

  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      if (*(format + 1)) {
        format++;
        TOKEN token = {0};
        token.number_system = 10;
        format =
            s21_getting(&token, format, &args);  // get: flags, width, length
        while (!s21_strchr(specifiers, *format)) format++;

        str = s21_parser(str, src, format, token, &args);
      } else {
        result = -1;
        break;
      }
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  *str = '\0';
  va_end(args);

  if (result != -1) result = str - src;

  return result;
}
