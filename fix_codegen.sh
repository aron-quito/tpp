sed -i '' -e '189s/.*/            generando_funciones = 0;\n            fprintf(out, "    .globl main\\n");/' codegen.c
sed -i '' -e '235s/.*/            int prev_gen = generando_funciones;\n            generando_funciones = 0;\n            generar_nodo(nodo->der, out);\n            generando_funciones = prev_gen;/' codegen.c
