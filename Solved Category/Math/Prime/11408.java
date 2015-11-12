import java.util.Scanner;

public class Main {

	static boolean[] isPrime;
	static int[] primes;

	static void sieve() {
		isPrime = new boolean[5000001];
		int index = 0;
		primes = new int[isPrime.length];
		for (int i = 2; i < isPrime.length; i++)
			if (!isPrime[i]) {
				for (int j = i + i; j < isPrime.length; j += i)
					isPrime[j] = true;
				primes[index++] = i;

			}

	}

	public static void main(String[] args) {
		boolean[] deprime = new boolean[5000001];
		int[] range = new int[5000001];
		sieve();
		for (int i = 0; i < deprime.length; i++) {
			deprime[i] = isDeprime(i);
		}
		range[0] = 0;
		for (int i = 1; i < range.length; i++)
			range[i] = range[i - 1] + ((deprime[i]) ? 1 : 0);
		Scanner sc = new Scanner(System.in);

		while (true) {
			int n = sc.nextInt();
			if (n == 0)
				break;
			int m = sc.nextInt();

			System.out.println(range[m] - range[n-1]/* + ((deprime[n]) ? 1 : 0)*/);

		}
	}

	private static boolean isDeprime(int i) {
		int sum = 0;
		int index = 0;
		int pf = primes[index++];
		while (i > 1 && pf * pf <= i) {
			if (i % pf == 0)
				sum += pf;
			while (i % pf == 0) {
				i /= pf;
			}
			pf = primes[index++];
		}
		if (i != 1)
			sum += i;
		return isPrime(sum);
	}

	private static boolean isPrime(int i) {
		if (i < primes.length)
			return !isPrime[i];
		else {
			int root = (int) Math.sqrt(i);
			for (int j = 2; j <= root; j++)
				if (i % j == 0)
					return false;
		}
		return true;
	}
}
