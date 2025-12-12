/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:14:30 by ndogan            #+#    #+#             */
/*   Updated: 2025/02/24 18:08:48 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		const std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &_target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator = (const RobotomyRequestForm other);
		~RobotomyRequestForm();

		void executeAction() const;
};
