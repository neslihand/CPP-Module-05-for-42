/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:14:27 by ndogan            #+#    #+#             */
/*   Updated: 2025/06/11 14:37:00 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) , target("Default"){
	std::cout << "RobotomyRequestForm Default constructor called!" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target): AForm("RobotomyRequestForm", 72, 45) , target(_target){
	std::cout << name << " RobotomyRequestForm constructor called!" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target){
	std::cout << name << " RobotomyRequestForm copy constructor called!" << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm other){
	if (this != &other){
		this->isSigned = other.isSigned;
		this->requiredToExecute = other.requiredToExecute;
		this->requiredToSign = other.requiredToSign;
	}
	std::cout << name << " RobotomyRequestForm copy assignment operator called!" << std::endl;
	return *this;
};
RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << name << " RobotomyRequestForm destructor called!" << std::endl;
};

void RobotomyRequestForm::executeAction() const{
	std::cout << "Bzzzzzzzt! Vrrrrr!\n" << std::endl;
	srand(time(NULL));
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << target << "." << std::endl;
    }
};
