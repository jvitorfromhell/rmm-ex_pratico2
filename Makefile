compila:
	g++ -o comp comp_jpeg.cpp cod_pred.cpp -std=c++11 -w
	g++ -o descomp comp_jpeg.cpp dec_pred.cpp -std=c++11 -w

comprime:
	./comp

descomprime:
	./descomp

limpa:
	rm comp
	rm descomp
	rm lena.jpg
	rm residuo.raw