/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassVolumed.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:39:17 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:12:02 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassVolumed.hpp"

Volumed::Volumed() : Popupd(POPUP_NAME)
{}

Volumed::~Volumed()
{}

int	Volumed::set_volume(const std::string& amount)
{
	if (parse_amount(amount))
		throw std::runtime_error("Badly formatted amount.");
	return this->_level;
}

int	Volumed::switch_mute()
{

	return this->_level;
}
