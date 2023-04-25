
#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }
    bool operator ==(Fraction other)
    {
        return (numerator_ == other.numerator_) && (denominator_ == other.denominator_);
    }
    bool operator !=(Fraction other)
    {
        return (numerator_ != other.numerator_) && (denominator_ != other.denominator_);
    }
    bool operator <(Fraction other)
    {
        return (numerator_ / denominator_) < (other.numerator_ / other.denominator_);
    }
    bool operator >(Fraction other)
    {
        return (numerator_ / denominator_) > (other.numerator_ / other.denominator_);
    }
    bool operator <=(Fraction other)
    {
        return (numerator_ / denominator_) <= (other.numerator_ / other.denominator_);
    }
    bool operator >=(Fraction other)
    {
        return (numerator_ / denominator_) >= (other.numerator_ / other.denominator_);
    }
    Fraction operator+(Fraction other)
    {
        int a, b;
        b = denominator_ * other.denominator_;
        a = numerator_ * other.denominator_ + other.numerator_ * denominator_;

        return reduce(a, b);
    };

    Fraction operator-(Fraction other)
    {
        int a, b;
        b = denominator_ * other.denominator_;
        a = numerator_ * other.denominator_ - other.numerator_ * denominator_;

        //    return Fraction(numerator_, denominator_);
        return reduce(a, b);
    }

    Fraction operator*(Fraction other)
    {
        int a, b;
        b = denominator_ * other.denominator_;
        a = numerator_ * other.numerator_;

        return reduce(a, b);
    }

    Fraction operator/(Fraction other)
    {
        int a, b;
        b = denominator_ * other.numerator_;
        a = numerator_ * other.denominator_;

        return 	reduce(a, b);
    }

    Fraction& operator++()
    {
        numerator_ = numerator_ + denominator_;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--()
    {
        numerator_ = numerator_ - denominator_;
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }




    void print()
    {
        std::cout << numerator_ << '/' << denominator_ << std::endl;
    }

    int NOD(int a, int b)
    {
        //    int a = numerator_;
        //	int b = denominator_;
        if (a < b) { std::swap(a, b); }
        while (a % b != 0)
        {
            a = a % b;
            std::swap(a, b);
        }
        return b;
    }

    Fraction reduce(int a, int b)
    {
        int n = NOD(a, b);
        a = a / n;
        b = b / n;
        return Fraction(a, b);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int numerator1;
    int denumerator1;
    int numerator2;
    int denumerator2;

    std::cout << "¬ведите числитель дроби 1 ";
    std::cin >> numerator1;
    std::cout << "¬ведите знаменатель дроби 1 ";
    std::cin >> denumerator1;
    std::cout << "¬ведите числитель дроби 2 ";
    std::cin >> numerator2;
    std::cout << "¬ведите знаменатель дроби 2 ";
    std::cin >> denumerator2;

    std::cout << numerator1 << '/' << denumerator1 << " + " <<
        numerator2 << '/' << denumerator2 << " = ";
    Fraction f1(numerator1, denumerator1);
    Fraction f2(numerator2, denumerator2);
    Fraction f3 = f1 + f2;
    f3.print();

    std::cout << numerator1 << '/' << denumerator1 << " - " <<
        numerator2 << '/' << denumerator2 << " = ";
    Fraction f4 = f1 - f2;
    f4.print();

    std::cout << numerator1 << '/' << denumerator1 << " * " <<
        numerator2 << '/' << denumerator2 << " = ";
    Fraction f5 = f1 * f2;
    f5.print();

    std::cout << numerator1 << '/' << denumerator1 << " / " <<
        numerator2 << '/' << denumerator2 << " = ";
    Fraction f6 = f1 / f2;
    f6.print();

    std::cout << "++" << numerator1 << '/' << denumerator1 << " * " <<
        numerator2 << '/' << denumerator2 << " = ";
    Fraction f7 = ++f1 * f2;
    f7.print();


    std::cout << "«начение дроби 1 = ";
    f1.print();


    std::cout << numerator1 << '/' << denumerator1 << "-- * " <<
        numerator2 << '/' << denumerator2 << " = ";
    Fraction f8 = (f1--) * f2;
    f8.print();


    std::cout << "«начение дроби 1 = ";
    f1.print();

    return 0;
}
