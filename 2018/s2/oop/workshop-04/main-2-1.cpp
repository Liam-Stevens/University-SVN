#include <iostream>
#include <string>
extern float add_op(float, float);
extern float subtract_op(float, float);
extern float arithmetic_ops(float, float, std::string);

int main()
{
	float fl1 = 0;
	float fl2 = 0;
	std::string oper = " ";
	std::cout << "Please enter the first number" << std::endl;
	std::cin >> fl1;
	while (oper != "+" && oper != "-")
	{
		std::cout << "Please enter an operation ( + or - )" << std::endl;
		std::cin >> oper;
		if (oper != "+" && oper != "-")
		{
			std::cout << "Invalide Operation Type" << std::endl;
		}
	}
	std::cout << "Please enter the second number" << std::endl;
	std::cin >> fl2;

	std::cout << std::endl;
	std::cout << fl1 << " " << oper << " " << fl2 << " = " << arithmetic_ops(fl1,fl2,oper) << std::endl;
	return 0;
}