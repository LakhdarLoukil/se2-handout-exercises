	double result = 0.0;
	
	void produit_scalaire_seq(double v[], double u[], int n) {
		for (int i = 0; i < n; i++) {
			result += v[i] * u[i];
		}
	}
