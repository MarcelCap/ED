//Sejam a, b inteiros positivos. O Máximo divisor comum de a e b eh dado por:
gcd(int a, int b) //mdc
{
  if(b>0)  return a;
  else  return gcd(b, a%b);
}
lcm(int a, int b) //mmc
{
  return (a*b)/gcd(a, b);
}
