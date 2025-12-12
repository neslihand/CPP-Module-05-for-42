/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:29:47 by ndogan            #+#    #+#             */
/*   Updated: 2025/05/06 14:11:06 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default Form"), requiredToSign(42), requiredToExecute(42), isSigned(false){
	std::cout << "Default Form constructor called!" << std::endl;
};

Form::Form(const std::string &_name, int _requiredToSign, int _requiredToExecute): 
	name(_name), requiredToSign(_requiredToSign), requiredToExecute(_requiredToExecute), isSigned(false){
	std::cout << _name << " Form constructor called!" << std::endl;
	if (_requiredToSign < MAX_GRADE || _requiredToExecute < MAX_GRADE)
		throw GradeTooHighException();
	else if (_requiredToSign > MIN_GRADE || _requiredToExecute > MIN_GRADE)
		throw GradeTooLowException();
};

Form::Form(const Form& other): name(other.name), requiredToSign(other.requiredToSign),
	requiredToExecute(other.requiredToExecute), isSigned(other.isSigned){
	std::cout << name << " Form copy constructor called!" << std::endl;
};

Form& Form::operator=(const Form& other){
	if (this != &other){
		this->isSigned = other.isSigned;
	}
	std::cout << name << " Form copy assignment operator called!" << std::endl;
	return *this;
};

Form::~Form(){
	std::cout << name << " Form destructor called!" << std::endl;
};

std::string Form::getName() const{
	return name;
}

bool Form::getIsSigned() const{
	return isSigned;
};

int Form::getRequiredToSign() const{
	return requiredToSign;
};

int Form::getRequiredToExecute() const{
	return requiredToExecute;
}

void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= requiredToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
};

const char* Form::GradeTooHighException::what() const throw(){
	return "Error: Grade is too high!";
};

const char* Form::GradeTooLowException::what() const throw(){
	return "Error: Grade is too low!";
};

std::ostream& operator<<(std::ostream &out, const Form &f){
	out << f.getName() << ", signed: "<< f.getIsSigned() <<", grade required to sign: " <<
	f.getRequiredToSign() << ", grade required to execute: " << f.getRequiredToExecute();
    return out;
};
