all: gadt-haskell gadt-ocaml

gadt-haskell: src/gadt.hs
	ghc src/gadt.hs -o gadt-haskell

gadt-ocaml: src/gadt.ml
	ocamlc src/gadt.ml -o gadt-ocaml

.PHONY: clean

clean:
	rm -rf src/*.o src/*.hi src/*cm[io] gadt-haskell gadt-ocaml
