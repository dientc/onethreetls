# ref: https://www.bojankomazec.com/2011/10/how-to-use-nmake-and-makefile.html
EXE_NAME = main.exe
OPTIONS = /Zi
INCLUDE_DIR = D:\Tls13\3rd_library\x64\Release\include
CRYPTO_LIB = D:\Tls13\3rd_library\x64\Release\lib\libcrypto.lib 

DIR_SRC = .\

SRC_FILES= \
  $(DIR_SRC)\crypto\tls13_hash.c \
  $(DIR_SRC)\net\tls13_net.c \
  $(DIR_SRC)\main.c

all:
    cl $(OPTIONS) -o $(EXE_NAME) $(SRC_FILES) /I $(INCLUDE_DIR) $(CRYPTO_LIB)

clean:
    del *.obj *.ilk *.exe *.pdb