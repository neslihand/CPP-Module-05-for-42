/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:15:41 by ndogan            #+#    #+#             */
/*   Updated: 2025/04/25 12:35:28 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) , target("Default"){
	std::cout << "PresidentialPardonForm Default constructor called!" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target) : AForm("PresidentialPardonForm", 25, 5) , target(_target){
	std::cout << name << " PresidentialPardonForm constructor called!" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target){
	std::cout << name << " PresidentialPardonForm copy constructor called!" << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		this->isSigned = other.isSigned;
		this->requiredToExecute = other.requiredToExecute;
		this->requiredToSign = other.requiredToSign;
	}
	std::cout << name << " PresidentialPardonForm copy assignment operator called!" << std::endl;
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << name << " PresidentialPardonForm destructor called!" << std::endl;
};

void PresidentialPardonForm::executeAction() const{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};