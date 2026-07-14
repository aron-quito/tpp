import itertools

ciphertext = "DAIDYUGSKTBQRJUVYWLMFJIWPQRSLV"
target = "HEILXHITLER"
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

rotors = {
    "I": ("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 16),
    "II": ("AJDKSIRUXBLHWTMCQGZNPYFVOE", 4),
    "III": ("BDFHJLCPRTXVZNYEIWGAKMUSQO", 21),
    "IV": ("ESOVPZJAYQUIRHXLNFTGKDCMWB", 9),
    "V": ("VZBRGITYUPSDNHLXAWMJQOFECK", 25)
}

reflector_b = [alphabet.index(c) for c in "YRUHQSLDPXNGOKMIEBFZCWVJAT"]

c_idx = [alphabet.index(c) for c in ciphertext]
t_idx = [alphabet.index(c) for c in target]

for r_order in itertools.permutations(["I", "II", "III"]):
    r1, m1 = rotors[r_order[0]]
    r2, m2 = rotors[r_order[1]]
    r3, m3 = rotors[r_order[2]]
    
    rotor_1_f = [alphabet.index(c) for c in r1]
    rotor_2_f = [alphabet.index(c) for c in r2]
    rotor_3_f = [alphabet.index(c) for c in r3]
    
    rotor_1_b = [0]*26
    rotor_2_b = [0]*26
    rotor_3_b = [0]*26
    for i in range(26):
        rotor_1_b[rotor_1_f[i]] = i
        rotor_2_b[rotor_2_f[i]] = i
        rotor_3_b[rotor_3_f[i]] = i

    for pos1 in range(26):
        for pos2 in range(26):
            for pos3 in range(26):
                p1, p2, p3 = pos1, pos2, pos3
                decrypted = []
                for i in range(30):
                    pder = 1 if p3 == m3 else 0
                    pmed = 1 if p2 == m2 else 0
                    
                    if pmed == 1:
                        p2 = (p2 + 1) % 26
                        p1 = (p1 + 1) % 26
                    else:
                        if pder == 1:
                            p2 = (p2 + 1) % 26
                    p3 = (p3 + 1) % 26
                    
                    c = c_idx[i]
                    c = (c + p3) % 26; c = rotor_3_f[c]; c = (c - p3) % 26
                    c = (c + p2) % 26; c = rotor_2_f[c]; c = (c - p2) % 26
                    c = (c + p1) % 26; c = rotor_1_f[c]; c = (c - p1) % 26
                    
                    c = reflector_b[c]
                    
                    c = (c + p1) % 26; c = rotor_1_b[c]; c = (c - p1) % 26
                    c = (c + p2) % 26; c = rotor_2_b[c]; c = (c - p2) % 26
                    c = (c + p3) % 26; c = rotor_3_b[c]; c = (c - p3) % 26
                    
                    decrypted.append(c)
                    
                if decrypted[-11:] == t_idx:
                    print(f"FOUND: Rotors={r_order} pos={pos1},{pos2},{pos3}")
                    exit(0)
print("Not found")
