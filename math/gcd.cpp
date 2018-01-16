//Iterative GCD in C++
typedef int tipo; // can also be long long
tipo GCD(tipo a, tipo b){
  tipo x;
  while(b>0){ x=a; a=b; b=x%a; }
  return a;
}