/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:13:51 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/28 16:54:46 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*decToHexa(int n) 
{
	// char array to store hexadecimal number 
	char hexaDeciNum[20]; 
	
	// counter for hexadecimal number array 
	int i = 0; 
	while (n != 0) 
	{    
		// temporary variable to store remainder 
		int temp  = 0; 
		
		// storing remainder in temp variable. 
		temp = n % 16; 
		
		// check if temp < 10 
		if (temp < 10) 
		{ 
			hexaDeciNum[i] = (char)(temp + 48); 
			i++; 
		} 
		else
		{ 
			hexaDeciNum[i] = (char)(temp + 55); 
			i++; 
		} 
		
		n = n/16; 
	} 
	return (hexaDeciNum);
}
