/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:29:30 by ndogan            #+#    #+#             */
/*   Updated: 2025/05/06 14:05:50 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class Form{
	private:
		const std::string name;
		const int requiredToSign;
		const int requiredToExecute;
		bool isSigned;
	public:
		Form();
		Form(const std::string &_name, int _requiredToSign, int _requiredToExecute);
		Form(const Form& other);
		Form& operator = (const Form& other);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getRequiredToSign() const;
		int getRequiredToExecute() const;

		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
		    public:
		        virtual const char* what() const throw();
	    };
	    class GradeTooLowException : public std::exception {
		    public:
		        virtual const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream &out, const Form &f);