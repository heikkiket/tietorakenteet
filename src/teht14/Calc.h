#ifndef CALC_H
#define CALC_H

#include <string>
#include <queue>
#include <exception>

using namespace std;

class Calc
{
private:
  double result = 0;
  deque<string> expression;

  bool isOperator(string str);
  bool validate();
  double processPart(double a, string op, double b);
  double sum(double a, double b);
  double minus(double a, double b);
  double mul(double a, double b);
  double div(double a, double b);
  bool stackIsEmpty();

public:
  Calc();
  virtual ~Calc();
  deque<string> tokenize(string str);
  void add(string str);
  double calculate();

  class InvalidExpression : exception {
  } InvalidExpression;
};


#endif /* CALC_H */
