#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "monom.h"
#include "TList.h"

using namespace std;

class Polynom {
	List<Monom> l;
public:
	Polynom() {}

	Polynom(string str) {
		List<string> monom_str;

		string s = "";
		for (int i = 0; i < str.length(); i++) {
			string s = "";
			while ((i < str.length()) && (str[i] != '+') && (str[i] != '-')) {
				if (i > 0 && str[i - 1] == '-')
					s += '-';
				s += str[i];
				i++;
			}
			monom_str.push_back(s);
		}
		if (s.length() > 0) {
			monom_str.push_back(s);
			cout << s;
		}

		Link<string>* pm = monom_str.front();
		while (pm != nullptr) {
			Monom m;
			string m_str = pm->value;
			int state = 0;
			s = "";
			for (int i = 0; i <= m_str.length(); i++) {
				if (m_str[i] == 'x') {
					m.analysis(state, s);
					state = 1;
					s = "";
				}
				else if (m_str[i] == 'y') {
					m.analysis(state, s);
					state = 2;
					s = "";
				}
				else if (m_str[i] == 'z') {
					m.analysis(state, s);
					state = 3;
					s = "";
				}
				else {
					s += m_str[i];
				}
			}
			if (m_str != "") {
				m.analysis(state, s);
				l.push_back(m);
			}
			pm = pm->next;
		}
	}

	Polynom(const Polynom& p) {
		l = p.l;
	}

	void add_monom(Monom m) {
		l.push_back(m);
	}

	Polynom& operator=(const Polynom& p) {
		l = p.l;
		return *this;
	}

	Polynom operator+(Polynom& p) {
		Polynom res;
		Link<Monom>* p1, * p2;
		p1 = l.front();
		p2 = p.l.front();
		while (p1 != nullptr && p2 != nullptr) {
			if (p1->value.get_ex() == p2->value.get_ex()) {
				if ((p1->value.get_coef() + p2->value.get_coef()) != 0)
					res.add_monom(p1->value + p2->value);
				p1 = p1->next;
				p2 = p2->next;

			}
			else if (p1->value > p2->value) {
				res.add_monom(p1->value);
				p1 = p1->next;
			}
			else if (p1->value < p2->value) {
				res.add_monom(p2->value);
				p2 = p2->next;

			}
		}

		while (p2 != nullptr) {
			res.add_monom(p2->value);
			p2 = p2->next;
		}
		while (p1 != nullptr) {
			res.add_monom(p1->value);
			p1 = p1->next;
		}
		return res;
	}

	Polynom operator-(Polynom& p) {
		Polynom res;
		Link<Monom>* p1, * p2;
		p1 = l.front();
		p2 = p.l.front();
		while (p1 != nullptr && p2 != nullptr) {
			if (p1->value.get_ex() == p2->value.get_ex()) {
				if ((p1->value.get_coef() - p2->value.get_coef()) != 0)
					res.add_monom(p1->value - p2->value);
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1->value > p2->value) {
				res.add_monom(p1->value);
				p1 = p1->next;
			}
			else if (p1->value < p2->value) {
				p2->value.get_coef() = -p2->value.get_coef(); // при вычитании полинома все мономы вычитаемого меняют знак
				res.add_monom(p2->value);
				p2 = p2->next;
			}
			
		}

		while (p2 != nullptr) {
			p2->value.get_coef() = -p2->value.get_coef();
			res.add_monom(p2->value);
			p2 = p2->next;
		}
		while (p1 != nullptr) {
			res.add_monom(p1->value);
			p1 = p1->next;
		}

		return res;
	}

	Polynom operator*(Polynom& p) {
		Polynom res;
		Link<Monom>* p1, * p2;
		p1 = l.front();
		while (p1 != nullptr) {
			p2 = p.l.front();
			while (p2 != nullptr) {
				res.add_monom(p1->value * p2->value);
				p2 = p2->next;
			}
			p1 = p1->next;
		}
		return res;
	}

	double calculate_result(double x, double y, double z) {
		int p = 20, i, j, k;
		double res = 0;
		Link<Monom>* pm = l.front();
		while (pm != nullptr) {
			res += pm->value.res_monom(x, y, z, p);
			pm = pm->next;
		}
		return res;
	}

	List<Monom> get_list() {
		return l;
	}

	bool operator==(const Polynom& p) {
		return l == p.l;
	}

	friend ostream& operator<<(ostream& o, Polynom& p) {
		o << p.l;
		return o;
	}
};