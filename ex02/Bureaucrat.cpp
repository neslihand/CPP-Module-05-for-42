/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:46:38 by ndogan            #+#    #+#             */
/*   Updated: 2025/02/24 18:53:19 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(42){
	std::cout << "Bureaucrat default constructor called!" << std::endl;
};

Bureaucrat::Bureaucrat(std::string const &_name, int _grade) : name(_name){
	std::cout << "Bureaucrat "<< _name << " constructor called!" << std::endl;
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_grade > MIN_GRADE)
		throw GradeTooLowException();
	grade = _grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat " << name << " copy constructor called!" << std::endl;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat " << name << " copy assignment operator called!" << std::endl;
	return *this;
};

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat " << name << " destructor called!" << std::endl;
};

std::string Bureaucrat::getName() const{
	return name;
};

int Bureaucrat::getGrade() const{
	return grade;
};

void Bureaucrat::incrementGrade(){
	if (grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	grade--;
};

void Bureaucrat::decrementGrade(){
	if (grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	grade++;
};

void Bureaucrat::signForm(AForm& f){
 	try {
        f.beSigned(*this);
        std::cout << getName() << " successfully signed the form!" << std::endl;
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cout << getName() << " couldn’t sign the form because: " << e.what() << std::endl;
    }
};

void Bureaucrat::executeForm(AForm const& form){
	form.execute(*this);
};

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Error: Grade is too high!";
};

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Error: Grade is too low!";
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
};
