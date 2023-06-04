#include <iostream>
#include <string>
#include <stdio.h>

int main(int av, char **ac)
{
	int j;
	
	if (av == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i<av; i++)
	{
		j = 0;
		while (ac[i][j] != '\0')
		{
			std::cout << char(toupper(ac[i][j]));
			j++;
		}
	}
	std::cout << std::endl;
}