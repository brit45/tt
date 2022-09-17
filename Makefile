GCC=g++
STD=-std=c++20
OUT=test

SOURCES= \
	src/main.cpp \
	src/Block.cpp \
	src/Transaction.cpp \
	src/Sha256.cpp \
	src/Chain.cpp



all: prog


prog :
	@$(GCC) $(STD) $(SOURCES) -lboost_system -lboost_serialization -o $(OUT)
