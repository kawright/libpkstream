BUILD_DIRS = build \
	build/obj \
	build/bin \
	build/tests

TEST_BINS = build/tests/test_new_and_del \
	build/tests/test_adv_and_iseos \
	build/tests/test_read

.PHONY: clean tests

tests: $(TEST_BINS)

# T E S T    B I N A R I E S :

build/tests/%: build/obj/%.o build/obj/pkstream.o
	@ echo -n COMPILING TEST $@...
	@ gcc -g -Wall -o $@ $< build/obj/pkstream.o
	@ echo DONE!

# T E S T    O B J E C T    F I L E S :

build/obj/%.o: tests/%.c
	@ echo -n BUILDING $@...
	@ gcc -g -Wall -o $@ -c $<
	@ echo DONE!

# O B J E C T    F I L E S :

build/obj/pkstream.o: src/pkstream.c
	@ echo -n BUILDING pkstream.o...
	@ gcc -g -Wall -o build/obj/pkstream.o -c src/pkstream.c
	@ echo DONE!

clean:
	@ echo -n CLEANING BUILD DIRECTORY...
	@ rm -Rf build
	@ echo DONE!

$(shell mkdir -p $(BUILD_DIRS))