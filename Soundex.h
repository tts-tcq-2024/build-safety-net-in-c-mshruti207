// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

// Returns true if and only if n is a prime number.
bool IsPrime(int n) {
  // Trivial case 2: even numbers
  if (n % 2 == 0) return n == 2;

   }

  // n has no integer factor in the range (1, n), and thus is prime.
  return true;
}
