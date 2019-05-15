#include <iostream>
#include "Header.h"

// Получаем начальную высоту от пользователя и возвращаем её
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

// Возвращаем расстояние от земли после "..." секунд падения
double calculateHeight(double initialHeight, int seconds)
{
	// Используем формулу: [ s = (a * t^2) / 2 ]
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	double currentHeight = initialHeight - distanceFallen;

	return currentHeight;
}

// Выводим высоту, на которой находится мячик после каждой секунды падения
void printHeight(double height, int seconds)
{
	if (height > 0.0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
			" meters\n";
	}
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

double calculateAndPrintHeight(double initialHeight, int seconds)
{
	double height = calculateHeight(initialHeight, seconds);
	printHeight(height, seconds);
	return height;
}

int main()
{
	const double initialHeight = getInitialHeight();

	int seconds;
	for (double ballHeight = initialHeight, seconds = 0;; seconds++)
	{
		double height = calculateAndPrintHeight(initialHeight, seconds);
		if (height <= 0)
		{
			return 0;
		}
	}
	

	return 0;
}
