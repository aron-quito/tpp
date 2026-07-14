with open("/Users/aron/.gemini/antigravity-ide/brain/b25ef874-a05e-409a-84c6-e0fd657006ac/walkthrough.md", "a") as f:
    f.write("\n\n## Generación y Descifrado de Enigma Real\n")
    f.write("- Se creó un script generador `generate_enigma_to.py` que crea el archivo `test/enigma_real.to` con toda la lógica de los rotores I, II y III, el Reflector B, y el mecanismo de odómetro para probar combinaciones.\n")
    f.write("- Se ajustó el código del analizador léxico (`lexer.l`) compilándolo nuevamente con `flex` para que soportara los caracteres `[` y `]` para arreglos de manera global.\n")
    f.write("- Se actualizaron nombres de variables para que no tuvieran guiones bajos (`_`), debido a que el analizador léxico de TPP no los admite.\n")
    f.write("- Se incrementó la capacidad de la memoria ROM en el Linker Script de Logisim (`RV32I_SC_Logisim/sw/buildenv/linker/smallriscv_logi.ld`) de 4K a 32K, ya que la inicialización de arreglos extensa generó un binario de 8.5 KB.\n")
    f.write("- Finalmente se compiló la máquina Bombe (fuerza bruta de Enigma) a código ensamblador de RV32I exitosamente, obteniendo el `rom.hex`.\n")
