## Solución
Transforma el programa en alto nivel anterior para que utilice un ciclo for en vez de un ciclo while.

``` C++
#include <iostream>

int main() {
   int sum = 0;
   
   // Ciclo for en lugar de while
   for (int i = 1; i <= 100; i++) {
       sum += i;
   }

   std::cout << "La suma de los números del 1 al 100 es: " << sum << std::endl;
   return 0;
}
