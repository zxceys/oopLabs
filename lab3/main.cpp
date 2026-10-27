#include <iostream>
#include <stdexcept>

/** @brief Класс комплексного числа. Перегрузки операторов для работы с числами. */
class Complex {
private:
    double destv, mnim;  // действительная и мнимая части
    mutable int views;
    static int count;

public:
    /** @brief Создать нулевое число. */
    Complex() : destv(0), mnim(0), views(0) { ++count; }
    /** @brief Создать число с одной действительной частью. */
    explicit Complex(double a) : destv(a), mnim(0), views(0) { ++count; }
    /** @brief Создать число с двумя частями. */
    Complex(double a, double b) : destv(a), mnim(b), views(0) { ++count; }
    Complex(const Complex& other)
        : destv(other.destv), mnim(other.mnim), views(0) { ++count; }

    Complex& operator=(const Complex& other) {
        if (this != &other) { destv = other.destv; mnim = other.mnim; views = 0; }
        return *this;
    }

    ~Complex() { --count; }

    double getDestv() const { ++views; return destv; }
    double getMnim() const { ++views; return mnim; }
    int getViews() const { return views; }
    static int getCount() { return count; }

    /** @brief Вывести число на экран. */
    void print() const {
        std::cout << destv;
        if (mnim < 0) std::cout << " - " << -mnim;
        else std::cout << " + " << mnim;
        std::cout << "i";
    }

    Complex& operator++() { ++destv; return *this; }
    Complex operator++(int) { Complex old(*this); ++(*this); return old; }
    Complex& operator--() { --destv; return *this; }
    Complex operator--(int) { Complex old(*this); --(*this); return old; }

    /** @brief Прибавить комплексное число. */
    Complex& operator+=(const Complex& b) {
        destv += b.destv;
        mnim += b.mnim;
        return *this;
    }
    Complex& operator-=(const Complex& b) {
        destv -= b.destv;
        mnim -= b.mnim;
        return *this;
    }
    Complex& operator*=(const Complex& b) {
        double a = destv * b.destv - mnim * b.mnim;
        double c = destv * b.mnim + mnim * b.destv;
        destv = a;
        mnim = c;
        return *this;
    }
    Complex& operator/=(const Complex& b) {
        double d = b.destv * b.destv + b.mnim * b.mnim;
        if (d == 0) throw std::invalid_argument("Division by zero");
        double a = (destv * b.destv + mnim * b.mnim) / d;
        double c = (mnim * b.destv - destv * b.mnim) / d;
        destv = a;
        mnim = c;
        return *this;
    }

    friend Complex operator+(Complex a, const Complex& b) { a += b; return a; }
    friend Complex operator-(Complex a, const Complex& b) { a -= b; return a; }
    friend Complex operator*(Complex a, const Complex& b) { a *= b; return a; }
    friend Complex operator/(Complex a, const Complex& b) { a /= b; return a; }

    double mod2() const { return destv * destv + mnim * mnim; }
    bool operator<(const Complex& b) const { return mod2() < b.mod2(); }
    bool operator>(const Complex& b) const { return mod2() > b.mod2(); }
    bool operator<=(const Complex& b) const { return mod2() <= b.mod2(); }
    bool operator>=(const Complex& b) const { return mod2() >= b.mod2(); }
    bool operator==(const Complex& b) const { return destv == b.destv && mnim == b.mnim; }
    bool operator!=(const Complex& b) const { return !(*this == b); }
};

int Complex::count = 0;

int main() {
    Complex zero;
    Complex number(5);
    Complex a(3, 2), b(1, 4);
    // Complex bad = 5; // Ошибка компиляции из-за explicit.
    std::cout << "Objects: " << Complex::getCount() << '\n';
    std::cout << "Zero: "; zero.print(); std::cout << '\n';
    std::cout << "Number: "; number.print(); std::cout << '\n';
    std::cout << "a: "; a.print(); std::cout << "  b: "; b.print(); std::cout << '\n';

    Complex c = a + b; std::cout << "a+b: "; c.print(); std::cout << '\n';
    c = a - b; std::cout << "a-b: "; c.print(); std::cout << '\n';
    c = a * b; std::cout << "a*b: "; c.print(); std::cout << '\n';
    c = a / b; std::cout << "a/b: "; c.print(); std::cout << '\n';

    c = a; c += b; std::cout << "a+=b: "; c.print(); std::cout << '\n';
    c = a; c -= b; std::cout << "a-=b: "; c.print(); std::cout << '\n';
    c = a; c *= b; std::cout << "a*=b: "; c.print(); std::cout << '\n';
    c = a; c /= b; std::cout << "a/=b: "; c.print(); std::cout << '\n';

    c = a; ++c; std::cout << "++a: "; c.print(); std::cout << '\n';
    c = a; Complex old = c++; std::cout << "a++ returned: "; old.print(); std::cout << " new: "; c.print(); std::cout << '\n';
    c = a; --c; std::cout << "--a: "; c.print(); std::cout << '\n';
    c = a; old = c--; std::cout << "a-- returned: "; old.print(); std::cout << " new: "; c.print(); std::cout << '\n';

    std::cout << std::boolalpha;
    std::cout << "a<b " << (a < b) << ", a>b " << (a > b)
              << ", a<=b " << (a <= b) << ", a>=b " << (a >= b)
              << ", a==b " << (a == b) << ", a!=b " << (a != b) << '\n';

    const Complex fixed(7, -2);
    std::cout << "Views before: " << fixed.getViews() << '\n';
    std::cout << "Parts: " << fixed.getDestv() << " and " << fixed.getMnim() << '\n';
    std::cout << "Views after: " << fixed.getViews() << '\n';

    try {
        c = a / zero;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
    std::cout << "Objects at end of main: " << Complex::getCount() << '\n';
}
