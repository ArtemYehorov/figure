#include<iostream>
using namespace std;

class Figure
{
public:
	virtual double Square() = 0;
	virtual double Perimeter() = 0; 

	virtual void Print()
	{
		cout << "Square - " << Square() << "\n";
		cout << "Perimeter - " << Perimeter() << "\n\n";
	}

};

class Point : public Figure
{
public:

	int PointX = 0;
	int PointY = 0;

	double Square() override 
	{
		cout << "Not for the point!\n";
		return 0;
	}

	double Perimeter() override
	{
		cout << "Not for the point!\n";
		return 0;
	}

	void Print()
	{
		cout << "PointX - " << PointX << "\n";
		cout << "PointY - " << PointY << "\n";
		Figure::Print();
	}
};

class Line : public Figure
{
public:
	int LineStart = 0;
	int LineEnd = 10;

	void SetEndLine(int LE)
	{
		if (LE > 0)
		{
			LineEnd = LE;
		}
		else
		{
			LineEnd = 10;
		}
	}

	int GetEndLine() const
	{
		return LineEnd;
	}

	double Square() override
	{
		cout << "Not for the Line!\n";
		return 0;
	}

	double Perimeter() override
	{
		cout << "Not for the Line!\n";
		return 0;
	}

	void Print()
	{
		cout << "LineStart - " << LineStart << "\n";
		cout << "LineEnd - " << GetEndLine() << "\n";
		Figure::Print();
	}
};

#pragma region Ellipse

class Ellipse : public Figure
{
public:
	
	double Radius1 = 10;
	double Radius2 = 9;

	void Print()
	{
		cout << "Radius1 - " << Radius1 << "\n";
		cout << "Radius2 - " << Radius2 << "\n";
		Figure::Print();
	}

	double Square() override
	{
		return 3.14 * Radius1 * Radius2;
	}

	double Perimeter() override
	{
		return 4 * ((3.14 * Radius1 * Radius2 + (Radius1 - Radius2) * (Radius1 - Radius2)) / (Radius1 + Radius2));
	}
};

class Circle : public Ellipse
{
public:

	void Print()
	{
		cout << "Radius - " << Radius1 << "\n";
		Figure::Print();
	}

	double Square() override
	{
		return 3.14 * Radius1 * Radius1;
	}

	double Perimeter() override
	{
		return 2 * 3.14 * Radius1;
	}
};

#pragma endregion

class Polygon : public Figure {};

#pragma region TRIANGLE

class Triangle : public Polygon
{
public:
	double A;
	double B;
	double C;
	double Height;

	double Square() override
	{
		return (0.5 * A * Height);
	}

	double Perimeter() override
	{
		return A + B + C;
	}

	void Print()
	{
		cout << "A - " << A << "\n";
		cout << "B - " << B << "\n";
		cout << "C - " << C << "\n";
		cout << "Height - " << Height << "\n";
		Figure::Print();
	}
};

class OrdinaryAcuteTriangle : public Triangle
{
public:
	void Print()
	{
		cout << "OrdinaryAcuteTriangle" << "\n";
		Triangle::Print();
	}
};

class IsoscelesAcuteTriangle : public Triangle
{
public:
	void Print()
	{
		cout << "IsoscelesAcuteTriangle" << "\n";
		Triangle::Print();
	}
};

class EquilateralAcuteTriangle : public Triangle
{
public:
	void Print()
	{
		cout << "EquilateralAcuteTriangle" << "\n";
		Triangle::Print();
	}
};

class RegularObtuseTriangle : public Triangle
{
public:
	void Print()
	{
		cout << "RegularObtuseTriangle" << "\n";
		Triangle::Print();
	}
};

class  IsoscelesObtuseTriangle : public Triangle
{
public:
	void Print()
	{
		cout << "IsoscelesObtuseTriangle" << "\n";
		Triangle::Print();
	}
};

class RegularRightTriangle : public Triangle
{
public:
	void Print()
	{
		cout << "RegularRightTriangle" << "\n";
		Triangle::Print();
	}
};

class IsoscelesRightTriangle : public Triangle
{
public:
	void Print()
	{
		cout << "IsoscelesRightTriangle" << "\n";
		Triangle::Print();
	}
};

#pragma endregion

#pragma region QUADRILATERAL

class Quadrilateral : public Polygon
{
public:
	double A;
	double B;
	double C;
	double D;
	double Height_1;
	double Height_2;
	double Diagonal_1 = sqrt(pow(B, 2) + pow(A, 2));
	double Diagonal_2 = sqrt(pow(D, 2) + pow(C, 2));

	double Perimeter() override
	{
		return A + B + C + D;
	}

	double Square() override
	{
		return ((Diagonal_1 * Diagonal_2) / 2) * sin(A * 3.14 / 180);
	}

	void Print()
	{
		cout << "A - " << A << "\n";
		cout << "B - " << B << "\n";
		cout << "C - " << C << "\n";
		cout << "D - " << D << "\n";
		cout << "Diagonal_1 - " << Diagonal_1 << "\n";
		cout << "Diagonal_2 - " << Diagonal_2 << "\n";
		cout << "Height_1 - " << Height_1 << "\n";
		cout << "Height_2 - " << Height_2 << "\n";
		Figure::Print();
	}
};

class Parallelogram : public Quadrilateral
{
public:

	double Square() override 
	{
		return A * Height_1;
	}

	void Print()
	{
		Quadrilateral::Print();
	}
};

class Rectangle : public Parallelogram
{
public:

	double Square() override 
	{
		return A * B;
	}

	void Print()
	{
		Parallelogram::Print();
	}

};

class Square : public Rectangle
{
	void Print()
	{
		Parallelogram::Print();
	}
};

class Rhombus : public Parallelogram
{
	void Print()
	{
		Quadrilateral::Print();
	}
};

class Trapezoid : public Quadrilateral
{
	double Square() override
	{
		return 0.5 * (A + B) * Height_1;
	}

	void Print()
	{
		Quadrilateral::Print();
	}
};

class Deltoid : public Quadrilateral
{
	double Square() override 
	{
		return 0.5 * Height_1 * Height_2;
	}
	void Print()
	{
		Quadrilateral::Print();
	}
};

#pragma endregion

int main()
{
	Ellipse q;
	q.Print();

	Line w;
	w.Print();

	Point e;
	e.Print();

	Circle r;
	r.Print();

	Triangle y;
	y.Print();

	RegularRightTriangle u;
	u.Print();
}