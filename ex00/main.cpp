/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:17:36 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:14:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <ostream>

/*
    This assignment sucks,
    I'm so desperate for perfection.
    I just need to see an example. Just examples.
    I don't want to be distracted by this issue, not anymore.
*/

int main(int argc, char *argv[]) {
  try {
    if (argc != 2)
      throw std::invalid_argument("Illegal number of arguments");
    ScalarConverter::convert(argv[1]);
    return 0;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
