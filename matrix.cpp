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
		
		matrix = new double* [col];
		scale = sizeof(int)*row;
		
		for(int i=0; i<col; i++){
			matrix[i] = new double [row];	
			memset(matrix[i], 0, scale);
		}
		
	}
	void initMatrix() {
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
	void show() {
		for(int i=0; i<col; i++) { 
			for(int j=0; j<row; j++) {
				std::cout<<matrix[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	double *selectMatrixRow(int select) {
		double *temp = new double [row];
		
		for(int i=0; i<row; i++) {
			temp[i] = matrix[select][i];
		}
		return temp;
	}
	double *selectMatrixCol(int select) {
		double *temp = new double [col];
		
		for(int i=0; i<col; i++) {
			temp[i] = matrix[i][select];
		}
		return temp;
	}
	void deleteMatrix(){
		delete matrix;
	}
};

double scalarProd(double *input1, double *input2, int len) {	
	double result = 0.0;
	
	for(int i=0;i<len;i++){
		result += input1[i]*input2[i];
		std::cout<<input2[i]<<"  "<<input1[i]<<" ";
	}
	return result;
}
