/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 01:01:09 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 01:15:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base *generate(void) {
  srand(time(NULL));
  switch (rand() % 3) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  default:
    return NULL;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}
void identify(Base &p) {
  for (int i = 0; i < 3; i++) {
    try {
      switch (i) {
      case 0:
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        break;
      case 1:
        dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        break;
      case 2:
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        break;
      default:
        std::cout << "Unknown" << std::endl;
        break;
      }
    } catch (std::bad_cast &e) {
    }
  }
}
