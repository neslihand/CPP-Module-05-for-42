/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:17:29 by ndogan            #+#    #+#             */
/*   Updated: 2025/04/22 16:02:35 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	try {
        std::cout << "--- Bureaucrat and Form Creation Tests ---" << std::endl;
        Bureaucrat b1("Alice", 1);  // En yüksek yetkili memur
        Bureaucrat b2("Bob", 72); // Orta seviye memur
        Bureaucrat b3("Charlie", 1); // En düşük yetkili memur

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;

        std::cout << "\n--- Creating Forms ---" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("John Doe");
        PresidentialPardonForm pardon("Prisoner X");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n--- Signing Forms ---" << std::endl;
        b1.signForm(shrubbery);
        b2.signForm(robotomy);
        b3.signForm(pardon); // Charlie'nin derecesi çok düşük, hata almalı

        std::cout << "\n--- Executing Forms ---" << std::endl;
        b1.executeForm(shrubbery);
        b1.executeForm(robotomy);
        b1.executeForm(pardon);

        std::cout << "\n--- Testing Exceptions ---" << std::endl;
        Bureaucrat lowRank("Dave", 140);
        lowRank.executeForm(shrubbery); // Yetkisi yetersiz, hata fırlatmalı

        std::cout << "\n--- Destructors ---" << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	return 0;
}