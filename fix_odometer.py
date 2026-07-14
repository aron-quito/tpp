with open("generate_enigma_to.py", "r") as f:
    text = f.read()

# Replace the broken odometer block
old_odometer = """
                // Girar rotores (odometro)
                pizq = 0;
                pmed = 0;
                si (p2 == m2) { pmed = 1; }
                si (p1 == m1) { pizq = 1; }
                
                si (pmed == 1) {
                    p2 = p2 + 1;
                    si (p2 == 26) { p2 = 0; }
                    p1 = p1 + 1;
                    si (p1 == 26) { p1 = 0; }
                } sino {
                    si (pizq == 1) {
                        p2 = p2 + 1;
                        si (p2 == 26) { p2 = 0; }
                    }
                }
                
                p3 = p3 + 1;
                si (p3 == 26) { p3 = 0; }
"""

new_odometer = """
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
                    }
                }
                
                p3 = p3 + 1;
                si (p3 == 26) { p3 = 0; }
"""

text = text.replace("entero pizq; entero pmed;", "entero pder; entero pmed;")
text = text.replace("entero m1; entero m2;", "entero m2; entero m3;")
text = text.replace("m1 = 16;\nm2 = 4;", "m2 = 4;\nm3 = 21;")
text = text.replace(old_odometer, new_odometer)

with open("generate_enigma_to.py", "w") as f:
    f.write(text)
