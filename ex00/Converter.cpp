/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 07:23:18 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:09:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include "ConvertException.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <limits>

Type checkType(const char *str) {
  if (!*str)
    return (INVALID);
  if (*str == '\'') {
    str++;
    while (*str && *str != '\'')
      str++;
    if (*str == '\'')
      if (!*++str)
        return (CHAR);
    return (INVALID);
  }
  if (!std::strncmp(str, "nan", 3)) {
    str += 3;
    goto type_of_decimal;
  }
  if (*str == '-' || *str == '+')
    str++;
  if (!std::strncmp(str, "inf", 3)) {
    str += 3;
    goto type_of_decimal;
  }
  while (std::isdigit(*str))
    str++;
  if (!*str)
    return (INT);
  if (*str == '.')
    str++;
  else
    return (INVALID);
  while (std::isdigit(*str))
    str++;
type_of_decimal:
  if (!*str)
    return (DOUBLE);
  if (*str == 'f')
    str++;
  if (!*str)
    return (FLOAT);
  return (INVALID);
}

char convertToChar(const std::string &str) {
  if (str.length() == 3)
    return (str[1]);
  throw ConvertException();
}

int convertToInt(const std::string &str) {
  errno = 0;
  long num = std::strtol(str.c_str(), NULL, 10);
  if (errno || num < std::numeric_limits<int>::min() ||
      num > std::numeric_limits<int>::max())
    throw ConvertException();
  return (static_cast<int>(num));
}

float convertToFloat(const std::string &str) {
  errno = 0;
  float num = std::strtof(str.c_str(), NULL);
  if (errno == ERANGE)
    throw ConvertException();
  return (num);
}

double convertToDouble(const std::string &str) {
  errno = 0;
  double num = std::strtod(str.c_str(), NULL);
  if (errno)
    throw ConvertException();
  return (num);
}
