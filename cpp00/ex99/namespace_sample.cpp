/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespace_sample.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:44:09 by nwattana          #+#    #+#             */
/*   Updated: 2023/06/04 17:46:27 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// What is namespace?

int GLOBAL_A = 3;

namespace Name_Space_A{
	int GLOBAL_A = 6;
	int sample_function(void){return 4;}
}


namespace Name_Space_B{
	int GLOBAL_A = 6;
	int sample_function(void){return 4;}
}