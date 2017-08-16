/* Recebe um vetor v e um número n >= 0. 
   Devolve a soma dos elementos positivos
   de v[0..n-1].
   -------------------------------------*/

int soma (int v[], int n) { 
   if (n == 0)
      return 0;
   else {
      int s;
      s = soma (v, n-1);
      if (v[n-1] > 0) s += v[n-1];
      return s; 
   }
}
