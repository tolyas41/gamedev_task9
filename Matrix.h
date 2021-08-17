#pragma once
#include <string>

class Matrix {

	int rows;
	int columns;
	double** data;
	friend class ConsoleLoader;
	friend class FileLoader;
	friend class QuickSort;
	friend class UsualSort;
public:

	Matrix();
	Matrix(int num, int in_rows, int in_columns);
	Matrix(const double* array, int in_rows, int in_columns);
	Matrix(const Matrix& source);
	Matrix(Matrix&& source);
	Matrix(const char* char_array);
	Matrix(std::nullptr_t ptr);
	~Matrix();

	Matrix& operator=(const Matrix& source);
	Matrix& operator=(Matrix&& source) noexcept;
	const Matrix operator+(Matrix& right_obj) const;
	const Matrix operator+(int additionValue) const;
	const Matrix operator+(const char* str) const;
	const Matrix operator-(Matrix& right_obj) const;
	const Matrix operator-(int subtractionValue) const;
	const Matrix operator-(const char* str) const;
	const Matrix operator*(Matrix& right_obj) const;
	const Matrix operator*(int multiplicationValue) const;
	const Matrix operator*(const char* str) const;
	const Matrix operator/(Matrix right_obj) const;
	const Matrix operator/(int divisionValue) const;
	const Matrix operator/(const char* str) const;
	Matrix& operator+=(Matrix& right_obj);
	Matrix& operator+=(int additionValue);
	Matrix& operator-=(Matrix& right_obj);
	Matrix& operator-=(int subtractionValue);
	Matrix operator*=(Matrix& right_obj);
	Matrix operator*=(int multiplicationValue);
	Matrix operator/=(Matrix right_obj);
	Matrix operator/=(int divisionValue);
	bool operator>(const Matrix& right_obj);
	bool operator<(const Matrix& right_obj);
	bool operator>=(const Matrix& right_obj);
	bool operator<=(const Matrix& right_obj);
	bool operator==(const Matrix& right_obj);
	bool operator!=(const Matrix& right_obj);

	void print_array();
	std::string to_string(const Matrix& source);
	double dataSumm(const Matrix& obj);
	int checkOverflowAddition(int valueLeft, int valueRight) const;
	int checkOverflowSubtraction(int valueLeft, int valueRight) const;
	double DiagonalsProduct() const;
};

