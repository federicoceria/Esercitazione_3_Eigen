#pragma once
#include "Eigen/Eigen"

using namespace Eigen;

// funzione per risolvere il sistema lineare attraverso la decomposizione Palu
// sol ed err non sono costanti siccome devono essere aggiornati
// matrici e vettori sono passati per riferimento
void Palu_matrix(const Matrix2d &A, const Vector2d &b, const Vector2d &c, Vector2d &sol, double &err){

// controllo se la matrice è invertibile tramite il determinante
if (A.determinant() != 0) {
	
	// siccome la matrice A è 2x2 invertibile (buon condizionamento) uso la decomposizione PartialPivLU per velocizzare
	sol = A.partialPivLu().solve(b);

	// uso la norma euclidea per calcolare l'errore relativo
	err = ((c - sol).norm()) / (c.norm());
} 
else {
	// uso fullPivLu per avere maggiore robustezza
	sol = A.fullPivLu().solve(b);
}
}

// funzione per risolvere il sistema lineare attraverso la decomposizione QR
void QR_matrix(const Matrix2d &A, const Vector2d &b, const Vector2d &c, Vector2d &sol, double &err){

// siccome la matrice A è di piccole dimensioni uso Householder reflections per velocizzare
// decomposizione molto stabile numericamente
sol = A.householderQr().solve(b);
err = ((c - sol).norm()) / (c.norm());
}
