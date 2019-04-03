#include <iostream>
#include <string.h>
#include <stdlib.h>

class Matrix {
private:
	int col, row; // col = i, row = j
	double **matrix;
public:
	Matrix(int c, int r) {
		col = c;
		row = r;
		int scale;
		
		matrix = new double* [col];  // 2nd array 
		scale = sizeof(int)*row;
		
		for(int i=0; i<col; i++){
			matrix[i] = new double [row];
			memset(matrix[i], 0, scale);
		}
		
	}
	void initMatrix() { // initalize matrix by random value 
		double rnd;
		int set;
		
		for(int i=0; i<col; i++) {
			for(int j=0; j<row; j++) {
				rnd=(double)rand()/RAND_MAX;
				set=rnd*100;
				rnd =(double)set/100;
				
				matrix[i][j] = rnd;	
			}
		}
	}
	void show() { // show matrix
		for(int i=0; i<col; i++) { 
			for(int j=0; j<row; j++) {
				std::cout<<matrix[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	double *selectMatrixRow(int select) { // get row want line
		double *temp = new double [row];
		
		for(int i=0; i<row; i++) {
			temp[i] = matrix[select][i];
		}
		return temp;
	}
	double *selectMatrixCol(int select) { // get coloumn want line
		double *temp = new double [col];
		
		for(int i=0; i<col; i++) {
			temp[i] = matrix[i][select];
		}
		return temp;
	}
	void deleteMatrix(){ // delete matrix
		delete matrix;
	}
};

double scalarProd(double *input1, double *input2, int len) {	// scalar mul 
	double result = 0.0;
	
	for(int i=0;i<len;i++){
		result += input1[i]*input2[i];
		std::cout<<input2[i]<<"  "<<input1[i]<<" ";
	}
	return result;
}
Matrix matrixVectorMul(Matrix input1, Matrix input2, int n, int m, int l) {
	Matrix temp(n, l);
	double result = 0.0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<l; j++) {
			result = 0.0;
			for(int k=0; k<m; k++) {
				result += input1.retValue(i, k) * input2.retValue(k, j);
			}
			temp.changeValue(i, j, result);
		}
	}
	return temp;	
}

/***************************/ 
/*  to use matrixVectorMul */ 
/*    create new Matrix    */ 
/***************************/

