#ifndef MATRIX3D_H
#define MATRIX3D_H


class Matrix3D
{
    private:
         double Matrix[3][3];
         int increment;
         int count;
    public:
        Matrix3D(const double mat[3][3],int inc=1);
        double det() const;
        Matrix3D inverse() const;
        void getMatrix() const;
        void setIncrement(int val);
        void Increment();
        Matrix3D operator+(const Matrix3D &other) const;
        Matrix3D operator-(const Matrix3D &other) const;
        Matrix3D operator*(const Matrix3D &other) const;
        bool operator>(const Matrix3D &other) const;
        bool operator<(const Matrix3D &other) const;
        bool operator>=(const Matrix3D &other) const;
        bool operator<=(const Matrix3D &other) const;
        bool operator==(const Matrix3D &other) const;
        bool operator!=(const Matrix3D &other) const;
};

#endif // MATRIX3D_H
