#!/usr/bin/env python3
import sys
import os
import shutil
import subprocess

def main():
    if len(sys.argv) < 2:
        print("Uso: python3 compile_to_logisim.py <archivo.to>")
        sys.exit(1)

    archivo_to = sys.argv[1]

    if os.path.exists("output.s"):
        os.remove("output.s")

    # 1. Correr el compilador
    print(f"[*] Compilando '{archivo_to}' con el compilador TPP...")
    result = subprocess.run(["./compilador", archivo_to])
    if result.returncode != 0:
        print("[-] Error durante la compilación del código fuente TPP.")
        sys.exit(result.returncode)

    # 2. Verificar existencia de output.s
    if not os.path.exists("output.s"):
        print("[-] Error: No se generó el archivo 'output.s'.")
        sys.exit(1)

    # 3. Copiar a main.S
    destino = "../RV32I_SC_Logisim/sw/apps/00_demo/main.S"
    print(f"\n[*] Copiando 'output.s' hacia '{destino}' ...")
    try:
        shutil.copy("output.s", destino)
    except Exception as e:
        print(f"[-] Error al copiar el archivo: {e}")
        sys.exit(1)

    # 4. Compilar binario en Logisim (00_demo)
    demo_dir = "../RV32I_SC_Logisim/sw/apps/00_demo"
    print(f"[*] Ejecutando 'make clean && make' en '{demo_dir}' ...\n")
    
    # Clean
    subprocess.run(["make", "clean"], cwd=demo_dir)
    
    # Make
    result_make = subprocess.run(["make"], cwd=demo_dir)

    if result_make.returncode == 0:
        print("\n[+] ¡Éxito! Todo el flujo se completó.")
        print("[+] El binario 'rom.hex' (y memoria RAM) se ha generado.")
        print("[+] Ahora puedes abrir Logisim Evolution, cargar el ROM y correr el procesador.")
    else:
        print("\n[-] Error al ensamblar y enlazar (Linker) el binario en Logisim.")
        sys.exit(result_make.returncode)

if __name__ == "__main__":
    main()
