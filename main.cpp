#include<iostream>

class Fraction {
private:
	int num;
	int denum;

public:
	Fraction(int n, int d);
	

	friend void reduce(Fraction f);
		

	friend Fraction operator + (Fraction f1, Fraction f2);
	friend Fraction operator - (Fraction f1, Fraction f2);
	friend Fraction operator / (Fraction f1, Fraction f2);
	friend Fraction operator * (Fraction f1, Fraction f2);
	friend bool operator == (Fraction f1, Fraction f2);
	friend bool operator != (Fraction f1, Fraction f2);
	friend bool operator < (Fraction f1, Fraction f2);
	friend bool operator <= (Fraction f1, Fraction f2);
	friend bool operator > (Fraction f1, Fraction f2);
	friend bool operator >= (Fraction f1, Fraction f2);


};
Fraction::Fraction(int n = 0, int d = 0) {
	num = n;
	denum = d;
}

void reduce(Fraction f) {
	//Найти все общие делители у числителя и знаменателя и поделить на них
	for (int i = 2; i < std::max(f.num, f.denum); ++i) {
		while (f.num % i == 0 && f.denum % i == 0) {
			f.num /= i;
			f.denum /= i;
		}
	}
}

Fraction operator + (Fraction f1, Fraction f2) {
	Fraction result;
	result.num = f1.num * f2.denum + f2.num * f1.denum;
	result.denum = f1.denum * f2.denum;
	reduce(result);
	return result;
}
Fraction operator - (Fraction f1, Fraction f2) {
	Fraction result;
	result.num = f1.num * f2.denum - f2.num * f1.denum;
	result.denum = f1.denum * f2.denum;
	reduce(result);
	return result;
}
Fraction operator * (Fraction f1, Fraction f2) {
	Fraction result;
	result.num = f1.num * f2.num;
	result.denum = f1.denum * f2.denum;
	reduce(result);
	return result;
}
Fraction operator / (Fraction f1, Fraction f2) {
	Fraction result;
	result.num = f1.num * f2.denum;
	result.denum = f1.denum * f2.num;
	reduce(result);
	return result;
}


bool operator == (Fraction f1, Fraction f2) {
	reduce(f1);
	reduce(f2);
	return f1.num == f2.num && f1.denum == f2.denum;
}
bool operator != (Fraction f1, Fraction f2) {
	return !(f1 == f2);
}
bool operator < (Fraction f1, Fraction f2) {
	reduce(f1);
	reduce(f2);
	return f1.num*f2.denum < f2.num* f1.denum;
}
bool operator <= (Fraction f1, Fraction f2) {
	return f1 == f2 || f1 < f2;
}
bool operator > (Fraction f1, Fraction f2) {
	return !(f1 <= f2);
}
bool operator >= (Fraction f1, Fraction f2) {
	return !(f1 < f2);
}

int main() {

	return 0;
}
