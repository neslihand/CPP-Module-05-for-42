/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:17:29 by ndogan            #+#    #+#             */
/*   Updated: 2025/05/06 13:52:18 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form;
    Bureaucrat br("brok", 1);

    std::cout << "\n--- TEST 1: Shrubbery Creation ---\n";
    form = someRandomIntern.makeForm("shrubbery creation", "Test");
    if (form)
        std::cout << *form << std::endl;
    br.signForm(*form);
    br.executeForm(*form);
    delete form;

    std::cout << "\n--- TEST 2: Robotomy Request ---\n";
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
        std::cout << *form << std::endl;
    br.signForm(*form);
    br.executeForm(*form);
    delete form;

    std::cout << "\n--- TEST 3: Presidential Pardon ---\n";
    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form)
        std::cout << *form << std::endl;

    br.signForm(*form);
    br.executeForm(*form);
    delete form;

    std::cout << "\n--- TEST 4: Invalid Form Name ---\n";
    form = someRandomIntern.makeForm("wrong form", "Nobody");
    if (!form)
        std::cout << "Form not created.\n";

    return 0;
}
