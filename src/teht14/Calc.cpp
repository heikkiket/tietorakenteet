#include "Calc.h"

#include <sstream>

using namespace std;

Calc::Calc() {}
Calc::~Calc() {}

deque<string> Calc::tokenize(string str)
{
  stringstream strim(str);

  deque<string> arr;

  string token;
  while (std::getline(strim, token, ' ')) {
    arr.push_back(token);
  }

  return arr;
}

void Calc::add(string str)
{
  expression = tokenize(str);
  validate();
}

bool Calc::validate()
{
  int operators = 0;
  int operands = 0;
  int local_operands;
  for(auto tok : expression) {
    if (isOperator(tok)) {
      if(operands < 2)
        throw InvalidExpression;

      operators++;
    }
    else {
      operands++;
    }
  }

  if ((operands - operators) != 1) {
    throw InvalidExpression;
    return false;
  }

  return true;
}

double Calc::calculate()
{
  double a;
  double b;
  string op;
  deque<double> numbers {};

  if(expression.size() == 1) {
    result = stod(expression.front());
    return result;
  }

  while(!stackIsEmpty()){

    while(!isOperator(expression.front())) {
      numbers.push_front(
                         stod(expression.front())
                         );
      expression.pop_front();
    }

    b = numbers.front();
    numbers.pop_front();
    a = numbers.front();
    numbers.pop_front();

    op = expression.front();
    expression.pop_front();

    numbers.push_front(processPart(a, op, b));
  }

  result = numbers.front();
  return result;
}

bool Calc::isOperator(string str)
{
  switch (str.at(0)) {
  case '+':
  case '-':
  case '*':
  case '/':
    return true;
  default:
    return false;
  }

}

double Calc::processPart(double a, string op, double b) {
  switch (op.at(0)) {
  case '+':
    return sum(a, b);
  case '-':
    return minus(a, b);
  case '*':
    return mul(a, b);
  case '/':
    return div(a, b);
  default:
    throw exception{};
    return -1;
  }
}

double Calc::sum(double a, double b)
{
  return a + b;
}

double Calc::minus(double a, double b)
{ return a - b; }

double Calc::mul(double a, double b)
{ return a * b; }

double Calc::div(double a, double b)
{ return a / b; }

bool Calc::stackIsEmpty()
{
  return expression.size() == 0;
}
