//Ishan Chaurasia
//101011068
//BIT 2400 Assignment 1
// May 18, 2018

#include <iostream>

using namespace std;

void makeMatrix(double **matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void showMatrix(double **matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void multiplyMatrix(double **matrixA, double **matrixB, double**matrixC, int RowA, int ColA, int RowB, int ColB)
{
	for (int i = 0; i < RowA; i++)
	{
		for (int j = 0; j < ColB; j++)
		{
			matrixC[i][j] = 0;
		}
	}

	for (int i = 0; i < RowA; i++)
	{
		for (int j = 0; j < ColB; j++)
		{
			for (int k = 0; k < ColA; k++)
			{
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}

	showMatrix(matrixC, RowA, ColB);
}

void transposeMatrix(double **matrixC, double **matrixD, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrixD[j][i] = 0;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrixD[j][i] = matrixC[i][j];
		}
	}

	showMatrix(matrixD, row, col);
}

void eraseMemory(double **matrix, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

void main()
{

	char restart;

	do
	{
		system("CLS");

		int RowA = 0;
		int ColA = 0;
		int RowB = 0;
		int ColB = 0;

		cout << "Step 1a: Enter rows for Matrix [A]: ";
		cin >> RowA;
		cout << endl << "Step 1b: Enter columns for Matrix [A]: ";
		cin >> ColA;

		double **matrixA = new double*[RowA];
		for (int i = 0; i < RowA; i++)
		{
			matrixA[i] = new double[ColA];
		}

		cout << endl << "Step 1c: Enter values for Matrix [A]" << endl;
		makeMatrix(matrixA, RowA, ColA);

		cout << endl << "Step 2a: Enter rows for Matrix [B]: ";
		cin >> RowB;
		cout << endl << "Step 2b: Enter coloumns for Matrix [B]: ";
		cin >> ColB;

		while (RowA != ColB)
		{
			cout << "Error!" << endl << "Rows of Matrix [A] =/= Columns of Matrix [B], Try Again." << endl;
			cout << endl << "Step 2a: Enter rows for Matrix [B]: ";
			cin >> RowB;
			cout << endl << "Step 2b: Enter coloumns for Matrix [B]: ";
			cin >> ColB;
		}

		double **matrixB = new double*[RowB];
		for (int i = 0; i < RowB; i++)
		{
			matrixB[i] = new double[ColB];
		}

		cout << endl << "Step 2c: Enter values for Matrix [B]" << endl;
		makeMatrix(matrixB, RowB, ColB);

		cout << endl << "Step 3: Matrices A and B are:" << endl;
		cout << "[A] =" << endl;
		showMatrix(matrixA, RowA, ColA);
		cout << endl << endl << "[B] =" << endl;
		showMatrix(matrixB, RowB, ColB);

		cout << endl << "Step 4: After multiplying matrices A and B, the result is:" << endl;
		cout << "[A] x [B] = [C] =" << endl;

		double **matrixC = new double*[RowA];
		for (int i = 0; i < RowA; i++)
		{
			matrixC[i] = new double[ColB];
		}

		double **matrixD = new double*[ColB];
		for (int i = 0; i < ColB; i++)
		{
			matrixD[i] = new double[RowA];
		}

		multiplyMatrix(matrixA, matrixB, matrixC, RowA, ColA, RowB, ColB);

		cout << endl << "Step 5: After calculating transpose of matrix C, the result is:" << endl;
		cout << "[C]T = [D] =" << endl;

		transposeMatrix(matrixC, matrixD, RowA, ColB);

		eraseMemory(matrixA, RowA);
		eraseMemory(matrixB, RowB);
		eraseMemory(matrixC, RowA);
		eraseMemory(matrixD, ColB);

		cout << endl << "Would you like to run this program again? Y/N: ";
		cin >> restart;
		cout << endl;

	} while (restart == 'y' || restart == 'Y');

}