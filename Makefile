
test: test/test.c src/rot13.c
	$(CC) -std=c99 $^ -o test/test -Isrc
	./test/test

.PHONY: test
