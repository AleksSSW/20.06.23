#include <iostream>
#include <string>



class Drob {
private:
	int _num;
	int _den;

	void Reduce() {
		int nod = 1;
		int d = 1;
		while (d <= abs (_num) && d <= abs (_den)) {
			if (_num % d == 0 && _den % d == 0)
				nod = d;
			d++;
		}
		_num = _num / nod;
		_den = _den / nod;

	}

public:
	Drob(int n, int d) : _num(n), _den(d != 0 ? d : 1){
		Reduce();
	}
	 
	int  GetNum() const {
		return _num;
	}
	int  GetDen() const {
		return _den;
	}

	Drob operator +(const Drob& other) const {
		return Drob(
			_num * other.GetDen() + other.GetNum() * _den,
			_den * other.GetDen()

		);
	}
	Drob operator *(const Drob& other) const {
		return Drob(
			_num * other.GetNum(),
			_den * other.GetDen()
		);
	}

	
};

Drob operator -(const Drob& left, const Drob& right)  {
	return Drob(
		left.GetNum() * right.GetDen() - right.GetNum() * left.GetDen(),
		left.GetDen() * right.GetDen()
	);
}

Drob operator /(const Drob& left, const Drob& right) {
	if (right.GetNum() != 0) {
		return Drob(
			left.GetNum() * right.GetDen(),
			left.GetDen() * right.GetNum()
		);
	}
	return left;
}

std::ostream& operator << (std::ostream& out, const Drob& d) {
	out << d.GetNum() << '/' << d.GetDen();
	return out;
}

class Complex {
private:
	double _real;
	double _imag;
	
public:
	Complex(double real, double imag):_real(real), _imag(imag) {}

	double GetImage() {
		return _imag;
	}

	double GetReal() {
		return _real;
	}
	
	Complex operator +( Complex &other) {
		return Complex ((this->_real + other.GetReal()) + (this->_imag + other.GetImage()));
				
	}
	Complex operator -(Complex& other) {
		return Complex((this->_real - other.GetReal()) - (this->_imag - other.GetImage()));
	 }

	Complex operator *(Complex& other) {
		return Complex((this->_real * other.GetReal()) * (this->_imag * other.GetImage()));
	}

	Complex operator /(Complex& other) {
		return Complex((this->_real / other.GetReal()) / (this->_imag / other.GetImage()));
	}
	
};





class Flat {
private:
	float _square;
	float _price;
public:
	Flat(float s, float p) : _square(s), _price(p) {}

	float GetSquare()const {
		return this->_square;
	}

	void SetSquare(float s) {
		this->_square = s;
	}

	float GetPrice()const {
		return _price;
	}



	bool operator ==(const Flat& other) const {
		return this->GetSquare() == other.GetSquare();
	}

	Flat& operator =(const Flat& other) {
		if (this != &other) {
			this->SetSquare(other.GetSquare());
			this->_price = other.GetPrice();
		}
		return *this;
	}

	bool operator > (const Flat& other)  const {
		return this->GetPrice() > other.GetPrice();
	}
};

class Overcoat {
private:
	float _coatPrice;
	std::string _coatType;
public:
	Overcoat(float price, std::string type): _coatPrice(price), _coatType(type){}
	
	float GetPrice()const {
		return _coatPrice;
	}

	std::string GetType()const {
		return _coatType;
	}

	void SetType(std::string s) {
		this->_coatType = s;
	}

	bool operator ==(const Overcoat& other) {
		return this->GetPrice() == other.GetPrice();
	}

	Overcoat& operator=(const Overcoat& other) {
		if (this != &other) {
			this->SetType(other.GetType());
			this->_coatType = other.GetType();
		}
		return *this;
	}
	bool operator >(const Overcoat& other) {
		return this -> GetPrice() > other.GetPrice();
	}
};

int main() {

	Drob a(5, 8);
	Drob b(5, 6);
	Drob c = a + b;
	std::cout << c<<std::endl;
	 c = a - b;
	std::cout << c << std::endl;
	c = a * b;
	std::cout << c << std::endl;
	c = a / b;
	std::cout << c << std::endl;
	c = (a - b) *c + a;
	std::cout << c << std::endl;

	Flat k(89.5f, 896);
	Flat m(89.5f, 215);
	if (k == m)
		std::cout << "Equal square\n";
	if (k > m)
		std::cout << "Bigger price\n";
	k = m;
	if (k > m)
		std::cout << "Bigger price!!!!!!\n";

	
	Overcoat s(125.8f, "short");
	Overcoat l(218.9f, "long");

	if (s == l)
		std::cout << "Equal price\n";
	if (s > l)
		std::cout << "Bigger price\n";
	s = l;
	if (s > l)
		std::cout << "Bigger type!!!!!!\n";

	return 0;
}