GCC=g++
STD=-std=c++14
OUT=test

SOURCES= \
	src/main.cpp \
	src/Block.cpp \
	src/Transaction.cpp \
	src/Config.cpp \
	src/Sha256.cpp \
	src/Chain.cpp



all: prog


prog :
	@$(GCC) $(STD) $(SOURCES) -lboost_system -lboost_serialization -o $(OUT)
