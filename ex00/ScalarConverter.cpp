/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:03:27 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:10:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConvertException.hpp"
#include "Converter.hpp"

#include <iostream>

template <typename T> void putLiterals(T value) {
  std::cout << "char: " << charLiteral(value) << std::endl;
  std::cout << "int: " << intLiteral(value) << std::endl;
  std::cout << "float: " << floatLiteral(value) << std::endl;
  std::cout << "double: " << doubleLiteral(value) << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
  switch (checkType(str.c_str())) {
  case CHAR:
    putLiterals(convertToChar(str));
    break;
  case INT:
    putLiterals(convertToInt(str));
    break;
  case FLOAT:
    putLiterals(convertToFloat(str));
    break;
  case DOUBLE:
    putLiterals(convertToDouble(str));
    break;
  case INVALID:
    throw ConvertException();
    break;
  }
}