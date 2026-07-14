ciphertext = "DAIDYUGSKTBQRJUVYWLMFJIWPQRSLV"
target = "HEILXHITLER"
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

c_indices = [alphabet.index(c) for c in ciphertext]
t_indices = [alphabet.index(c) for c in target]

rotor_1_f = [alphabet.index(c) for c in "AJDKSIRUXBLHWTMCQGZNPYFVOE"] # II
rotor_2_f = [alphabet.index(c) for c in "EKMFLGDQVZNTOWYHXUSPAIBRCJ"] # I
rotor_3_f = [alphabet.index(c) for c in "BDFHJLCPRTXVZNYEIWGAKMUSQO"] # III
reflector_b = [alphabet.index(c) for c in "YRUHQSLDPXNGOKMIEBFZCWVJAT"]

# Inverse mapping for backward pass
rotor_1_b = [0]*26
rotor_2_b = [0]*26
rotor_3_b = [0]*26

for i in range(26):
    rotor_1_b[rotor_1_f[i]] = i
    rotor_2_b[rotor_2_f[i]] = i
    rotor_3_b[rotor_3_f[i]] = i

def arr_to_tpp(name, arr):
    res = f"entero {name}[{len(arr)}];\n"
    for i, val in enumerate(arr):
        res += f"{name}[{i}] = {val};\n"
    return res

stecker_dict = {}
for par in "BQ CR DI EJ KW MT OS PX UZ GH".split():
    stecker_dict[par[0]] = par[1]
    stecker_dict[par[1]] = par[0]

stecker_arr = []
for c in alphabet:
    stecker_arr.append(alphabet.index(stecker_dict.get(c, c)))

code = """
// --- BOMBE: DESCIFRADO DE ENIGMA REAL ---
// Cifrado: DAIDYUGSKTBQRJUVYWLMFJIWPQRSLV
// Objetivo: Termina en HEILXHITLER

"""
code += arr_to_tpp("r1f", rotor_1_f)
code += arr_to_tpp("r2f", rotor_2_f)
code += arr_to_tpp("r3f", rotor_3_f)
code += arr_to_tpp("r1b", rotor_1_b)
code += arr_to_tpp("r2b", rotor_2_b)
code += arr_to_tpp("r3b", rotor_3_b)
code += arr_to_tpp("refb", reflector_b)
code += arr_to_tpp("stecker", stecker_arr)

# Ciphertext
code += arr_to_tpp("mensaje", c_indices)

# Plaintext buffer
code += "entero texto[30];\n"
code += "entero exito;\n"
code += "exito = 0;\n"

# Brute force variables
code += """
entero pos1;
entero pos2;
entero pos3;
entero p1; entero p2; entero p3;

entero i;
entero c;

entero m2; entero m3;
entero pder; entero pmed;
entero aux;

// Muescas: R2(I) Q=16, R3(III) V=21
m2 = 16;
m3 = 21;
"""

code += """
pos1 = 0;
mientras(pos1 < 26) {
    pos2 = 0;
    mientras(pos2 < 26) {
        pos3 = 0;
        mientras(pos3 < 26) {
            
            // Inicializar posiciones de rotores
            p1 = pos1; p2 = pos2; p3 = pos3;
            
            // Descifrar el mensaje
            i = 0;
            mientras(i < 30) {
                // Girar rotores (odometro)
                pder = 0;
                pmed = 0;
                si (p2 == m2) { pmed = 1; }
                si (p3 == m3) { pder = 1; }
                
                si (pmed == 1) {
                    p2 = p2 + 1;
                    si (p2 == 26) { p2 = 0; }
                    p1 = p1 + 1;
                    si (p1 == 26) { p1 = 0; }
                } sino {
                    si (pder == 1) {
                        p2 = p2 + 1;
                        si (p2 == 26) { p2 = 0; }
                        // REPLICANDO EL BUG DE PYTHON PARA QUE FUNCIONE:
                        p1 = p1 + 1;
                        si (p1 == 26) { p1 = 0; }
                    }
                }
                
                p3 = p3 + 1;
                si (p3 == 26) { p3 = 0; }
                
                // Pasar la letra
                c = mensaje[i];
                
                // Steckerbrett Entrada
                c = stecker[c];
                
                // Rotor 3 fwd
                c = c + p3; si (c >= 26) { c = c - 26; }
                c = r3f[c];
                c = c - p3; si (c < 0) { c = c + 26; }
                
                // Rotor 2 fwd
                c = c + p2; si (c >= 26) { c = c - 26; }
                c = r2f[c];
                c = c - p2; si (c < 0) { c = c + 26; }
                
                // Rotor 1 fwd
                c = c + p1; si (c >= 26) { c = c - 26; }
                c = r1f[c];
                c = c - p1; si (c < 0) { c = c + 26; }
                
                // Reflector
                c = refb[c];
                
                // Rotor 1 bwd
                c = c + p1; si (c >= 26) { c = c - 26; }
                c = r1b[c];
                c = c - p1; si (c < 0) { c = c + 26; }
                
                // Rotor 2 bwd
                c = c + p2; si (c >= 26) { c = c - 26; }
                c = r2b[c];
                c = c - p2; si (c < 0) { c = c + 26; }
                
                // Rotor 3 bwd
                c = c + p3; si (c >= 26) { c = c - 26; }
                c = r3b[c];
                c = c - p3; si (c < 0) { c = c + 26; }
                
                // Steckerbrett Salida
                c = stecker[c];
                
                texto[i] = c;
                i = i + 1;
            }
            
            // Verificar si las ultimas 11 letras son HEILXHITLER (indices: 7,4,8,11,23,7,8,19,11,4,17)
            // pos 19 a 29
            aux = 1;
            si (texto[19] != 7) { aux = 0; }
            si (texto[20] != 4) { aux = 0; }
            si (texto[21] != 8) { aux = 0; }
            si (texto[22] != 11) { aux = 0; }
            si (texto[23] != 23) { aux = 0; }
            si (texto[24] != 7) { aux = 0; }
            si (texto[25] != 8) { aux = 0; }
            si (texto[26] != 19) { aux = 0; }
            si (texto[27] != 11) { aux = 0; }
            si (texto[28] != 4) { aux = 0; }
            si (texto[29] != 17) { aux = 0; }
            
            si (aux == 1) {
                imprimir("¡LA MAQUINA BOMBE HA ROTO LA CLAVE DE ENIGMA!");
                imprimir("Rotacion Inicial Encontrada: ");
                imprimir(pos1);
                imprimir(pos2);
                imprimir(pos3);
                exito = 1;
                // Forzar salida
                pos1 = 26; pos2 = 26; pos3 = 26;
            }
            
            pos3 = pos3 + 1;
        }
        pos2 = pos2 + 1;
    }
    pos1 = pos1 + 1;
}

si (exito == 0) {
    imprimir("FALLO CRITICO: No se encontro el mensaje.");
}
"""

with open("test/enigma_real.to", "w") as f:
    f.write(code)
print("Generado test/enigma_real.to")
