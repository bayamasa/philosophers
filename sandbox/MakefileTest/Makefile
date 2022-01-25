# test

# all: echo_test 
# 	echo $@

echo_test : 
	echo echo_test


foo: b/bar
	gcc foo.c -o foo

all: b/bar
	gcc foo.c -o foo

clean:
	gcc foo.c -o foo

hello: hoge fuga
	@echo $^

hoge: piyo
	@echo hogehoge
fuga:
	@echo fugafuga

piyo:
	@echo piyopiyo

.PHONY: clean 
