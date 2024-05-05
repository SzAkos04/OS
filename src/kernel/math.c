#include "math.h"

static double factorial(int n) {
    static double cache[TERMS] = {1};
    if (n <= 1) {
        return 1;
    }
    if (n < TERMS && cache[n]) {
        return cache[n];
    }
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    if (n < TERMS) {
        cache[n] = result;
    }
    return result;
}

int abs(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

double acos(double x) {
    if (x < -1.0 || x > 1.0) {
        return NAN;
    }
    return atan2(sqrt(1.0 - x * x), x);
}

double acosh(double x) {
    if (x < 1.0) {
        return NAN;
    }
    return log(x + sqrt(x * x - 1.0));
}

double asin(double x) {
    if (x < -1.0 || x > 1.0) {
        return NAN;
    } else if (x == 1.0) {
        return M_PI / 2;
    } else if (x == -1.0) {
        return -M_PI / 2;
    } else if (x == 0.0) {
        return 0.0;
    } else {
        return atan2(x, sqrt(1.0 - x * x));
    }
}

double atan(double x) {
    double result = x;
    double term = x;
    double x_squared = x * x;

    int sign = -1;

    for (int i = 3; i < TERMS; i += 2) {
        term *= x_squared;
        result += sign * term / i;
        sign = -sign;
    }

    return result;
}

double atan2(double y, double x) {
    if (x > 0) {
        return atan(y / x);
    } else if (x < 0 && y >= 0) {
        return atan(y / x) + M_PI;
    } else if (x < 0 && y < 0) {
        return atan(y / x) - M_PI;
    } else if (x == 0 && y > 0) {
        return M_PI / 2;
    } else if (x == 0 && y < 0) {
        return -M_PI / 2;
    } else {
        return NAN;
    }
}

double atanh(double x) {
    if (x <= -1.0 || x >= 1.0) {
        return NAN;
    }

    return 0.5 * log((1.0 + x) / (1.0 - x));
}

double cbrt(double x) {
    if (x == 0.0) {
        return 0.0;
    }

    double guess = x / 3.0;
    double last = 0;

    while (fabs(guess - last) > M_EPSILON) {
        last = guess;
        guess = (2 * last + x / (last * last)) / 3.0;
    }

    return guess;
}

double ceil(double x) {
    int i = (int)x;

    if (x > 0 && x != i) {
        i++;
    }

    return (double)i;
}

double cos(double x) {
    double result = 0.0;
    double x_power = 1.0;
    double sign = 1.0;
    for (int n = 0; n < TERMS; n++) {
        result += sign * x_power / factorial(2 * n);
        x_power *= -x * x;
        sign = -sign;
    }
    return result;
}

double cosh(double x) { return (exp(x) + exp(-x)) / 2; }

double exp(double x) {
    double result = 1.0;
    double term = 1.0;

    for (int n = 1; n <= TERMS; n++) {
        term *= x / n;
        result += term;
    }

    return result;
}

double fabs(double x) { return x < 0 ? -x : x; }

double floor(double x) {
    int i = (int)x;

    if (x < 0 && x != i) {
        i--;
    }

    return (double)i;
}

double hypot(double x, double y) { return sqrt(x * x + y * y); }

double log(double x) {
    if (x <= 0) {
        return NAN;
    }

    double result = 0.0;
    double term = (x - 1) / (x + 1);
    double term_power = term;

    for (int n = 1; n <= TERMS; n++) {
        result += term_power / n;
        term_power *= term * term;
    }

    return 2 * result;
}

double log10(double x) {
    if (x <= 0) {
        return NAN;
    }
    return log(x) / log(10.0);
}

double pow(double x, double y) {
    for (int i = 1; i < y; i++) {
        x *= x;
    }
    return x;
}

double sin(double x) {
    double result = 0.0;
    double x_power = x;
    double sign = 1.0;

    for (int n = 0; n < 100; n++) {
        result += sign * x_power / factorial(2 * n + 1);
        x_power *= -x * x;
        sign = -sign;
    }
    return result;
}

double sinh(double x) { return (exp(x) - exp(-x)) / 2; }

double sqrt(double x) {
    if (x < 0) {
        return NAN;
    }

    if (x == 0.0 || x == 1.0) {
        return x;
    }

    double guess = x / 2.0;
    double last;

    do {
        last = guess;
        guess = 0.5 * (guess + x / guess);
    } while (fabs(guess - last) > M_EPSILON);

    return guess;
}

double tan(double x) { return sin(x) / cos(x); }

double tanh(double x) { return sinh(x) / cosh(x); }

int round(double x) {
    if (x < 0) {
        return (int)(x - 0.5);
    } else {
        return (int)(x + 0.5);
    }
}
