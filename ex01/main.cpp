/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:28:17 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:41:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  {
    Data data(2);
    std::cout << "data: " << data << std::endl;
    std::cout << "data ptr: " << &data << std::endl;
    uintptr_t serial = Serializer::serialize(&data);
    std::cout << "serial: " << serial << std::endl;
    Data *deserial = Serializer::deserialize(serial);
    std::cout << "deserial ptr: " << deserial << std::endl;
    std::cout << "deserial data: " << *deserial << std::endl;
  }
  {
    Data data(-10);
    std::cout << "data: " << data << std::endl;
    std::cout << "data ptr: " << &data << std::endl;
    uintptr_t serial = Serializer::serialize(&data);
    std::cout << "serial: " << serial << std::endl;
    Data *deserial = Serializer::deserialize(serial);
    std::cout << "deserial ptr: " << deserial << std::endl;
    std::cout << "deserial data: " << *deserial << std::endl;
  }
  return 0;
}