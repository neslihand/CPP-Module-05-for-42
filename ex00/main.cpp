/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:46:45 by ndogan            #+#    #+#             */
/*   Updated: 2025/04/22 11:48:19 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testConstructor() {
    std::cout << "\n----- Constructor Tests -----" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1.getName() << " created with grade " << b1.getGrade() << std::endl;
        
        Bureaucrat b2("Bob", 150);
        std::cout << b2.getName() << " created with grade " << b2.getGrade() << std::endl;

        Bureaucrat b3("Charlie", 75);
        std::cout << b3.getName() << " created with grade " << b3.getGrade() << std::endl;

        Bureaucrat b4("Error1", 0); // Hata: GradeTooHighException fırlatır.
    } 
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Error2", 151); // Hata: GradeTooLowException fırlatır.
    } 
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment() {
    std::cout << "\n----- Copy & Assignment Tests -----" << std::endl;
    Bureaucrat b1("Original", 50);
    Bureaucrat b2(b1); // Copy constructor çağrılır
    std::cout << "Copy constructor: " << b2.getName() << " - Grade: " << b2.getGrade() << std::endl;

    Bureaucrat b3("Another", 100);
    b3 = b1; // Copy assignment çağrılır
    std::cout << "Copy assignment: " << b3.getName() << " - Grade: " << b3.getGrade() << std::endl;
}

void testGradeManipulation() {
    std::cout << "\n----- Grade Manipulation Tests -----" << std::endl;
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1.getName() << " before increment: " << b1.getGrade() << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << " after increment: " << b1.getGrade() << std::endl;

        b1.incrementGrade(); // Hata: GradeTooHighException fırlatır.
    } 
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2.getName() << " before decrement: " << b2.getGrade() << std::endl;
        b2.decrementGrade();
        std::cout << b2.getName() << " after decrement: " << b2.getGrade() << std::endl;

        b2.decrementGrade(); // Hata: GradeTooLowException fırlatır.
    } 
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInsertOperator() {
    std::cout << "\n----- Insertion Operator Test -----" << std::endl;
    Bureaucrat b1("Alice", 50);
    std::cout << b1 << std::endl;

    Bureaucrat b2("Bob", 1);
    std::cout << b2 << std::endl;

    Bureaucrat b3;
    std::cout << b3 << std::endl;
}

int main() {
    testConstructor();
    testCopyAndAssignment();
    testGradeManipulation();
	testInsertOperator();
    return 0;
}

