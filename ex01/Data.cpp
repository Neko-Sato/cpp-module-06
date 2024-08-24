/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:28:49 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:48:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <ostream>

Data::Data(int data) : data(data) {
}

Data::~Data() {
}

Data::Data(Data const &other) : data(other.data) {
}

Data &Data::operator=(Data const &other) {
  if (this == &other) {
    data = other.data;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, Data const &data) {
  os << "<Data " << data.data << ">";
  return os;
}