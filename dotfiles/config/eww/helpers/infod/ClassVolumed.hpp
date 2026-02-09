/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassVolumed.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:14:56 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:15:31 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOLUMED_HPP
# define VOLUMED_HPP

#include "ClassPopup.hpp"

#define POPUP_NAME "volpopup"

class Volumed : Popupd
{
	private:
		bool	_mute;

	public:
		Volumed();
		~Volumed();

	int	set_volume(const std::string& amount);
	int	switch_mute();
};

#endif // !VOLUMED_HPP
