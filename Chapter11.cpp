#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Time.h"
#include "Vector.h"
#include "Complex.h"

const std::string ERR = "Please enter a valid option\n";

template<typename T>
T randrange(T min, T max);

void ignore();
void showMenu();

void timeCaller();

void stepCaller();

void complexCaller();

int main()
{
    showMenu();
    std::string input;
    while (std::getline(std::cin, input))
    {
        char cinput = input[0];
        if (!(isdigit(cinput)))
        {
            if (toupper(cinput) == 'Q')
                return 0;
            //ignore();
            std::cout << ERR;
            showMenu();
            continue;
        }
        int choice = atoi(&cinput);
        switch (choice)
        {
        case 0: timeCaller(); break;
		case 1: complexCaller(); break;
		case 2: stepCaller(); break;
        default: std::cout << ERR; break;
        }
        showMenu();
    }
}


template<typename T>
T randrange(T min, T max)
{
	T result = rand() % (max - min) + min;
	return result;
}


void ignore()
{
    std::cin.clear();
    std::cin.ignore(100, '\n');
}


void showMenu()
{
    std::cout << "0) Time\n1) Complex\n2) Random Walk\nq) Quit\n>";
}


void timeCaller()
{
    Time t1(3, 26);
    Time t2;
    t2.reset(5, 30);
    Time t3 = t1 + t2;
    Time t4 = t2 - t1;
    std::cout << "t1: " << t1 << "\nt2: " << t2;
    std::cout << "\nt1 + t2: " << t3 << "\n";
    std::cout << "t2 - t1: " << t4 << "\n";
}


void stepCaller()
{
	srand(time(NULL));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps{};
	double target;
	double dstep;
	std::cout << "Enter target distance: ";
	std::cin >> target;
	std::cout << "Enter step length: ";
	std::cin >> dstep;
	while (result.getMag() < target)
	{
		direction = rand() % 360;
		step.reset(dstep, direction, Vector::POL);
		result = result + step;
		steps++;
	}
	std::cout << "After " << steps << " steps, the subject has the following location:\n";
	std::cout << result << "\n";
	result.setPolar();
	std::cout << " or\n" << result << "\n";
	std::cout << "Average outward distance per step: " << result.getMag() / steps << "\n";
	steps = 0;
	result.reset(0, 0);
	ignore();
}


void complexCaller()
{
	Complex a(3.0, 4.0);
	Complex c;
	std::cout << "Enter a complex number (q to quit):\n";
	while (std::cin >> c)
	{
		std::cout << "c is " << c << "\ncomplex conjugate is "
			<< -c << "\na is " << a << "\na + c is " << a + c
			<< "\na - c is " << a - c << "\na * c is " << a * c
			<< "\n2 * c is " << 2 * c << "\n";
		std::cout << "enter a complex number (q to quit):\n";
	}
	ignore();
}
