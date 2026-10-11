#include <stdio.h>
 
 int main() {
 	int m, n, p;
 	
 	do {
 	printf("Enter rows and columns of A(m n): ");
 	scanf("%d%d", &m, &n);
 	
 	printf("Enter columns of B (p): ");
 	scanf("%d", &p);
 	
 	if (m <= 0 || n <= 0 || p <= 0) printf("Boyutlar pozitif tamsayi olmalidir!\n");
 	
	}while (m <= 0 || n <= 0 || p <= 0);
 	
 	int A[m][n];
 	int B[n][p];
 	int C[m][p];
 	
 	// A matrix 
 	printf("Enter elements of A:\n");
 	for(int i=0;i<m;i++) {
 		for(int j=0; j<n; j++) {
 			scanf("%d", &A[i][j]);
		 }
	 }
 	
 	// B matrix
 	printf("Enter elements of B:\n");
 	for(int i=0; i<n;i++) {
 		for(int j=0;j<p;j++) {
 			scanf("%d", &B[i][j]);
		 }
	 }
 	
 	// Matrix multiplication
 	for(int i=0; i<m;i++) {
 		for(int j=0; j<p;j++) {
 			
 			C[i][j] =0;
 			
 			for(int k=0;k<n;k++) {
 				C[i][j] += A[i][k] * B[k][j];
			 }
		 }
	 }
	 
	 // Result
	 printf("Result matrix C = A * B:\n");
	 
	 for(int i =0;i<m;i++) {
	 	for(int j=0;j<p;j++) {
	 		printf("%d ", C[i][j]);	
		 }
		 printf("\n");
	 }
  	
  	return 0;
  	
 }