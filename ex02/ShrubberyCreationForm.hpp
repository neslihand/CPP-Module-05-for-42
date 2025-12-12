/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:12:29 by ndogan            #+#    #+#             */
/*   Updated: 2025/02/24 19:06:23 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		const std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &_target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm other);
		~ShrubberyCreationForm();

		void executeAction() const;
};