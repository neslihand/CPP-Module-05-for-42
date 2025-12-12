/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:12:46 by ndogan            #+#    #+#             */
/*   Updated: 2025/02/24 19:29:36 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) , target("Default"){
	std::cout << "ShrubberyCreationForm Default constructor called!" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target): AForm("ShrubberyCreationForm", 145, 137) , target(_target){
	std::cout << name << " ShrubberyCreationForm constructor called!" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target){
	*this = other;
	std::cout << name << " ShrubberyCreationForm copy constructor called!" << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm other){
	if (this != &other){
		this->isSigned = other.isSigned;
		this->requiredToExecute = other.requiredToExecute;
		this->requiredToSign = other.requiredToSign;
	}
	std::cout << name << " ShrubberyCreationForm copy assignment operator called!" << std::endl;
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << name << " ShrubberyCreationForm destructor called!" << std::endl;
};

void ShrubberyCreationForm::executeAction() const{
	std::ofstream My_file((target + "_shrubbery").c_str());
    if (My_file.is_open()) {
        My_file << "      /\\      \n";
        My_file << "     /\\*\\     \n";
        My_file << "    /\\O\\*\\    \n";
        My_file << "   /*/\\/\\/\\   \n";
        My_file << "  /\\O\\/\\*\\/\\  \n";
        My_file << " /\\*\\/\\*\\/\\/\\ \n";
        My_file << "/\\O\\/\\/*/\\/O/\\\n";
        My_file << "      ||      \n";
        My_file << "      ||      \n";
        My_file << "      ||      \n";
        My_file.close();
        std::cout << "Shrubbery created at " << (target + "_shrubbery") << std::endl;
    } else {
        std::cerr << "Error: Could not create file!" << std::endl;
    }
};
