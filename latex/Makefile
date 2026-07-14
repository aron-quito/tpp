## Makefile para compilar la documentación LaTeX del compilador TPP
## Autor: Cachicatari Quito Aron Rene

MAIN     = main
TEXBIN   = /usr/local/texlive/2026basic/bin/universal-darwin
LATEX    = $(TEXBIN)/pdflatex
TLMGR    = $(TEXBIN)/tlmgr
BUILD    = build
PDF      = $(BUILD)/$(MAIN).pdf

# Opciones de pdflatex
LATEX_FLAGS = -interaction=nonstopmode -output-directory=$(BUILD)

# Paquetes necesarios (longtable viene en 'tools')
PACKAGES = tcolorbox pgf xcolor listings fancyhdr titlesec \
           booktabs tools enumitem mdframed float setspace \
           environ trimspaces

.PHONY: all clean view setup

## setup: Instalar paquetes LaTeX necesarios (requiere contraseña admin)
setup:
	sudo $(TLMGR) update --self
	sudo $(TLMGR) install --no-warnings $(PACKAGES) || true
	@echo "Paquetes instalados. Ejecuta: make compile"

## compile: Compilar directamente sin setup
compile: $(PDF)

all: $(PDF)

$(BUILD):
	mkdir -p $(BUILD) $(BUILD)/chapters

$(PDF): $(BUILD) $(MAIN).tex chapters/*.tex
	$(LATEX) $(LATEX_FLAGS) $(MAIN).tex || true
	$(LATEX) $(LATEX_FLAGS) $(MAIN).tex || true
	@echo ""
	@echo "=========================================="
	@echo "  PDF generado: $(PDF)"
	@echo "=========================================="

view: $(PDF)
	open $(PDF)

clean:
	rm -rf $(BUILD)
	@echo "Directorio build limpiado."
