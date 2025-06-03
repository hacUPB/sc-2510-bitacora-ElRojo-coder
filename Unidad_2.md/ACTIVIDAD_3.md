// Inicio del programa
``` AMS
(INICIO)
@SCREEN

// Inicializar variables
@16384   
D=A
@16     
M=D

// Leer entrada de teclado
@24576  
D=M  
@100
D=A
@24576
D = M - D
@Bitmap
D;JEQ 
@BORRAR
0;JMP

// Si se presiona "d", se dibuja la imagen
(Bitmap)
  D=A
  @R12
  AD=D+M
  M=-1
  AD=A+1
  @7
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @3971
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @5
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @3971
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @5
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24535
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24535
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24529
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @7
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @20568
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @22360
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @1800
  D=D+A
  A=D-A
  M=A-D
  
  @INICIO
  0;JMP

// Si no se presiona ninguna tecla, se borra la imagen
(BORRAR)
  @SCREEN
  D=A
  @8192
  D=D+A
  @R0
  M=D  // Apuntar a la pantalla

(BORRAR_LOOP)
  @R0
  A=M
  M=0  // Borra el píxel
  @R0
  M=M+1  // Avanza al siguiente píxel
  D=M
  @24576
  D=D-A
  @BORRAR_LOOP
  D;JLT  // Continua mientras no haya llegado al final

  @INICIO
  0;JMP
  ```
