/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:29:30 by ndogan            #+#    #+#             */
/*   Updated: 2025/02/24 15:41:43 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class AForm{
	protected:
		const std::string name;
		bool isSigned;
		int requiredToSign;
		int requiredToExecute;
    	virtual void executeAction() const = 0;
	public:
		AForm();
		AForm(const std::string &_name, int _requiredToSign, int _requiredToExecute);
		AForm(const AForm& other);
		AForm& operator = (const AForm& other);
		~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getRequiredToSign() const;
		int getRequiredToExecute() const;

		void beSigned(const Bureaucrat& b);

		void execute(Bureaucrat const &executor) const;

		class FormIsNotSignedException : public std::exception {
		    public:
		        virtual const char* what() const throw();
	    };
		class GradeTooHighException : public std::exception {
		    public:
		        virtual const char* what() const throw();
	    };
	    class GradeTooLowException : public std::exception {
		    public:
		        virtual const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream &out, const AForm &f);