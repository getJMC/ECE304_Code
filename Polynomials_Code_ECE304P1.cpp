#include <iostream>
#include <string>
#include <vector>
using namespace std;

class poly {
public:
	poly (string, unsigned int, double []);
	// you need to add at least two different constructors
	double FirstDeriv(unsigned int, double);
	double SecondDeriv(unsigned int, double);

	void printPoly();
	double val(double);
	// you need to append your functions here

private:
	string name;
	unsigned int order;
	vector<double> coeff;
};

poly::poly (string p, unsigned int n , double c[])
{
	name  = p;
	order = n;
	for (unsigned int i = 0; i <= n; i++)
		coeff.push_back(c[i]);
}

double poly::val(double x)
{
	double ans = 0;
	for (unsigned int i = 0; i <= order; i++)
		ans = ans * x + coeff[i];
	return ans;
}

double poly::FirstDeriv(unsigned int x, double h)
{
	double result = (val(x+h) - val(x-h))/(2*h);
	return result;
}

double poly::SecondDeriv(unsigned int x, double h)
{
	double result = (val(x+h) - 2*val(x) + val(x-h))/(h*h);
	return result;
}

void poly::printPoly( )
{
	cout<<"polynomial name:"<<name<<endl;
	cout<<"Order"<<order<<endl;
	cout<<"Coefficients are:";
	for(unsigned int i=0; i<=order; i++){
		cout<<coeff[i]<<" ";
	}
	cout<<endl;
}


int main (void)
{
	double c[3] = {1,3,2};
	poly a("A", 2, c);
	a.printPoly();
	cout<<a.val(5) << endl;
	cout << a.val(-2.0) << endl;

	cout << endl << "First Derivative: " << a.FirstDeriv(2,0.5) << endl;
	cout << "Second Derivative: " << a.SecondDeriv(2,0.5) << endl;
	system ("pause");
	return 0;
}