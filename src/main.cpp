#include <iostream>

#include "FFT.hpp"
#include "polinomio.hpp"

#include <complex>
using cd = std::complex<double>;
const double PI = acos(-1);

void fft(std::vector<cd>& a, bool invert) {
  int n = a.size();
  if (n == 1)
    return;

  std::vector<cd> a0(n / 2), a1(n / 2);
  for (int i = 0; 2 * i < n; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }
  fft(a0, invert);
  fft(a1, invert);

  double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for (int i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if (invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  }
}

int main() {
  int n, a;
  std::cin >> n;
  std::vector<cd> poly;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    poly.push_back(cd(a, 0));
  }

  for (int i = 0; i < n; i++) {
    std::cout << poly[i] << " ";
  }

  fft(poly, false);

  for (int i = 0; i < n; i++) {
    std::cout << poly[i] << " ";
  }
  std::cout << "\n";
  return 0;
}