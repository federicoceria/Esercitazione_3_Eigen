#include <iostream>
#include <iomanip>
#include "Eigen/Eigen"
#include "function.cpp"

using namespace std;
using namespace Eigen;

int main()
{
	// creo un array di matrici
	Matrix2d matrices[3];
	matrices[0] << 5.547001962252291e-01,-3.770900990025203e-02,
				   8.320502943378437e-01,-9.992887623566787e-01;
	matrices[1] << 5.547001962252291e-01,-5.540607316466765e-01,
				   8.320502943378437e-01,-8.324762492991313e-01;
	matrices[2] << 5.547001962252291e-01,-5.547001955851905e-01,
				   8.320502943378437e-01,-8.320502947645361e-01;
	
	// creo un array di vettori
	Vector2d vectors[3];
	vectors[0] << -5.169911863249772e-01, 1.672384680188350e-01;
	vectors[1] << -6.394645785530173e-04, 4.259549612877223e-04;
	vectors[2] << -6.400391328043042e-10, 4.266924591433963e-10;
	
	Vector2d c;
	c << -1.0e+0, -1.0e+00;  //questa è la soluzione esatta
	
	Vector2d sol;
	
	double err;
	
	int i = 0;
	while(i < 3){
		Palu_matrix(matrices[i], vectors[i], c, sol, err);
		cout << scientific << setprecision(16);
		cout << "La soluzione del sistema lineare " << i+1 << " con decomposizione PALU è: [" << sol.transpose() << "]" << endl;
		cout << "L'errore relativo associato alla matrice " << i+1 << " con decomposizione PALU è: " << err << endl;
	
		QR_matrix(matrices[i], vectors[i], c, sol, err);
		cout << "La soluzione del sistema lineare " << i+1 << " con decomposizione QR è: [" << sol.transpose() << "]" << endl;
		cout << "L'errore relativo associato alla matrice " << i+1 << " con decomposizione QR è: " << err << endl;
	
		i++;
	}

    return 0;
}
