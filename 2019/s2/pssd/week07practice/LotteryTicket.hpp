#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CountExpressions
{
private:
    int num1;
    int num2;
    int comparison;

    int doOperation(int x, int y, int operation)
    {
        if(operation == '*')
        {
            return x * y;
        } else if (operation == '+')
        {
            return x + y;
        } else if (operation == '-')
        {
            return x - y;
        }
    }

    int evaluateExpression(vector<int> numbers, vector<char> operators)
    {
        int num = numbers[0];
        num = doOperation(num,numbers[1],operators[0]);
        num = doOperation(num,numbers[2],operators[1]);
        num = doOperation(num,numbers[3],operators[2]);


        if (num == comparison)
        {
            return 1;
        } else {
            return 0;
        }
    }

    int generateNumbers(vector<int> numbers, vector<char> operators)
    {
        if(numbers.size() == 4)
        {
            return evaluateExpression(numbers, operators);
        } else if (numbers.size() == 0)
        {
            numbers.push_back(num1);
            int tmp1 = generateNumbers(numbers, operators);
            numbers[0] = num2;
            int tmp2 = generateNumbers(numbers, operators);

            return tmp1 + tmp2;
        } else if (numbers.size() == 1)
        {
            numbers.push_back(num1);
            int tmp1 = generateNumbers(numbers, operators);
            numbers[1] = num2;
            int tmp2 = generateNumbers(numbers, operators);

            return tmp1 + tmp2;
        } else if (numbers.size() == 2)
        {
            if ((numbers[0] == num1 && numbers[1] == num2) || (numbers[1] == num1 && numbers[0] == num2))
            {
                numbers.push_back(num1);
                int tmp1 = generateNumbers(numbers, operators);
                numbers[2] = num2;
                int tmp2 = generateNumbers(numbers, operators);

                return tmp1 + tmp2;
            } else if (numbers[0] == num1 && numbers[1] == num1)
            {
                numbers.push_back(num2);
                return generateNumbers(numbers, operators);
            }  else if (numbers[0] == num2 && numbers[1] == num2)
            {
                numbers.push_back(num1);
                return generateNumbers(numbers, operators);
            }
        } else if (numbers.size() == 3)
        {
            if((numbers[0] == num1 && numbers[1] == num2) || (numbers[0] == num2 && numbers[1] == num1))
            {
                if(numbers[2] == num1)
                {
                    numbers.push_back(num2);
                    return generateNumbers(numbers, operators);
                } else {
                    numbers.push_back(num1);
                    return generateNumbers(numbers, operators);
                }
            } else if (numbers[2] == num1)
            {
                numbers.push_back(num1);
                return generateNumbers(numbers, operators);
            } else if (numbers[2] == num2)
            {
                numbers.push_back(num2);
                return generateNumbers(numbers, operators);
            }
        }
    }

    int generateOperators(vector<char> current)
    {
        if(current.size() == 3)
        {
            vector<int> numbers;
            return generateNumbers(numbers,current);
        } else if(current.size() == 0)
        {
            current.push_back('*');
            int tmp1 = generateOperators(current);
            current[0] = '+';
            int tmp2 = generateOperators(current);
            current[0] = '-';
            int tmp3 = generateOperators(current);

            return tmp1 + tmp2 + tmp3;
        } else if(current.size() == 1)
        {
            current.push_back('*');
            int tmp1 = generateOperators(current);
            current[1] = '+';
            int tmp2 = generateOperators(current);
            current[1] = '-';
            int tmp3 = generateOperators(current);

            return tmp1 + tmp2 + tmp3;
        } else if(current.size() == 2)
        {
            current.push_back('*');
            int tmp1 = generateOperators(current);
            current[2] = '+';
            int tmp2 = generateOperators(current);
            current[2] = '-';
            int tmp3 = generateOperators(current);

            return tmp1 + tmp2 + tmp3;
        }
    }

public:
    int calcExpressions(int x, int y, int val)
    {
        num1 = x;
        num2 = y;
        comparison = val;

        vector<char> nothing;

        return generateOperators(nothing);
    }
};
