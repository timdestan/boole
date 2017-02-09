all: gadt-haskell

gadt-haskell: src/gadt.hs
	ghc src/gadt.hs -o gadt-haskell

.PHONY: clean

clean:
	rm -rf src/*.o src/*.hi gadt-haskell
