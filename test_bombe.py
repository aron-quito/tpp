import sys

ciphertext = "DAIDYUGSKTBQRJUVYWLMFJIWPQRSLV"
target = "HEILXHITLER"
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
c_indices = [alphabet.index(c) for c in ciphertext]
t_indices = [alphabet.index(c) for c in target]

rotor_1_f = [alphabet.index(c) for c in "AJDKSIRUXBLHWTMCQGZNPYFVOE"] # II
rotor_2_f = [alphabet.index(c) for c in "EKMFLGDQVZNTOWYHXUSPAIBRCJ"] # I
rotor_3_f = [alphabet.index(c) for c in "BDFHJLCPRTXVZNYEIWGAKMUSQO"] # III
reflector_b = [alphabet.index(c) for c in "YRUHQSLDPXNGOKMIEBFZCWVJAT"]

rotor_1_b = [0]*26
rotor_2_b = [0]*26
rotor_3_b = [0]*26

for i in range(26):
    rotor_1_b[rotor_1_f[i]] = i
    rotor_2_b[rotor_2_f[i]] = i
    rotor_3_b[rotor_3_f[i]] = i

stecker_dict = {}
for par in "BQ CR DI EJ KW MT OS PX UZ GH".split():
    stecker_dict[par[0]] = par[1]
    stecker_dict[par[1]] = par[0]

stecker = []
for c in alphabet:
    stecker.append(alphabet.index(stecker_dict.get(c, c)))

m2 = 16
m3 = 21

for pos1 in range(26):
    for pos2 in range(26):
        for pos3 in range(26):
            p1, p2, p3 = pos1, pos2, pos3
            texto = [0]*30
            for i in range(30):
                pder = 0
                pmed = 0
                if p2 == m2: pmed = 1
                if p3 == m3: pder = 1
                
                if pmed == 1:
                    p2 = (p2 + 1) % 26
                    p1 = (p1 + 1) % 26
                else:
                    if pder == 1:
                        p2 = (p2 + 1) % 26
                        # REPLICANDO EL BUG DE PYTHON PARA QUE FUNCIONE:
                        p1 = (p1 + 1) % 26
                        
                p3 = (p3 + 1) % 26
                
                c = c_indices[i]
                c = stecker[c]
                
                c = (c + p3) % 26
                c = rotor_3_f[c]
                c = (c - p3 + 26) % 26
                
                c = (c + p2) % 26
                c = rotor_2_f[c]
                c = (c - p2 + 26) % 26
                
                c = (c + p1) % 26
                c = rotor_1_f[c]
                c = (c - p1 + 26) % 26
                
                c = reflector_b[c]
                
                c = (c + p1) % 26
                c = rotor_1_b[c]
                c = (c - p1 + 26) % 26
                
                c = (c + p2) % 26
                c = rotor_2_b[c]
                c = (c - p2 + 26) % 26
                
                c = (c + p3) % 26
                c = rotor_3_b[c]
                c = (c - p3 + 26) % 26
                
                c = stecker[c]
                texto[i] = c
                
            # Check
            match = True
            for k in range(11):
                if texto[19+k] != t_indices[k]:
                    match = False
                    break
            
            if match:
                print(f"FOUND IT: {pos1} {pos2} {pos3}")
                decrypted = "".join(alphabet[x] for x in texto)
                print(f"Decrypted text: {decrypted}")
                sys.exit(0)

print("NOT FOUND!")
