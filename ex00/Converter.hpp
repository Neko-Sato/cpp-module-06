/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 07:23:18 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:02:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONVERTER_HPP__
#define __CONVERTER_HPP__

#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

#include "ConvertException.hpp"

enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

Type checkType(const char *str);

char convertToChar(const std::string &str);
int convertToInt(const std::string &str);
float convertToFloat(const std::string &str);
double convertToDouble(const std::string &str);

template <typename T> std::string charLiteral(T value) {
  if (std::numeric_limits<T>::has_infinity && std::isinf(value))
    return "impossible";
  if (std::numeric_limits<T>::has_quiet_NaN && std::isnan(value))
    return "impossible";
  const char &c = static_cast<char>(value);
  if (std::isprint(c))
    return ("'" + std::string(1, c) + "'");
  return ("Non displayable");
}

template <typename T> std::string intLiteral(T value) {
  if (std::numeric_limits<T>::has_infinity && std::isinf(value))
    return "impossible";
  if (std::numeric_limits<T>::has_quiet_NaN && std::isnan(value))
    return "impossible";
  const int &i = static_cast<int>(value);
  std::stringstream ss;
  ss << i;
  return (ss.str());
}

template <typename T> std::string floatLiteral(T value) {
  const float &f = static_cast<float>(value);
  std::stringstream ss;
  ss << std::showpoint << f << "f";
  return (ss.str());
}

template <typename T> std::string doubleLiteral(T value) {
  const float &d = static_cast<double>(value);
  std::stringstream ss;
  ss << std::showpoint << d;
  return (ss.str());
}

#endif
