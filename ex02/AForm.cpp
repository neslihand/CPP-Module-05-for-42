/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:29:47 by ndogan            #+#    #+#             */
/*   Updated: 2025/02/24 15:44:41 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default AForm"), isSigned(false), requiredToSign(42), requiredToExecute(42){
	std::cout << "Default AForm constructor called!" << std::endl;
};

AForm::AForm(const std::string &_name, int _requiredToSign, int _requiredToExecute): 
	name(_name), isSigned(false){
	if (_requiredToSign < MAX_GRADE || _requiredToExecute < MAX_GRADE)
		throw GradeTooHighException();
	else if (_requiredToSign > MIN_GRADE || _requiredToExecute > MIN_GRADE)
		throw GradeTooLowException();
	this->requiredToExecute = _requiredToExecute;
	this->requiredToSign = _requiredToSign;
	std::cout << _name << " AForm constructor called!" << std::endl;
};

AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), requiredToSign(other.requiredToSign),
	requiredToExecute(other.requiredToExecute){
	std::cout << name << "AForm copy constructor called!" << std::endl;
};

AForm& AForm::operator=(const AForm& other){
	if (this != &other){
		this->isSigned = other.isSigned;
		this->requiredToExecute = other.requiredToExecute;
		this->requiredToSign = other.requiredToSign;
	}
	std::cout << name << "AForm copy assignment operator called!" << std::endl;
	return *this;
};

AForm::~AForm(){
	std::cout << name << "AForm destructor called!" << std::endl;
};

std::string AForm::getName() const{
	return name;
}

bool AForm::getIsSigned() const{
	return isSigned;
};

int AForm::getRequiredToSign() const{
	return requiredToSign;
};

int AForm::getRequiredToExecute() const{
	return requiredToExecute;
}

void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= requiredToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
};

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned)
		throw FormIsNotSignedException();
	else if (executor.getGrade() > this->requiredToExecute)
		throw GradeTooLowException();
	this->executeAction();
};

const char* AForm::FormIsNotSignedException::what() const throw(){
	return "Error: This form is not signed!";
};

const char* AForm::GradeTooHighException::what() const throw(){
	return "Error: Grade is too high!";
};

const char* AForm::GradeTooLowException::what() const throw(){
	return "Error: Grade is too low!";
};

std::ostream& operator<<(std::ostream &out, const AForm &f){
	out << f.getName() << ", signed: "<< f.getIsSigned() <<", grade required to sign: " <<
	f.getRequiredToSign() << ", grade required to execute: " << f.getRequiredToExecute();
    return out;
};
