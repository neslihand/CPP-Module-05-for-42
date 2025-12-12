/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:47:27 by ndogan            #+#    #+#             */
/*   Updated: 2025/02/17 19:07:08 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &_name, int _grade);
		Bureaucrat(const Bureaucrat& other); 
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
		    public:
		        virtual const char* what() const throw();
	    };
	    class GradeTooLowException : public std::exception {
		    public:
		        virtual const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);