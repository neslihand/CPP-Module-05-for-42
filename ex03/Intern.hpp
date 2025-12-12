/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:34:53 by ndogan            #+#    #+#             */
/*   Updated: 2025/04/25 20:31:28 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);

    private:
        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPresidential(const std::string& target);
};