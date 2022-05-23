#include <iostream>


using namespace std;


struct Expression {

	virtual double evaluate() const = 0;
	virtual ~Expression() {};
};

struct Number : public Expression { // для представления чисел
	Number(double value) : value(value) {}
	double evaluate() const { return value; }

	~Number() {}

private:
	double value;
};

struct BinaryOperation : public Expression { // описывает бинарную операцию
	BinaryOperation(Expression const* left, char op, Expression const* right) :
		right(right), left(left), op(op) {}

	double evaluate() const {

		switch (op) {
		case '+':
			return (left->evaluate() + right->evaluate());
		case '-':
			return (left->evaluate() - right->evaluate());
		case '*':
			return (left->evaluate() * right->evaluate());
		case '/':
			return (left->evaluate() / right->evaluate());
		}
	}
	~BinaryOperation() {
		delete left;
		delete right;
	}

private:
	Expression const* right;
	Expression const* left;
	char op;
};

//применяем 2 указателя и возвращаем true, если указывают на объект одного и того же класса

bool check_equals(Expression const* left, Expression const* right) // 6 задание
{
return (*((size_t*)left) == *((size_t*)right));
}

int main() {
	Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5)); // сначала создаём объекты для подвыражения 4.5 * 5

	Expression* expr = new BinaryOperation(new Number(3), '+', sube); // потом используем его в выражении для +

	cout << check_equals(new BinaryOperation(new Number(4.5), '*', new Number(5)), new Number(1));

	putchar('\n');

	cout << expr->evaluate(); // вычисляем и выводим результат: 25.5

	delete expr; // освобождение всех объектов
}