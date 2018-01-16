Calcula el perimetro de un poligono representado como un vector de puntos. IMPORTANTE: Definir P[0] = P[n-1] para cerrar el poligono. La estructura point debe estar definida, al igual que el metodo euclideanDistance.

double perimeter(vector<point> P) {
	double result = 0.0;
  for (int i = 0; i < P.size()-1; i++){
  	result += euclideanDistance(P[i], P[i+1]);
  }
  return result; 
}
