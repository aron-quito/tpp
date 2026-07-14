def girar_python(pos0, pos1, pos2):
    paso_izq = pos1 == 16 # muesca Q
    paso_med = pos2 == 21 # muesca V
    if paso_med:
        pos1 = (pos1 + 1) % 26
        pos0 = (pos0 + 1) % 26
    elif paso_izq:
        pos1 = (pos1 + 1) % 26
        pos0 = (pos0 + 1) % 26
    pos2 = (pos2 + 1) % 26
    return pos0, pos1, pos2

def girar_to(pos0, pos1, pos2):
    pder = (pos2 == 21)
    pmed = (pos1 == 16)
    if pmed:
        pos1 = (pos1 + 1) % 26
        pos0 = (pos0 + 1) % 26
    else:
        if pder:
            pos1 = (pos1 + 1) % 26
    pos2 = (pos2 + 1) % 26
    return pos0, pos1, pos2

p_py = (7, 20, 8)
p_to = (7, 20, 8)

for i in range(30):
    p_py = girar_python(*p_py)
    p_to = girar_to(*p_to)
    if p_py != p_to:
        print(f"Divergence at step {i+1}: Python={p_py}, TO={p_to}")
        break
