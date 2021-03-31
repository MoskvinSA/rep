#pragma once
#include <string>
#include <iostream>

class Monom {
	double coef;
	int ex;
public:
	Monom(double _coef = 1, int _ex = 0) :coef(_coef), ex(_ex) {}

	Monom(const Monom& m) : coef(m.coef), ex(m.ex) { }

	double& get_coef() {
		return coef;
	}

	int get_ex() {
		return ex;
	}

	void analysis(int _state, std::string _s) {
		int p = 20;
		if (_state == 0 && _s.length() > 0) coef = atof(_s.c_str());
		if (_state == 1 && _s.length() > 0) ex += atof(_s.c_str()) * p * p;
		if (_state == 2 && _s.length() > 0) ex += atof(_s.c_str()) * p;
		if (_state == 3 && _s.length() > 0) ex += atof(_s.c_str());
	}

	double res_monom(double _x, double _y, double _z, int _p) {
		int x = ex / (_p * _p);
		int y = (ex - x * _p * _p) / _p;
		int z = (ex - x * _p * _p) % _p;
		return coef * exp(x * log(_x)) * exp(y * log(_y)) * exp(z * log(_z));
	}

	bool operator==(const Monom& m) {
		return coef == m.coef && ex == m.ex;
	}

	bool operator !=(const Monom& m) {
		return coef != m.coef && ex != m.ex;
	}

	bool operator>(const Monom& m) {
		return this->ex > m.ex || (this->ex == m.ex && coef > m.coef);
	}

	bool operator<(const Monom& m) {
		return this->ex < m.ex || (this->ex == m.ex && coef < m.coef);
	}

	Monom& operator=(const Monom& m) {
		coef = m.coef;
		ex = m.ex;
		return *this;
	}

	Monom operator-(const Monom& m) {
		if (m.ex != ex) throw - 1;
		Monom res;
		res.ex = ex;
		res.coef = coef - m.coef;
		return res;
	}

	Monom operator+(const Monom& m) {
		if (m.ex != ex) throw - 1;
		Monom res;
		res.ex = ex;
		res.coef = coef + m.coef;
		return res;
	}

	Monom operator*(const Monom& m) {
		Monom res;
		res.coef = coef * m.coef;
		res.ex = ex + m.ex;
		return res;
	}

	friend std::ostream& operator<<(std::ostream& o, Monom& m) {
		int p = 20;
		int x = m.ex / (p * p);
		int y = (m.ex - x * p * p) / p;
		int z = (m.ex - x * p * p) % p;

		o << "+( " << m.coef;
		if (x > 0) o << "x^" << x;
		if (y > 0) o << "y^" << y;
		if (z > 0) o << "z^" << z;
		o << " )";

		return o;
	}
};